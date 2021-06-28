#pragma once

// Version number
#include "version.h"

#ifndef RC_INVOKED

#define _HAS_CXX17 1
#define _HAS_CXX20 1
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

// Requires Visual Leak Detector plugin: http://vld.codeplex.com/
#define VLD_FORCE_ENABLE
//#include <vld.h>
#pragma warning(disable: 4740)

#include <windows.h>
#include <timeapi.h>
#include <shellapi.h>
#include <Wininet.h>
#include <Aclapi.h>
#include <Psapi.h>
#include <tlhelp32.h>
#include <Shlwapi.h>

#pragma warning(push)
#pragma warning(disable: 4091)
#pragma warning(disable: 4244)
#include <dbghelp.h>

#include <sstream>
#include <fstream>
#include <cctype>
#include <regex>
#include <thread>
#include <future>
#include <map>
#include <queue>

// Experimental C++17 features
#include <filesystem>
#include <optional>

#pragma warning(pop)

// Usefull for debugging
template <size_t S> class Sizer { };
#define BindNum(x, y) Sizer<x> y;
#define Size_Of(x, y) BindNum(sizeof(x), y)
#define Offset_Of(x, y, z) BindNum(offsetof(x, y), z)

// Submodules
// Ignore the warnings, it's not our code!
#pragma warning(push)
#pragma warning(disable: 4005)
#pragma warning(disable: 4091)
#pragma warning(disable: 4100)
#pragma warning(disable: 4244)
#pragma warning(disable: 4389)
#pragma warning(disable: 4702)
#pragma warning(disable: 4800)
#pragma warning(disable: 4996) // _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 5054)
#pragma warning(disable: 6001)
#pragma warning(disable: 6011)
#pragma warning(disable: 6031)
#pragma warning(disable: 6255)
#pragma warning(disable: 6258)
#pragma warning(disable: 6386)
#pragma warning(disable: 6387)

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#pragma warning(pop)

#include "Utils/Hooking.hpp"

#include "Game/MP.hpp"

// Libraries
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Wininet.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "Urlmon.lib")
#pragma comment(lib, "Advapi32.lib")
#pragma comment(lib, "rpcrt4.lib")
#pragma comment(lib, "dbghelp.lib")

// Enable additional literals
using namespace std::literals;

#endif

#define STRINGIZE_(x) #x
#define STRINGIZE(x) STRINGIZE_(x)

#define AssertSize(x, size) static_assert(sizeof(x) == size, STRINGIZE(x) " structure has an invalid size.")
#define AssertOffset(x, y, offset) static_assert(offsetof(x, y) == offset, STRINGIZE(x) "::" STRINGIZE(y) " is not at the right offset.")

// Resource stuff
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
// Defines below make accessing the resources from the code easier.
#define _APS_NEXT_RESOURCE_VALUE        102
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif
