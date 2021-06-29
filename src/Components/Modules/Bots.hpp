#pragma once

namespace Components
{
	class Bots : public Component
	{
	public:
		Bots();
		~Bots();
	private:
		static const char* ConnectString;

		static int BuildConnectString(char*, const char*, int, int);
		static void SV_BotUserMove_Func(Game::client_t*);
		static void SV_BotUserMove_Stub();

		static void G_SelectWeaponIndex_Func(int, int);
		static void G_SelectWeaponIndex_Stub();

		static void PlayerCmd_setSpawnWeapon_Func(Game::gentity_t*, int);
		static void PlayerCmd_setSpawnWeapon_Stub();
	};
}
