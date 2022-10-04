#pragma once

#define SELECT(addr) (addr)
#define ASSIGN(type, addr) reinterpret_cast<type>(SELECT(addr))

namespace Game
{
	void Init(GAMEEXE);
	bool IsDedicated();

	extern char* isDvarSystemActive;

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
	
	typedef void (Com_DedicatedModified_t)();
	extern Com_DedicatedModified_t* Com_DedicatedModified;

	typedef void(Com_Printf_t)(const char *, ...);
	extern Com_Printf_t* Com_Printf;

	typedef cvar_t*(Dvar_RegisterBool_t)(const char *, int, int);
	extern Dvar_RegisterBool_t* Dvar_RegisterBool;

	extern unsigned int Scr_GetFunctionHandle(const char*, const char*);
	extern __int16 Scr_ExecThread(int, int);
	extern void RemoveRefToObject(int);
	
	typedef Game::xmethod_t (Player_GetMethod_t)(const char**);
	extern Player_GetMethod_t* Player_GetMethod;

	typedef Game::xfunction_t (Scr_GetFunction_t)(const char**, int*);
	extern Scr_GetFunction_t* Scr_GetFunction;

	typedef void (Cmd_AddCommand_t)(const char*, Game::xcommand_t);
	extern Cmd_AddCommand_t* Cmd_AddCommand;
	
	typedef void (Cmd_FindCommand_t)(const char*);
	extern Cmd_FindCommand_t* Cmd_FindCommand;

	//VariableValue *__cdecl sub_483580(union VariableUnion a1) addint
	//int __usercall sub_483770@<eax>(char *a2@<esi>) addstring
	//VariableValue *__cdecl sub_4835D0(float a1) addfloat
	//_DWORD *__usercall Scr_AddVector@<eax>(_DWORD *a2@<esi>) 4838B0

	//double __usercall sub_482DB0@<st0>(unsigned int a1@<eax>) getfloat
	//char __usercall sub_483160@<al>(unsigned int a1@<eax>, _DWORD *a2@<edx>) get vector

	extern int FS_GetFileList(const char*, const char*, int, char*, size_t);
	extern int FS_ForEachFile(const char*, const char*, void(char*));

	extern const char* Scr_GetString(unsigned int);
	extern int Scr_GetInt(unsigned int);
	extern void Scr_AddInt(int);
	extern void G_SelectWeaponIndex(int, int);
	extern void SV_ClientThink(Game::usercmd_s*, Game::client_t*);
	extern void SV_DropClient(Game::client_t*, const char*);
	extern void CM_Trace(float*, float*, float*, int, float*, int, int);

	extern int StuckInClient(Game::gentity_t*);
}
