#include "STDInclude.hpp"

#include "Modules/Bots.hpp"
#include "Modules/Flags.hpp"
#include "Modules/HelloWorld.hpp"
#include "Modules/Logger.hpp"
#include "Modules/Script.hpp"
#include "Modules/Player.hpp"
#include "Modules/Scheduler.hpp"

namespace Components
{
	bool Loader::Pregame = true;
	bool Loader::Postgame = false;
	bool Loader::Uninitializing = false;
	std::vector<Component*> Loader::Components;

	bool Loader::IsPregame()
	{
		return Loader::Pregame;
	}

	bool Loader::IsPostgame()
	{
		return Loader::Postgame;
	}

	bool Loader::IsUninitializing()
	{
		return Loader::Uninitializing;
	}

	void Loader::Initialize(GAMEEXE GameType)
	{
		Loader::Pregame = true;
		Loader::Postgame = false;
		Loader::Uninitializing = false;
		Utils::Memory::GetAllocator()->clear();

		Game::Init(GameType);
		Loader::Register(new Flags());
		Loader::Register(new HelloWorld());
		Loader::Register(new Logger());
		Loader::Register(new Bots());
		Loader::Register(new Script());
		Loader::Register(new Player());
		Loader::Register(new Scheduler());

		Loader::Pregame = false;
	}

	void Loader::Uninitialize()
	{
		Loader::Uninitializing = true;
		Loader::PreDestroyNoPostGame();

		std::reverse(Loader::Components.begin(), Loader::Components.end());
		for (auto component : Loader::Components)
		{
#ifdef DEBUG
			if (!Loader::IsPerformingUnitTests())
			{
				Logger::Print("Unregistering component: %s\n", component->getName().data());
			}
#endif
			delete component;
		}

		Loader::Components.clear();
		Utils::Memory::GetAllocator()->clear();
		Loader::Uninitializing = false;
	}

	void Loader::PreDestroy()
	{
		if (!Loader::Postgame)
		{
			Loader::Postgame = true;

			auto components = Loader::Components;

			std::reverse(components.begin(), components.end());
			for (auto component : components)
			{
				component->preDestroy();
			}
		}
	}

	void Loader::PreDestroyNoPostGame()
	{
		if (!Loader::Postgame)
		{
			auto components = Loader::Components;

			std::reverse(components.begin(), components.end());
			for (auto component : components)
			{
				component->preDestroy();
			}

			Loader::Postgame = true;
		}
	}

	bool Loader::PerformUnitTests()
	{
		bool result = true;

		Logger::Print("Performing unit tests for components:\n");

		for (auto component : Loader::Components)
		{
#if defined(DEBUG) || defined(FORCE_UNIT_TESTS)
			Logger::Print("Testing '%s'...\n", component->getName().data());
#endif
			auto startTime = std::chrono::high_resolution_clock::now();
			bool testRes = component->unitTest();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count();
			Logger::Print("Test done (%llims): %s\n\n", duration, (testRes ? "Success" : "Error"));
			result &= testRes;
		}

		return result;
	}

	bool Loader::IsPerformingUnitTests()
	{
#if defined(DEBUG) || defined(FORCE_UNIT_TESTS)
		return Flags::HasFlag("tests");
#else
		return false;
#endif
	}

	void Loader::Register(Component* component)
	{
		if (component)
		{
#if defined(DEBUG) || defined(FORCE_UNIT_TESTS)
			if (!Loader::IsPerformingUnitTests())
			{
				Logger::Print("Component registered: %s\n", component->getName().data());
			}
#endif
			Loader::Components.push_back(component);
		}
	}
}
