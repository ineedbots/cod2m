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


	Player_GetMethod_t* Player_GetMethod;
	Scr_GetFunction_t* Scr_GetFunction;
		
	void Init(GAMEEXE)
	{
		Player_GetMethod = ASSIGN(Player_GetMethod_t*, 0x52E050);
		Scr_GetFunction = ASSIGN(Scr_GetFunction_t*, 0x50D280);


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
}

