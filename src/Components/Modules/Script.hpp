#pragma once

namespace Components
{
	class Script : public Component
	{
	public:
		static void AddFunction(const char*, Game::xfunction_t, int = 0);
		static void AddMethod(const char*, Game::xmethod_t, int = 0);
		Script();
		~Script();
	private:
		static std::unordered_map<std::string, Game::scr_function_t> CustomScrFunctions;
		static std::unordered_map<std::string, Game::scr_method_t> CustomScrMethods;
		static std::vector<unsigned int> CustomScrHandles;

		static Game::xmethod_t Player_GetMethod_Hook(const char**);
		static Game::xfunction_t Scr_GetFunction_Hook(const char**, int*);

		static void GScr_LoadGameTypeScript_Hook();
		static void G_LoadStructs_Hook();
	};
}
