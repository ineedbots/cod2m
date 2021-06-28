#include "STDInclude.hpp"

namespace Game
{
	void Init(GAMEEXE)
	{
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
}

