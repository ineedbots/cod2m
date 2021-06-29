#pragma once

namespace Components
{
	class Script : public Component
	{
	public:
		Script();
		~Script();
	private:
		static Game::xmethod_t* Player_GetMethod_Hook(const char**);
		static Game::xfunction_t* Scr_GetFunction_Hook(const char**, int*);
	};
}
