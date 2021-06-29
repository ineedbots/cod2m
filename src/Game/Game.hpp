#pragma once

#define SELECT(addr) (addr)
#define ASSIGN(type, addr) reinterpret_cast<type>(SELECT(addr))

namespace Game
{
	void Init(GAMEEXE);
	bool IsDedicated();

	extern clientStatic_t* cls;
	extern serverStatic_t* svs;
	extern server_t* sv;

	extern scrCompilePub_t* gScrCompilePub;
	extern scrVarPub_t* scrVarPub;
	extern scrVmPub_t* scrVmPub;

	extern cgs_t* cgsArray;
	extern cg_t* cgArray;

	extern centity_s* cg_entitiesArray;

	extern WeaponDef_t** BG_WeaponNames;

	extern gentity_t* g_entities;
	extern gclient_t* g_clients;

	extern bgs_s* level_bgs;

	extern level_locals_t* level;

	extern stringIndex_t* scr_const;

	extern bgs_s** bgs_ptr;

	typedef int (Scr_LoadScript_t)(char*);
	extern Scr_LoadScript_t* Scr_LoadScript;

	typedef void (GScr_LoadGameTypeScript_t)();
	extern GScr_LoadGameTypeScript_t* GScr_LoadGameTypeScript;

	typedef void (G_LoadStructs_t)();
	extern G_LoadStructs_t* G_LoadStructs;

	typedef int (Sys_Milliseconds_t)();
	extern Sys_Milliseconds_t* Sys_Milliseconds;

	extern unsigned int Scr_GetFunctionHandle(char*, const char*);
	extern __int16 Scr_ExecThread(int);
	extern void RemoveRefToObject(int);
	
	typedef Game::xmethod_t (Player_GetMethod_t)(const char**);
	extern Player_GetMethod_t* Player_GetMethod;

	typedef Game::xfunction_t (Scr_GetFunction_t)(const char**, int*);
	extern Scr_GetFunction_t* Scr_GetFunction;

	extern void G_SelectWeaponIndex(int, int);
	extern void SV_ClientThink(Game::usercmd_s*, Game::client_t*);
	extern void SV_DropClient(Game::client_t*, const char*);
}
