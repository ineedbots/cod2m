#include "STDInclude.hpp"
#include "Bots.hpp"

namespace Components
{
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

		if (cl->state < Game::CS_ACTIVE)
		{
			Game::SV_DropClient(cl, "EXE_DISCONNECTED");
			cl->state = Game::CS_FREE;
			return;
		}

		Game::usercmd_t cmd = {};
		cmd.serverTime = Game::svs->time;

		cl->deltaMessage = cl->netchan.outgoingSequence - 1;
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

	Bots::Bots()
	{
		// intercept the sprintf when creating the bot connect string 
		Utils::Hook(0x45655B, BuildConnectString, HOOK_CALL).install()->quick();

		// hook bot movement
		Utils::Hook(0x45C210, SV_BotUserMove_Stub, HOOK_JUMP).install()->quick();

		// stop the ping spam
		Utils::Hook::Nop(0x45BF59, 5);
	}

	Bots::~Bots()
	{
	}
}
