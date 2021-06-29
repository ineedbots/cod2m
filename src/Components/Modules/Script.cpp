#include "STDInclude.hpp"
#include "Script.hpp"

namespace Components
{
	Game::xmethod_t* Script::Player_GetMethod_Hook(const char** name)
	{
		return Game::Player_GetMethod(name);
	}

	Game::xfunction_t* Script::Scr_GetFunction_Hook(const char** name, int* isDev)
	{
		return Game::Scr_GetFunction(name, isDev);
	}

	Script::Script()
	{
		Utils::Hook(0x46E9CB, Player_GetMethod_Hook, HOOK_CALL).install()->quick();
		Utils::Hook(0x46E7BF, Scr_GetFunction_Hook, HOOK_CALL).install()->quick();
	}

	Script::~Script()
	{
	}
}
