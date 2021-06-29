#include "STDInclude.hpp"
#include "Script.hpp"

namespace Components
{
	std::unordered_map<std::string, Game::scr_function_t> Script::CustomScrFunctions;
	std::unordered_map<std::string, Game::scr_method_t> Script::CustomScrMethods;

	void Script::AddFunction(const char* name, Game::xfunction_t func, int type)
	{
		Game::scr_function_t toAdd;
		toAdd.call = func;
		toAdd.name = name;
		toAdd.developer = type;

		CustomScrFunctions.insert_or_assign(name, toAdd);
	}

	void Script::AddMethod(const char* name, Game::xmethod_t func, int type)
	{
		Game::scr_method_t toAdd;
		toAdd.call = func;
		toAdd.name = name;
		toAdd.developer = type;

		CustomScrMethods.insert_or_assign(name, toAdd);
	}

	Game::xmethod_t Script::Player_GetMethod_Hook(const char** name)
	{
		auto got = CustomScrMethods.find(*name);

		if (got == CustomScrMethods.end())
			return Game::Player_GetMethod(name);

		return got->second.call;
	}

	Game::xfunction_t Script::Scr_GetFunction_Hook(const char** name, int* isDev)
	{
		auto got = CustomScrFunctions.find(*name);

		if (got == CustomScrFunctions.end())
			return Game::Scr_GetFunction(name, isDev);

		return got->second.call;
	}

	Script::Script()
	{
		Utils::Hook(0x46E9CB, Player_GetMethod_Hook, HOOK_CALL).install()->quick();
		Utils::Hook(0x46E7BF, Scr_GetFunction_Hook, HOOK_CALL).install()->quick();
	}

	Script::~Script()
	{
		CustomScrFunctions.clear();
		CustomScrMethods.clear();
	}
}
