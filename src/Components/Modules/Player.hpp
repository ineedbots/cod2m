#pragma once

namespace Components
{
	class Player : public Component
	{
	public:
		Player();
		~Player();

		static Game::cvar_t* g_playerEjection;
		static Game::cvar_t* g_playerCollision;
	private:
		static int StuckInClient_Func(Game::gentity_t* ent);
		static void StuckInClient_Stub();
		static void CM_Trace_Func(float*, float*, float*, int, float*, int, int);
		static void CM_Trace_Stub();
	};
}
