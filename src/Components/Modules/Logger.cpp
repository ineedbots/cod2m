#include "STDInclude.hpp"
#include "Logger.hpp"
#include "Flags.hpp"

namespace Components
{
	bool Logger::IsConsoleReady()
	{
		return true;
	}

	void Logger::PrintStub(int channel, const char* message, ...)
	{
		return Logger::MessagePrint(channel, Logger::Format(&message));
	}

	void Logger::Print(const char* message, ...)
	{
		return Logger::MessagePrint(0, Logger::Format(&message));
	}

	void Logger::Print(int channel, const char* message, ...)
	{
		return Logger::MessagePrint(channel, Logger::Format(&message));
	}

	void Logger::MessagePrint([[maybe_unused]] int channel, [[maybe_unused]] const std::string& message)
	{
		if (Flags::HasFlag("stdout") || Loader::IsPerformingUnitTests())
		{
			printf("%s", message.data());
			fflush(stdout);
			return;
		}

		/*if (!Logger::IsConsoleReady())
		{
			OutputDebugStringA(message.data());
		}

		if (!Game::Sys_IsMainThread())
		{
			Logger::EnqueueMessage(message);
		}
		else
		{
			Game::Com_PrintMessage(channel, message.data(), 0);
		}*/
	}

	void Logger::ErrorPrint([[maybe_unused]] int error, [[maybe_unused]] const std::string& message)
	{
#ifdef DEBUG
		if (IsDebuggerPresent()) __debugbreak();
#endif

		//Game::Com_Error(error, "%s", message.data());
	}

	void Logger::Error(int error, const char* message, ...)
	{
		return Logger::ErrorPrint(error, Logger::Format(&message));
	}

	void Logger::Error(const char* message, ...)
	{
		return Logger::ErrorPrint(0, Logger::Format(&message));
	}

	void Logger::SoftError(const char* message, ...)
	{
		return Logger::ErrorPrint(2, Logger::Format(&message));
	}

	std::string Logger::Format(const char** message)
	{
		const size_t bufferSize = 0x10000;
		Utils::Memory::Allocator allocator;
		char* buffer = allocator.allocateArray<char>(bufferSize);

		va_list ap = reinterpret_cast<char*>(const_cast<char**>(&message[1]));
		//va_start(ap, *message);
		_vsnprintf_s(buffer, bufferSize, bufferSize, *message, ap);
		va_end(ap);

		return buffer;
	}

	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
	}
}
