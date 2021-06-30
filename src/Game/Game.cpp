#include "STDInclude.hpp"

namespace Game
{
	clientStatic_t* cls;
	serverStatic_t* svs;
	server_t* sv;

	scrCompilePub_t* gScrCompilePub;
	scrVarPub_t* scrVarPub;
	scrVmPub_t* scrVmPub;

	cgs_t* cgsArray;
	cg_t* cgArray;

	centity_s* cg_entitiesArray;

	WeaponDef_t** BG_WeaponNames;

	gentity_t* g_entities;
	gclient_t* g_clients;

	bgs_s* level_bgs;

	level_locals_t* level;

	stringIndex_t* scr_const;

	bgs_s** bgs_ptr;

	Scr_LoadScript_t* Scr_LoadScript;
	Scr_GetFunction_t* Scr_GetFunction;
	Player_GetMethod_t* Player_GetMethod;
	GScr_LoadGameTypeScript_t* GScr_LoadGameTypeScript;
	G_LoadStructs_t* G_LoadStructs;
	Sys_Milliseconds_t* Sys_Milliseconds;
	Com_Printf_t* Com_Printf;
	Com_DedicatedModified_t* Com_DedicatedModified;
	Dvar_RegisterBool_t* Dvar_RegisterBool;
	Cmd_AddCommand_t* Cmd_AddCommand;
	Cmd_FindCommand_t* Cmd_FindCommand;


	char* isDvarSystemActive;

	bool IsDedicated()
	{
		return false;
	}
		
	void Init(GAMEEXE)
	{
		Player_GetMethod = ASSIGN(Player_GetMethod_t*, 0x52E050);
		Scr_GetFunction = ASSIGN(Scr_GetFunction_t*, 0x50D280);
		Scr_LoadScript = ASSIGN(Scr_LoadScript_t*, 0x474D80);
		GScr_LoadGameTypeScript = ASSIGN(GScr_LoadGameTypeScript_t*, 0x503F90);
		G_LoadStructs = ASSIGN(G_LoadStructs_t*, 0x5118A0);
		Sys_Milliseconds = ASSIGN(Sys_Milliseconds_t*, 0x435200);
		Com_Printf = ASSIGN(Com_Printf_t*, 0x431EE0);
		Com_DedicatedModified = ASSIGN(Com_DedicatedModified_t*, 0x434DC0);
		Dvar_RegisterBool = ASSIGN(Dvar_RegisterBool_t*, 0x438040);
		Cmd_AddCommand = ASSIGN(Cmd_AddCommand_t*, 0x4212F0);
		Cmd_FindCommand = ASSIGN(Cmd_FindCommand_t*, 0x421290);


		isDvarSystemActive = ASSIGN(char*, 0xC5C5C8);

		cls = ASSIGN(clientStatic_t*, 0x68A408);
		svs = ASSIGN(serverStatic_t*, 0xD35700);
		sv = ASSIGN(server_t*, 0xCD6180);

		gScrCompilePub = ASSIGN(scrCompilePub_t*, 0xD77790);
		scrVarPub = ASSIGN(scrVarPub_t*, 0xF08F88);
		scrVmPub = ASSIGN(scrVmPub_t*, 0xF4B900);

		cgsArray = ASSIGN(cgs_t*, 0x14C3700);
		cgArray = ASSIGN(cg_t*, 0x14EE080);

		cg_entitiesArray = ASSIGN(centity_s*, 0x15E2A80);

		BG_WeaponNames = ASSIGN(WeaponDef_t**, 0x1728200);

		g_entities = ASSIGN(gentity_t*, 0x1744380);
		g_clients = ASSIGN(gclient_t*, 0x1897E80);

		level_bgs = ASSIGN(bgs_s*, 0x17D03D0);

		level = ASSIGN(level_locals_t*, 0x193A780);

		scr_const = ASSIGN(stringIndex_t*, 0x1943920);

		bgs_ptr = ASSIGN(bgs_s**, 0x19A1C78);
	}

	unsigned int Scr_GetFunctionHandle(char* filename, const char* funcHandle)
	{
		int func_loc = 0x474950;
		unsigned int answer;

		__asm
		{
			push funcHandle;
			mov eax, filename;
			call func_loc;
			add esp, 4;
			mov answer, eax;
		}

		return answer;
	}

	__int16 Scr_ExecThread(int handle)
	{
		int func_loc = 0x482080;
		__int16 answer;

		__asm
		{
			mov eax, handle;
			call func_loc;
			mov answer, ax;
		}

		return answer;
	}

	void RemoveRefToObject(int obj)
	{
		int func_loc = 0x479660;

		__asm
		{
			mov eax, obj;
			call func_loc;
		}
	}

	const char* Scr_GetString(unsigned int slot)
	{
		int func_loc = 0x482FF0;
		const char* answer;

		__asm
		{
			mov eax, slot;
			call func_loc;
			mov answer, eax;
		}

		return answer;
	}

	int Scr_GetInt(unsigned int slot)
	{
		int func_loc = 0x482B80;
		int answer;

		__asm
		{
			mov eax, slot;
			call func_loc;
			mov answer, eax;
		}

		return answer;
	}

	void G_SelectWeaponIndex(int wpIdx, int clNum)
	{
		int func_loc = 0x5282E0;

		__asm
		{
			mov esi, clNum;
			mov eax, wpIdx;
			call func_loc;
		}
	}

	void SV_ClientThink(Game::usercmd_s* cmd, Game::client_t* client)
	{
		int func_loc = 0x456010;

		__asm
		{
			mov ecx, client;
			mov eax, cmd;
			call func_loc;
		}
	}

	void SV_DropClient(Game::client_t* client, const char* reason)
	{
		int func_loc = 0x454750;

		__asm
		{
			push reason;
			mov eax, client;
			call func_loc;
			add esp, 4;
		}
	}

	void CM_Trace(float* a1, float* a2, float* a3, int a4, float* a5, int a6, int a7)
	{
		int func_loc = 0x41D120;

		__asm
		{
			push a7;
			push a6;
			push a5;
			push a4;
			mov ecx, a3;
			mov edx, a2;
			mov eax, a1;
			call func_loc;
			add esp, 0x10;
		}
	}

	int StuckInClient(Game::gentity_t* ent)
	{
		int func_loc = 0x5009F0;
		int answer;

		__asm
		{
			mov eax, ent;
			call func_loc;
			mov answer, eax;
		}

		return answer;
	}
}

