#pragma once

#define SELECT(addr) (addr)
#define ASSIGN(type, addr) reinterpret_cast<type>(SELECT(addr))

namespace Game
{
	void Init(GAMEEXE);

	static clientStatic_t* cls;
	static serverStatic_t* svs;
	static server_t* sv;

	static scrCompilePub_t* gScrCompilePub;
	static scrVarPub_t* scrVarPub;
	static scrVmPub_t* scrVmPub;

	static cgs_t* cgsArray;
	static cg_t* cgArray;

	static centity_s* cg_entitiesArray;

	static WeaponDef_t** BG_WeaponNames;

	static gentity_t* g_entities;
	static gclient_t* g_clients;

	static bgs_s* level_bgs;

	static level_locals_t* level;

	static stringIndex_t* scr_const;

	static bgs_s** bgs_ptr;
}
