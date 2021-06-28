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
	};
}
