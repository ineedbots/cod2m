#pragma once
#define MAX_G_BOTAI_ENTRIES 64

namespace Components
{
	class Bots : public Component
	{
	public:
		Bots();
		~Bots();
	private:
		typedef enum button_mask : unsigned int
		{
			KEY_FIRE = 1 << 0,
			KEY_SPRINT = 1 << 1,
			KEY_MELEE = 1 << 2,
			KEY_USE = 1 << 3,
			KEY_RELOAD = 1 << 4,
			KEY_USERELOAD = 1 << 5,
			KEY_LEANLEFT = 1 << 6,
			KEY_LEANRIGHT = 1 << 7,
			KEY_PRONE = 1 << 8,
			KEY_CROUCH = 1 << 9,
			KEY_GOSTAND = 1 << 10,
			KEY_ADSMODE = 1 << 11,
			KEY_TEMP = 1 << 12,
			KEY_HOLDBREATH = 1 << 13,
			KEY_FRAG = 1 << 14,
			KEY_SMOKE = 1 << 15,
			KEY_UNK = 1 << 16,
			KEY_UNK2 = 1 << 17,
			KEY_NIGHTVISION = 1 << 18,
			KEY_ADS = 1 << 19,
			KEY_UNK3 = 1 << 20,
			KEY_UNK4 = 1 << 21,
			KEY_MENU = 1 << 22,
			KEY_UNK5 = 1 << 23,
			KEY_UNK6 = 1 << 24,
			KEY_UNK7 = 1 << 25,
			KEY_UNK8 = 1 << 25,
			KEY_UNK9 = 1 << 26,
			KEY_UNK10 = 1 << 27,
			KEY_UNK11 = 1 << 28,
			KEY_UNK12 = 1 << 29,
			KEY_UNK13 = 1 << 30,
			KEY_UNK14 = 2147483648
		} button_mask;

		struct BotAction_t
		{
			const char* action;
			unsigned int key;
		};

		struct botMovements
		{
			unsigned int buttons;
			int ping;
			char weapon;
			char forward;
			char right;
		};

		static botMovements g_botai[];
		static const BotAction_t bot_actions[];

		static std::vector<std::string> bot_names;

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
