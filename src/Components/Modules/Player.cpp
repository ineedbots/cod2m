#include "STDInclude.hpp"
#include "Player.hpp"
#include "Scheduler.hpp"

namespace Components
{
	Game::cvar_t* Player::g_playerEjection;
	Game::cvar_t* Player::g_playerCollision;

	int Player::StuckInClient_Func(Game::gentity_t* ent)
	{
		if (!g_playerEjection->current.boolean)
			return 0;

		return Game::StuckInClient(ent);
	}

	__declspec(naked) void Player::StuckInClient_Stub()
	{
		__asm
		{
			push eax;
			call StuckInClient_Func;
			add esp, 4;
			retn;
		}
	}

	void Player::CM_Trace_Func(float* a1, float* a2, float* a3, int a4, float* a5, int a6, int a7)
	{
		if (g_playerCollision->current.boolean)
			Game::CM_Trace(a1, a2, a3, a4, a5, a6, a7);
	}

	__declspec(naked) void Player::CM_Trace_Stub()
	{
		__asm
		{
			push ecx;
			push edx;
			push eax;
			call CM_Trace_Func;
			add esp, 0xC;

			push 0x41D93E;
			retn;
		}
	}

	Player::Player()
	{
		Scheduler::OnReady([]()
		{
			g_playerEjection = Game::Dvar_RegisterBool("g_playerEjection", true, Game::CVAR_FLAG_ARCHIVE);
			g_playerCollision = Game::Dvar_RegisterBool("g_playerCollision", true, Game::CVAR_FLAG_ARCHIVE);
		});

		Utils::Hook(0x5011D3, StuckInClient_Stub, HOOK_CALL).install()->quick();

		Utils::Hook(0x41D939, CM_Trace_Stub, HOOK_JUMP).install()->quick();
	}

	Player::~Player()
	{
	}
}
