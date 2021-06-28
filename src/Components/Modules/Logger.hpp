#pragma once

namespace Components
{
	class Logger : public Component
	{
	public:
		Logger();
		~Logger();

		static void MessagePrint(int channel, const std::string& message);
		static void Print(int channel, const char* message, ...);
		static void Print(const char* message, ...);
		static void ErrorPrint(int error, const std::string& message);
		static void Error(const char* message, ...);
		static void Error(int error, const char* message, ...);
		static void SoftError(const char* message, ...);
		static bool IsConsoleReady();

		static void PrintStub(int channel, const char* message, ...);

	private:

		static std::string Format(const char** message);
	};
}
