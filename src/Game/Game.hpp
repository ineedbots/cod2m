#pragma once

#define SELECT(addr) (addr)
#define ASSIGN(type, addr) reinterpret_cast<type>(SELECT(addr))

namespace Game
{
	void Init(GAMEEXE);

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


	void SV_ClientThink(Game::usercmd_s*, Game::client_t*);
}
