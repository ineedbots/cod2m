#include "STDInclude.hpp"
#include "Script.hpp"

namespace Components
{
	std::unordered_map<std::string, Game::scr_function_t> Script::CustomScrFunctions;
	std::unordered_map<std::string, Game::scr_method_t> Script::CustomScrMethods;
	std::vector<unsigned int> Script::CustomScrHandles;

	void Script::AddFunction(const char* name, Game::xfunction_t func, int type)
	{
		Game::scr_function_t toAdd;
		toAdd.call = func;
		toAdd.developer = type;

		CustomScrFunctions.insert_or_assign(Utils::String::ToLower(name), toAdd);
	}

	void Script::AddMethod(const char* name, Game::xmethod_t func, int type)
	{
		Game::scr_method_t toAdd;
		toAdd.call = func;
		toAdd.developer = type;

		CustomScrMethods.insert_or_assign(Utils::String::ToLower(name), toAdd);
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

		*isDev = got->second.developer;
		return got->second.call;
	}

	void Script::GScr_LoadGameTypeScript_Hook()
	{
		CustomScrHandles.clear();

		Game::FS_ForEachFile("scripts", "gsc", [](char* filename)
		{
			std::string file = filename;
			std::string label = "init";

			file = "scripts/" + file;

			if (Utils::String::EndsWith(file, ".gsc"))
				file = file.substr(0, file.size() - 4);

			Game::Com_Printf("Loading script %s.gsc...\n", file.data());

			if (!Game::Scr_LoadScript(file.data()))
			{
				Game::Com_Printf("Script %s encountered an error while loading. (doesn't exist?)", file.data());
				return;
			}

			Game::Com_Printf("Script %s.gsc loaded successfully.\n", file.data());
			Game::Com_Printf("Finding script handle %s::%s...\n", file.data(), label.data());

			unsigned int handle = Game::Scr_GetFunctionHandle(file.data(), label.data());
			if (!handle)
			{
				Game::Com_Printf("Script handle %s::%s couldn't be loaded. (file with no entry point?)\n", file.data(), label.data());
				return;
			}
			
			CustomScrHandles.push_back(handle);
			Game::Com_Printf("Script handle %s::%s loaded successfully.\n", file.data(), label.data());
		});

		Game::GScr_LoadGameTypeScript();
	}

	void Script::G_LoadStructs_Hook()
	{
		for (auto handle : CustomScrHandles)
		{
			Game::RemoveRefToObject(Game::Scr_ExecThread(handle, 0));
		}

		Game::G_LoadStructs();
	}

	Script::Script()
	{
		// custom gsc calls
		Utils::Hook(0x46E9CB, Player_GetMethod_Hook, HOOK_CALL).install()->quick();
		Utils::Hook(0x46E7BF, Scr_GetFunction_Hook, HOOK_CALL).install()->quick();

		// load custom scripts
		Utils::Hook(0x4FC75F, G_LoadStructs_Hook, HOOK_CALL).install()->quick();
		Utils::Hook(0x5043FA, GScr_LoadGameTypeScript_Hook, HOOK_CALL).install()->quick();
	}

	Script::~Script()
	{
		CustomScrFunctions.clear();
		CustomScrMethods.clear();
		CustomScrHandles.clear();
	}
}
