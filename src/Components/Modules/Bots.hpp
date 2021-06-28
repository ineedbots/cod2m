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
	};
}
