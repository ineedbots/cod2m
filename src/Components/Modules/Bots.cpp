#include "STDInclude.hpp"
#include "Bots.hpp"
#include "Script.hpp"

namespace Components
{
	Bots::botMovements Bots::g_botai[MAX_G_BOTAI_ENTRIES];

	const Bots::BotAction_t Bots::bot_actions[] =
	{
		{ "fire", KEY_FIRE },
		{ "attack", KEY_FIRE },
		{ "melee", KEY_MELEE },
		{ "activate", KEY_USE },
		{ "use", KEY_USE | KEY_USERELOAD },
		{ "usereload", KEY_USERELOAD },
		{ "reload", KEY_RELOAD },
		{ "leanleft", KEY_LEANLEFT },
		{ "leanright", KEY_LEANRIGHT },
		{ "goprone", KEY_PRONE },
		{ "gocrouch", KEY_CROUCH },
		{ "gostand", KEY_GOSTAND },
		{ "ads", KEY_ADSMODE | KEY_ADS },
		{ "toggleads_throw", KEY_ADSMODE },
		{ "speed_throw", KEY_ADS },
		{ "holdbreath", KEY_HOLDBREATH },
		{ "frag", KEY_FRAG },
		{ "smoke", KEY_SMOKE },
		{ "unk", KEY_UNK },
		{ "unk2", KEY_UNK2 },
		{ "unk3", KEY_UNK3 },
		{ "unk4", KEY_UNK4 },
		{ "menu", KEY_MENU },
		{ "unk5", KEY_UNK5 },
		{ "unk6", KEY_UNK6 },
		{ "unk7", KEY_UNK7 },
		{ "unk8", KEY_UNK8 },
		{ "unk9", KEY_UNK9 },
		{ "unk10", KEY_UNK10 },
		{ "unk11", KEY_UNK11 },
		{ "unk12", KEY_UNK12 },
		{ "unk13", KEY_UNK13 },
		{ "unk14", KEY_UNK14 },
		{ "unk15", KEY_UNK15 },
		{ "unk16", KEY_UNK16 },
		{ "unk17", KEY_UNK17 }
	};

	std::vector<std::string> Bots::bot_names;

	const char* Bots::ConnectString = "connect \"\\cg_predictItems\\1\\cl_punkbuster\\0\\cl_anonymous\\0\\color\\4\\head\\default\\model\\multi\\snaps\\20\\"
    "rate\\5000\\name\\%s\\protocol\\%d\"";

	int Bots::BuildConnectString(char* buffer, const char*, [[maybe_unused]] int num, int protocol)
	{
		const char* botName = Utils::String::VA("bota%d", num);
		return sprintf(buffer, ConnectString, botName, protocol);
	}

	void Bots::SV_BotUserMove_Func(Game::client_t* cl)
	{
		int cl_num = cl - Game::svs->clients;

		if (cl->gentity == nullptr)
		{
			return;
		}

		Game::usercmd_t cmd = {};
		cmd.serverTime = Game::svs->time;
		cmd.weapon = g_botai[cl_num].weapon;
		cmd.forwardmove = g_botai[cl_num].forward;
		cmd.rightmove = g_botai[cl_num].right;
		cmd.buttons = g_botai[cl_num].buttons;

		cl->deltaMessage = cl->netchan.outgoingSequence - 1;
		cl->ping = g_botai[cl_num].ping;
		Game::SV_ClientThink(&cmd, cl);
	}

	__declspec(naked) void Bots::SV_BotUserMove_Stub()
	{
		__asm
		{
			push esi;
			call SV_BotUserMove_Func;
			add esp, 4;
			retn;
		}
	}

	void Bots::G_SelectWeaponIndex_Func(int wpIdx, int clNum)
	{
		g_botai[clNum].weapon = static_cast<char>(wpIdx);

		Game::G_SelectWeaponIndex(wpIdx, clNum);
	}

	__declspec(naked) void Bots::G_SelectWeaponIndex_Stub()
	{
		__asm
		{
			push esi;
			push eax;
			call G_SelectWeaponIndex_Func;
			add esp, 8;
			retn;
		}
	}

	void __cdecl Bots::PlayerCmd_setSpawnWeapon_Func(Game::gentity_t* ent, int wpIdx)
	{
		g_botai[ent->s.number].weapon = static_cast<char>(wpIdx);
	}

	__declspec(naked) void Bots::PlayerCmd_setSpawnWeapon_Stub()
	{
		__asm
		{
			push edx;
			push esi;
			call PlayerCmd_setSpawnWeapon_Func;
			add esp, 4;
			pop edx; // __cdecl reqires edx be caller saved

			// go back
			mov eax, [esi + 0x158];
			push 0x52B16C;
			retn;
		}
	}

	Bots::Bots()
	{
		// init the bot commands
		for (int i = 0; i < std::extent_v<decltype(g_botai)>; i++)
		{
			g_botai[i] = { 0 };
			g_botai[i].weapon = 1;
		}

		// intercept the sprintf when creating the bot connect string 
		Utils::Hook(0x45655B, BuildConnectString, HOOK_CALL).install()->quick();

		// hook bot movement
		Utils::Hook(0x45C210, SV_BotUserMove_Stub, HOOK_JUMP).install()->quick();

		// stop the ping spam
		Utils::Hook::Nop(0x45BF59, 5);


		// fix bots switching weapons
		Utils::Hook(0x52A1C2, G_SelectWeaponIndex_Stub, HOOK_CALL).install()->quick();
		Utils::Hook(0x51E2DC, G_SelectWeaponIndex_Stub, HOOK_CALL).install()->quick();
		Utils::Hook(0x501E0D, G_SelectWeaponIndex_Stub, HOOK_CALL).install()->quick();
		Utils::Hook(0x52B166, PlayerCmd_setSpawnWeapon_Stub, HOOK_JUMP).install()->quick();


		Script::AddMethod("botaction", [](Game::scr_entref_t ent)
		{
			const char* action = Game::Scr_GetString(0);

			for (size_t i = 0; i < std::extent_v<decltype(bot_actions)>; ++i)
			{
				if (strcmp(&action[1], bot_actions[i].action))
				{
					continue;
				}

				if (action[0] == '+')
				{
					g_botai[ent.entnum].buttons |= bot_actions[i].key;
				}
				else
				{
					g_botai[ent.entnum].buttons &= ~(bot_actions[i].key);
				}

				return;
			}
		});

		Script::AddMethod("botmovement", [](Game::scr_entref_t ent)
		{
			int forward = Game::Scr_GetInt(0);
			int right = Game::Scr_GetInt(1);

			forward = std::clamp<int>(forward, std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
			right = std::clamp<int>(right, std::numeric_limits<char>::min(), std::numeric_limits<char>::max());

			g_botai[ent.entnum].forward = static_cast<char>(forward);
			g_botai[ent.entnum].right = static_cast<char>(right);
		});

		Script::AddMethod("botstop", [](Game::scr_entref_t ent)
		{
			g_botai[ent.entnum].buttons = 0;
			g_botai[ent.entnum].forward = 0;
			g_botai[ent.entnum].right = 0;
			g_botai[ent.entnum].weapon = 1;
		});
	}

	Bots::~Bots()
	{
	}
}
