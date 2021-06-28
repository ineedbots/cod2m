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

	Bots::Bots()
	{
		// intercept the sprintf when creating the bot connect string 
		Utils::Hook(0x45655B, BuildConnectString, HOOK_CALL).install()->quick();
	}

	Bots::~Bots()
	{
	}
}
