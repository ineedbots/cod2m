#include "STDInclude.hpp"
#include "Scheduler.hpp"

namespace Components
{
	bool Scheduler::AsyncTerminate;
	std::thread Scheduler::AsyncThread;

	bool Scheduler::ReadyPassed = false;
	Utils::Signal<Scheduler::Callback> Scheduler::ReadySignal;
	Utils::Signal<Scheduler::Callback> Scheduler::ShutdownSignal;

	Utils::Signal<Scheduler::Callback> Scheduler::FrameSignal;
	Utils::Signal<Scheduler::Callback> Scheduler::FrameOnceSignal;
	std::vector<Scheduler::DelayedSlot> Scheduler::DelayedSlots;

	Utils::Signal<Scheduler::Callback> Scheduler::AsyncFrameSignal;
	Utils::Signal<Scheduler::Callback> Scheduler::AsyncFrameOnceSignal;

	void Scheduler::Once(Utils::Slot<Scheduler::Callback> callback, bool clientOnly)
	{
		if (clientOnly && Game::IsDedicated()) return;
		Scheduler::FrameOnceSignal.connect(callback);
	}

	void Scheduler::OnShutdown(Utils::Slot<Scheduler::Callback> callback)
	{
		Scheduler::ShutdownSignal.connect(callback);
	}

	void Scheduler::OnFrame(Utils::Slot<Scheduler::Callback> callback, bool clientOnly)
	{
		if (clientOnly && Game::IsDedicated()) return;
		Scheduler::FrameSignal.connect(callback);
	}

	void Scheduler::OnReady(Utils::Slot<Scheduler::Callback> callback, bool clientOnly)
	{
		if (clientOnly && Game::IsDedicated()) return;
		if (Scheduler::ReadyPassed) Scheduler::Once(callback);
		else Scheduler::ReadySignal.connect(callback);
	}

	void Scheduler::ReadyHandler()
	{
		if (!*Game::isDvarSystemActive)
		{
			Scheduler::Once(Scheduler::ReadyHandler);
		}
		else
		{
			Scheduler::ReadyPassed = true;
			Scheduler::ReadySignal();
			Scheduler::ReadySignal.clear();
		}
	}

	void Scheduler::FrameHandler([[maybe_unused]]bool isRenderer)
	{
		Scheduler::DelaySignal();
		Scheduler::FrameSignal();

		Utils::Signal<Scheduler::Callback> copy(Scheduler::FrameOnceSignal);
		Scheduler::FrameOnceSignal.clear();
		copy();
	}

	void Scheduler::OnDelay(Utils::Slot<Scheduler::Callback> callback, std::chrono::nanoseconds delay, bool clientOnly)
	{
		if (clientOnly && Game::IsDedicated()) return;

		Scheduler::DelayedSlot slot;
		slot.callback = callback;
		slot.delay = delay;

		Scheduler::DelayedSlots.push_back(slot);
	}

	void Scheduler::DelaySignal()
	{
		Utils::Signal<Scheduler::Callback> signal;

		for (auto i = Scheduler::DelayedSlots.begin(); i != Scheduler::DelayedSlots.end();)
		{
			if (i->interval.elapsed(i->delay))
			{
				signal.connect(i->callback);
				i = Scheduler::DelayedSlots.erase(i);
				continue;
			}

			++i;
		}

		signal();
	}

	void Scheduler::ShutdownStub(const char* str)
	{
		Scheduler::ShutdownSignal();

		Game::Com_Printf(str);
	}

	void Scheduler::OnFrameAsync(Utils::Slot<Scheduler::Callback> callback)
	{
		Scheduler::AsyncFrameSignal.connect(callback);
	}

	void Scheduler::OnceAsync(Utils::Slot<Scheduler::Callback> callback)
	{
		Scheduler::AsyncFrameOnceSignal.connect(callback);
	}

	void Scheduler::GameFrameStub()
	{
		FrameHandler();

		Game::Com_DedicatedModified();
	}

	Scheduler::Scheduler()
	{
		Scheduler::ReadyPassed = false;
		Scheduler::Once(Scheduler::ReadyHandler);

		Utils::Hook(0x4326C5, Scheduler::ShutdownStub, HOOK_CALL).install()->quick();
		Utils::Hook(0x43503D, Scheduler::GameFrameStub, HOOK_CALL).install()->quick();

		if (!Loader::IsPerformingUnitTests())
		{
			Scheduler::AsyncTerminate = false;
			Scheduler::AsyncThread = std::thread([]()
			{
				while (!Scheduler::AsyncTerminate)
				{
					Scheduler::AsyncFrameSignal();

					Utils::Signal<Scheduler::Callback> copy(Scheduler::AsyncFrameOnceSignal);
					Scheduler::AsyncFrameOnceSignal.clear();
					copy();

					std::this_thread::sleep_for(16ms);
				}
			});
		}
	}

	Scheduler::~Scheduler()
	{
		Scheduler::ReadySignal.clear();
		Scheduler::ShutdownSignal.clear();

		Scheduler::FrameSignal.clear();
		Scheduler::FrameOnceSignal.clear();
		Scheduler::DelayedSlots.clear();

		Scheduler::AsyncFrameSignal.clear();
		Scheduler::AsyncFrameOnceSignal.clear();

		Scheduler::ReadyPassed = false;
	}

	void Scheduler::preDestroy()
	{
		Scheduler::AsyncTerminate = true;
		if (Scheduler::AsyncThread.joinable())
		{
			Scheduler::AsyncThread.join();
		}
	}
}
