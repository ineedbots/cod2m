#pragma once

namespace Game
{
    typedef float vec_t;
    typedef vec_t vec3_t[3];
    typedef vec_t vec2_t[2];
    typedef vec_t vec4_t[4];
    typedef vec_t vec5_t[5];
    typedef int scr_entref_t;

    struct turretInfo_s
    {
      int inuse;
      int flags;
      int fireTime;
      vec2_t arcmin;
      vec2_t arcmax;
      float dropPitch;
      int stance;
      int prevStance;
      int fireSndDelay;
      vec3_t userOrigin;
      float playerSpread;
      int triggerDown;
      char fireSnd;
      char fireSndPlayer;
      char stopSnd;
      char stopSndPlayer;
    };

    typedef enum
    {
      PLAYERVIEWLOCK_NONE = 0x0,
      PLAYERVIEWLOCK_FULL = 0x1,
      PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
      PLAYERVIEWLOCKCOUNT = 0x3,
    } ViewLockTypes_t;

    typedef struct
    {
      float yaw;
      int timer;
      int transIndex;
      int flags;
    } mantleState_t;

    typedef enum
    {
      OBJST_EMPTY = 0x0,
      OBJST_ACTIVE = 0x1,
      OBJST_INVISIBLE = 0x2,
      OBJST_DONE = 0x3,
      OBJST_CURRENT = 0x4,
      OBJST_FAILED = 0x5,
      OBJST_NUMSTATES = 0x6,
    } objectiveState_t;

    typedef struct objective_s
    {
      objectiveState_t state;
      vec3_t origin;
      int entNum;
      int teamNum;
      int icon;
    } objective_t;

    typedef enum
    {
      HE_TYPE_FREE = 0x0,
      HE_TYPE_TEXT = 0x1,
      HE_TYPE_VALUE = 0x2,
      HE_TYPE_PLAYERNAME = 0x3,
      HE_TYPE_MAPNAME = 0x4,
      HE_TYPE_GAMETYPE = 0x5,
      HE_TYPE_MATERIAL = 0x6,
      HE_TYPE_TIMER_DOWN = 0x7,
      HE_TYPE_TIMER_UP = 0x8,
      HE_TYPE_TENTHS_TIMER_DOWN = 0x9,
      HE_TYPE_TENTHS_TIMER_UP = 0xA,
      HE_TYPE_CLOCK_DOWN = 0xB,
      HE_TYPE_CLOCK_UP = 0xC,
      HE_TYPE_WAYPOINT = 0xD,
      HE_TYPE_COUNT = 0xE,
    } he_type_t;

    typedef struct
    {
      char r;
      char g;
      char b;
      char a;
    } hudelem_colorsplit_t;

    typedef union
    {
      hudelem_colorsplit_t split;
      int rgba;
    } hudelem_color_t;

    typedef struct hudelem_s
    {
      he_type_t type;
      float x;
      float y;
      float z;
      float fontScale;
      int font;
      int alignOrg;
      int alignScreen;
      hudelem_color_t color;
      hudelem_color_t fromColor;
      int fadeStartTime;
      int fadeTime;
      int label;
      int width;
      int height;
      int materialIndex;
      int fromWidth;
      int fromHeight;
      int scaleStartTime;
      int scaleTime;
      float fromX;
      float fromY;
      int fromAlignOrg;
      int fromAlignScreen;
      int moveStartTime;
      int moveTime;
      int time;
      int duration;
      float value;
      int text;
      float sort;
      hudelem_color_t glowColor;
    } hudelem_t;

    typedef struct hudElemState_s
    {
      hudelem_t current[31];
      hudelem_t archival[31];
    } hudElemState_t;

    typedef struct playerState_s
    {
      int commandTime;
      int pm_type;
      int bobCycle;
      int pm_flags;
      int pm_time;
      vec3_t origin;
      vec3_t velocity;
      vec2_t oldVelocity;
      int weaponTime;
      int weaponDelay;
      int grenadeTimeLeft;
      int throwBackGrenadeOwner;
      int throwBackGrenadeTimeLeft;
      int gravity;
      float leanf;
      int speed;
      vec3_t delta_angles;
      int groundEntityNum;
      vec3_t vLadderVec;
      int jumpTime;
      float jumpOriginZ;
      int legsTime;
      int legsAnim;
      int torsoTime;
      int torsoAnim;
      int legsAnimDuration;
      int torsoAnimDuration;
      int damageTimer;
      int damageDuration;
      int flinchYawAnim;
      int movementDir;
      int eFlags;
      int eventSequence;
      int events[4];
      unsigned int eventParms[4];
      int oldEventSequence;
      int clientNum;
      int offHandIndex;
      unsigned int weapon;
      int weaponstate;
      float fWeaponPosFrac;
      int adsDelayTime;
      int viewmodelIndex;
      vec3_t viewangles;
      int viewHeightTarget;
      float viewHeightCurrent;
      int viewHeightLerpTime;
      int viewHeightLerpTarget;
      int viewHeightLerpDown;
      int unknown[5];
      int damageEvent;
      int damageYaw;
      int damagePitch;
      int damageCount;
      int stats[6];
      int ammo[128];
      int ammoclip[128];
      int weapFlags;
      int weapFlags2;
      int unknown2[2];
      byte slot_none;
      byte slot_primary;
      byte slot_primaryb;
      int unknown3[5];
      vec3_t mins;
      vec3_t maxs;
      float proneDirection;
      float proneDirectionPitch;
      float proneTorsoPitch;
      ViewLockTypes_t viewlocked;
      int viewlocked_entNum;
      int cursorHint;
      int cursorHintString;
      int cursorHintEntIndex;
      int unknown1;
      vec3_t unkAngles;
      float holdBreathScale;
      int holdBreathTimer;
      mantleState_t mantleState;
      int entityEventSequence;
      int weapAnim;
      float aimSpreadScale;
      int shellshockIndex;
      int shellshockTime;
      int shellshockDuration;
      objective_t objective[16];
      int archiveTime;
      hudElemState_t hud;
    } playerState_t;

    typedef enum
    {
      STATE_PLAYING = 0x0,
      STATE_DEAD = 0x1,
      STATE_SPECTATOR = 0x2,
      STATE_INTERMISSION = 0x3,
    } sessionState_t;

    typedef enum
    {
      CON_DISCONNECTED = 0x0,
      CON_CONNECTING = 0x1,
      CON_CONNECTED = 0x2,
    } clientConnected_t;

    typedef struct usercmd_s
    {
      int serverTime;
      int buttons;
      byte weapon;
      byte offHandIndex;
      int angles[3];
      char forwardmove;
      char rightmove;
    } usercmd_t;

    typedef enum
    {
      TEAM_NONE = 0x0,
      TEAM_AXIS = 0x1,
      TEAM_ALLIES = 0x2,
      TEAM_SPECTATOR = 0x3,
    } sessionTeam_t;

    typedef struct
    {
      sessionState_t state;
      int forceSpectatorClient;
      int statusIcon;
      int archiveTime;
      int score;
      int deaths;
      unsigned __int16 scriptPersId;
      byte pad2;
      byte pad;
      clientConnected_t connected;
      usercmd_t cmd;
      usercmd_t oldcmd;
      int localClient;
      int predictItemPickup;
      char name[32];
      int maxHealth;
      int enterTime;
      int voteCount;
      int teamVoteCount;
      float unknown;
      int viewmodelIndex;
      int noSpectate;
      int teamInfo;
      int clientId;
      sessionTeam_t team;
      int model;
      int attachedModels[6];
      int attachedModelsTags[6];
      char manualModeName[32];
      int psOffsetTime;
    } clientSession_t;

    typedef enum
    {
      TR_STATIONARY = 0x0,
      TR_INTERPOLATE = 0x1,
      TR_LINEAR = 0x2,
      TR_LINEAR_STOP = 0x3,
      TR_SINE = 0x4,
      TR_GRAVITY = 0x5,
      TR_GRAVITY_PAUSED = 0x6,
      TR_ACCELERATE = 0x7,
      TR_DECCELERATE = 0x8,
    } trType_t;

    typedef struct
    {
      trType_t trType;
      int trTime;
      int trDuration;
      vec3_t trBase;
      vec3_t trDelta;
    } trajectory_t;

    typedef struct entityState_s
    {
      int number;
      int eType;
      int eFlags;
      trajectory_t pos;
      trajectory_t apos;
      int time;
      int time2;
      vec3_t origin;
      vec3_t angles;
      int otherEntityNum;
      int attackerEntityNum;
      int groundEntityNum;
      int constantLight;
      int loopSound;
      int surfaceFlags;
      int modelindex;
      int clientNum;
      int iHeadIcon;
      int iHeadIconTeam;
      int solid;
      int eventParm;
      int eventSequence;
      vec4_t events;
      vec4_t eventParms;
      int weapon;
      int legsAnim;
      int torsoAnim;
      int stage;
      int loopfxid;
      int hintstring;
      int animMovetype;
      vec3_t unkAngles;
    } entityState_t;

    typedef struct
    {
      byte linked;
      byte bmodel;
      byte svFlags;
      byte pad1;
      int clientMask[2];
      byte inuse;
      byte pad2[3];
      int broadcastTime;
      vec3_t mins;
      vec3_t maxs;
      int contents;
      vec3_t absmin;
      vec3_t absmax;
      vec3_t currentOrigin;
      vec3_t currentAngles;
      unsigned __int16 ownerNum;
      unsigned __int16 pad3;
      int eventTime;
    } entityShared_t;

    typedef struct gentity_s
    {
      entityState_t s;
      entityShared_t r;
      struct gclient_s *client;
      turretInfo_s *pTurretInfo;
      byte physicsObject;
      byte takedamage;
      byte active;
      byte nopickup;
      byte model;
      byte dobjbits;
      byte handler;
      byte team;
      unsigned __int16 classname;
      unsigned __int16 target;
      unsigned __int16 targetname;
      unsigned __int16 padding;
      int spawnflags;
      int flags;
      int eventTime;
      int freeAfterEvent;
      int unlinkAfterEvent;
      int clipmask;
      int framenum;
      struct gentity_s *parent;
      int nextthink;
      int healthPoints;
      int reservedHealth;
      int damage;
      int splashDamage;
      int splashRadius;
      float pfDecelTimeMove;
      float pfDecelTimeRotate;
      float pfSpeedMove;
      float pfSpeedRotate;
      float pfMidTimeMove;
      float pfMidTimeRotate;
      vec3_t vPos1Move;
      vec3_t vPos2Move;
      vec3_t vPos3Move;
      vec3_t vPos1Rotate;
      vec3_t vPos2Rotate;
      vec3_t vPos3Rotate;
      int moverState;
      struct gentity_s **linkedEntities;
      byte attachedModels[6];
      unsigned __int16 attachedModelsIndexes;
      unsigned __int16 numAttachedModels;
      int animTree;
      vec4_t color;
    } gentity_t;

    typedef struct gclient_s
    {
      playerState_t ps;
      clientSession_t sess;
      int spectatorClient;
      int noclip;
      int ufo;
      int bFrozen;
      int lastCmdTime;
      int buttons;
      int oldbuttons;
      int latched_buttons;
      int buttonsSinceLastFrame;
      vec3_t oldOrigin;
      float fGunPitch;
      float fGunYaw;
      int damage_blood;
      vec3_t damage_from;
      int damage_fromWorld;
      int accurateCount;
      int accuracy_shots;
      int accuracy_hits;
      int inactivityTime;
      int inactivityWarning;
      int playerTalkTime;
      int rewardTime;
      float currentAimSpreadScale;
      int unknown_space[2];
      int unknownClientEndFrameVar;
      int unknown_space2[3];
      gentity_t *lookAtEntity;
      int activateEntNumber;
      int activateTime;
      int nonPVSFriendlyEntNum;
      int pingPlayerTime;
      int damageFeedBackTime;
      vec2_t damageFeedBackDir;
      vec3_t swayViewAngles;
      vec3_t swayOffset;
      vec3_t swayAngles;
      int unknown_space3[7];
      float weaponRecoil;
      int unknown_space4[3];
      int lastServerTime;
      int lastActivateTime;
    } gclient_t;

    typedef enum
    {
      MOD_UNKNOWN = 0x0,
      MOD_PISTOL_BULLET = 0x1,
      MOD_RIFLE_BULLET = 0x2,
      MOD_GRENADE = 0x3,
      MOD_GRENADE_SPLASH = 0x4,
      MOD_PROJECTILE = 0x5,
      MOD_PROJECTILE_SPLASH = 0x6,
      MOD_MELEE = 0x7,
      MOD_HEAD_SHOT = 0x8,
      MOD_CRUSH = 0x9,
      MOD_TELEFRAG = 0xA,
      MOD_FALLING = 0xB,
      MOD_SUICIDE = 0xC,
      MOD_TRIGGER_HURT = 0xD,
      MOD_EXPLOSIVE = 0xE,
      MOD_BAD = 0xF,
    } meansOfDeath_t;

    enum svc_ops_e
    {
      svc_nop = 0x0,
      svc_gamestate = 0x1,
      svc_configstring = 0x2,
      svc_baseline = 0x3,
      svc_serverCommand = 0x4,
      svc_download = 0x5,
      svc_snapshot = 0x6,
      svc_EOF = 0x7,
    };

    typedef enum
    {
      ET_GENERAL = 0x0,
      ET_PLAYER = 0x1,
      ET_CORPSE = 0x2,
      ET_ITEM = 0x3,
      ET_MISSILE = 0x4,
      ET_INVISIBLE = 0x5,
      ET_SCRIPTMOVER = 0x6,
    } entityType_t;

    typedef enum
    {
      TEAM_FREE = 0x0,
      TEAM_RED = 0x1,
      TEAM_BLUE = 0x2,
      TEAM_SPEC = 0x3,
      TEAM_NUM_TEAMS = 0x4,
    } team_t;

    typedef enum
    {
      CS_FREE = 0x0,
      CS_ZOMBIE = 0x1,
      CS_CONNECTED = 0x2,
      CS_PRIMED = 0x3,
      CS_ACTIVE = 0x4,
    } clientState_t;

    typedef enum
    {
      NA_BOT = 0x0,
      NA_BAD = 0x0,
      NA_LOOPBACK = 0x2,
      NA_BROADCAST = 0x3,
      NA_IP = 0x4,
      NA_IPX = 0x5,
      NA_BROADCAST_IPX = 0x6,
    } netadrtype_t;

    typedef struct
    {
      netadrtype_t type;
      byte ip[4];
      unsigned __int16 port;
      byte ipx[10];
    } netadr_t;

    typedef enum
    {
      NS_CLIENT = 0x0,
      NS_SERVER = 0x1,
    } netsrc_t;

    typedef struct
    {
      int overflowed;
      byte *data;
      int maxsize;
      int cursize;
      int readcount;
      int bit;
    } msg_t;

    typedef union
    {
      int i;
      byte rgba[4];
    } ucolor_t;

    typedef enum : unsigned __int16
	{
		CVAR_FLAG_ARCHIVE = 1 << 0,				// 0x0001
		CVAR_FLAG_USERINFO = 1 << 1,			// 0x0002
		CVAR_FLAG_SERVERINFO = 1 << 2,			// 0x0004
		CVAR_FLAG_SYSTEMINFO = 1 << 3,			// 0x0008
		CVAR_FLAG_INIT = 1 << 4,				// 0x0010
		CVAR_FLAG_LATCH = 1 << 5,				// 0x0020
		CVAR_FLAG_ROM = 1 << 6,					// 0x0040
		CVAR_FLAG_CHEAT = 1 << 7,				// 0x0080
		CVAR_FLAG_DEVELOPER = 1 << 8,			// 0x0100
		CVAR_FLAG_SAVED = 1 << 9,				// 0x0200
		CVAR_FLAG_NORESTART = 1 << 10,			// 0x0400
		CVAR_FLAG_CHANGEABLE_RESET = 1 << 12,	// 0x1000
		CVAR_FLAG_EXTERNAL = 1 << 14,			// 0x4000
		CVAR_FLAG_AUTOEXEC = 1 << 15,			// 0x8000
	} CvarFlags;
	
	enum cvarType_t : char
	{
		CVAR_TYPE_BOOL = 0x0,
		CVAR_TYPE_FLOAT = 0x1,
		CVAR_TYPE_FLOAT_2 = 0x2,
		CVAR_TYPE_FLOAT_3 = 0x3,
		CVAR_TYPE_FLOAT_4 = 0x4,
		CVAR_TYPE_INT = 0x5,
		CVAR_TYPE_ENUM = 0x6,
		CVAR_TYPE_STRING = 0x7,
		CVAR_TYPE_COLOR = 0x8,
		CVAR_TYPE_COUNT = 0x9,
	};

    enum DvarSetSource
	{
		CVAR_SOURCE_INTERNAL = 0x0,
		CVAR_SOURCE_EXTERNAL = 0x1,
		CVAR_SOURCE_SCRIPT = 0x2,
		CVAR_SOURCE_DEVGUI = 0x3,
	};

    union cvar_value_s
    {
      float floatval;
      int integer;
      char *string;
      byte boolean;
      vec2_t vec2;
      vec3_t vec3;
      vec4_t vec4;
      ucolor_t color;
    };

    union cvar_bounds_s
    {
      int imin;
      float fmin;
    };

    union cvar_bounds_enum_s
    {
      int imax;
      float fmax;
      const char **enumStr;
    };

    typedef struct cvar_s
    {
      char *name;
      CvarFlags flags;
      cvarType_t type;
      byte modified;
      cvar_value_s current;
      cvar_value_s latched;
      cvar_value_s reset;
      cvar_bounds_s domain;
      cvar_bounds_enum_s domain_enum;
      struct cvar_s *next;
      struct cvar_s *hashNext;
    } cvar_t;

    struct VariableStackBuffer
    {
      const char *pos;
      unsigned __int16 size;
      unsigned __int16 bufLen;
      unsigned __int16 localId;
      char time;
      char buf[1];
    };

    union VariableUnion
    {
      int intValue;
      float floatValue;
      unsigned int stringValue;
      const float *vectorValue;
      const char *codePosValue;
      unsigned int pointerValue;
      struct VariableStackBuffer *stackValue;
      unsigned int entityOffset;
    };

    union ObjectInfo_u
    {
      unsigned __int16 size;
      unsigned __int16 entnum;
      unsigned __int16 nextEntId;
      unsigned __int16 self;
    };

    struct ObjectInfo
    {
      unsigned __int16 refCount;
      union ObjectInfo_u u;
    };

    union VariableValueInternal_u
    {
      unsigned __int16 next;
      union VariableUnion u;
      struct ObjectInfo o;
    };

    union VariableValueInternal_w
    {
      unsigned int status;
      unsigned int type;
      unsigned int name;
      unsigned int classnum;
      unsigned int notifyName;
      unsigned int waitTime;
      unsigned int parentLocalId;
    };

    union VariableValueInternal_v
    {
      unsigned __int16 next;
      unsigned __int16 index;
    };

    typedef struct
    {
      union VariableUnion u;
      int type;
    } VariableValue;

    union Variable_u
    {
      unsigned __int16 prev;
      unsigned __int16 prevSibling;
    };

    struct Variable
    {
      unsigned __int16 id;
      union Variable_u u;
    };

    typedef struct
    {
      struct Variable hash;
      union VariableValueInternal_u u;
      union VariableValueInternal_w w;
      union VariableValueInternal_v v;
      unsigned __int16 nextSibling;
    } VariableValueInternal;

    typedef struct
    {
      const char *fieldBuffer;
      struct HunkUser *programHunkUser;
      unsigned __int16 canonicalStrCount;
      byte developer;
      byte developer_script;
      byte evaluate;
      byte pad[3];
      const char *error_message;
      int error_index;
      unsigned int time;
      unsigned int timeArrayId;
      unsigned int pauseArrayId;
      unsigned int levelId;
      unsigned int gameId;
      unsigned int animId;
      unsigned int freeEntList;
      unsigned int tempVariable;
      byte bInited;
      byte pad2;
      unsigned __int16 savecount;
      unsigned int checksum;
      unsigned int entId;
      unsigned int entFieldName;
      const char *programBuffer;
      const char *endScriptBuffer;
    } scrVarPub_t;

    struct function_stack_t
    {
      const char *pos;
      unsigned int localId;
      unsigned int localVarCount;
      VariableValue *top;
      VariableValue *startTop;
    };

    struct function_frame_t
    {
      struct function_stack_t fs;
      int topType;
    };

    typedef struct
    {
      unsigned int *localVars;
      VariableValue *maxstack;
      int function_count;
      struct function_frame_t *function_frame;
      VariableValue *top;
      byte debugCode;
      byte abort_on_error;
      byte terminal_error;
      byte pad;
      unsigned int inparamcount;
      unsigned int outparamcount;
      struct function_frame_t function_frame_start[32];
      VariableValue stack[2048];
    } scrVmPub_t;

    typedef int fileHandle_t;

    typedef void (__stdcall *xfunction_t)();

    typedef void (__stdcall *xmethod_t)(scr_entref_t);

    typedef void (*xcommand_t)(void);

    typedef struct scr_function_s
    {
      const char *name;
      xfunction_t call;
      int developer;
    } scr_function_t;

    typedef struct scr_method_s
    {
      const char *name;
      xmethod_t call;
      int developer;
    } scr_method_t;

    typedef enum
    {
      EV_NONE = 0x0,
      EV_FOOTSTEP_RUN_DEFAULT = 0x1,
      EV_FOOTSTEP_RUN_BARK = 0x2,
      EV_FOOTSTEP_RUN_BRICK = 0x3,
      EV_FOOTSTEP_RUN_CARPET = 0x4,
      EV_FOOTSTEP_RUN_CLOTH = 0x5,
      EV_FOOTSTEP_RUN_CONCRETE = 0x6,
      EV_FOOTSTEP_RUN_DIRT = 0x7,
      EV_FOOTSTEP_RUN_FLESH = 0x8,
      EV_FOOTSTEP_RUN_FOLIAGE = 0x9,
      EV_FOOTSTEP_RUN_GLASS = 0xA,
      EV_FOOTSTEP_RUN_GRASS = 0xB,
      EV_FOOTSTEP_RUN_GRAVEL = 0xC,
      EV_FOOTSTEP_RUN_ICE = 0xD,
      EV_FOOTSTEP_RUN_METAL = 0xE,
      EV_FOOTSTEP_RUN_MUD = 0xF,
      EV_FOOTSTEP_RUN_PAPER = 0x10,
      EV_FOOTSTEP_RUN_PLASTER = 0x11,
      EV_FOOTSTEP_RUN_ROCK = 0x12,
      EV_FOOTSTEP_RUN_SAND = 0x13,
      EV_FOOTSTEP_RUN_SNOW = 0x14,
      EV_FOOTSTEP_RUN_WATER = 0x15,
      EV_FOOTSTEP_RUN_WOOD = 0x16,
      EV_FOOTSTEP_RUN_ASPHALT = 0x17,
      EV_FOOTSTEP_WALK_DEFAULT = 0x18,
      EV_FOOTSTEP_WALK_BARK = 0x19,
      EV_FOOTSTEP_WALK_BRICK = 0x1A,
      EV_FOOTSTEP_WALK_CARPET = 0x1B,
      EV_FOOTSTEP_WALK_CLOTH = 0x1C,
      EV_FOOTSTEP_WALK_CONCRETE = 0x1D,
      EV_FOOTSTEP_WALK_DIRT = 0x1E,
      EV_FOOTSTEP_WALK_FLESH = 0x1F,
      EV_FOOTSTEP_WALK_FOLIAGE = 0x20,
      EV_FOOTSTEP_WALK_GLASS = 0x21,
      EV_FOOTSTEP_WALK_GRASS = 0x22,
      EV_FOOTSTEP_WALK_GRAVEL = 0x23,
      EV_FOOTSTEP_WALK_ICE = 0x24,
      EV_FOOTSTEP_WALK_METAL = 0x25,
      EV_FOOTSTEP_WALK_MUD = 0x26,
      EV_FOOTSTEP_WALK_PAPER = 0x27,
      EV_FOOTSTEP_WALK_PLASTER = 0x28,
      EV_FOOTSTEP_WALK_ROCK = 0x29,
      EV_FOOTSTEP_WALK_SAND = 0x2A,
      EV_FOOTSTEP_WALK_SNOW = 0x2B,
      EV_FOOTSTEP_WALK_WATER = 0x2C,
      EV_FOOTSTEP_WALK_WOOD = 0x2D,
      EV_FOOTSTEP_WALK_ASPHALT = 0x2E,
      EV_FOOTSTEP_PRONE_DEFAULT = 0x2F,
      EV_FOOTSTEP_PRONE_BARK = 0x30,
      EV_FOOTSTEP_PRONE_BRICK = 0x31,
      EV_FOOTSTEP_PRONE_CARPET = 0x32,
      EV_FOOTSTEP_PRONE_CLOTH = 0x33,
      EV_FOOTSTEP_PRONE_CONCRETE = 0x34,
      EV_FOOTSTEP_PRONE_DIRT = 0x35,
      EV_FOOTSTEP_PRONE_FLESH = 0x36,
      EV_FOOTSTEP_PRONE_FOLIAGE = 0x37,
      EV_FOOTSTEP_PRONE_GLASS = 0x38,
      EV_FOOTSTEP_PRONE_GRASS = 0x39,
      EV_FOOTSTEP_PRONE_GRAVEL = 0x3A,
      EV_FOOTSTEP_PRONE_ICE = 0x3B,
      EV_FOOTSTEP_PRONE_METAL = 0x3C,
      EV_FOOTSTEP_PRONE_MUD = 0x3D,
      EV_FOOTSTEP_PRONE_PAPER = 0x3E,
      EV_FOOTSTEP_PRONE_PLASTER = 0x3F,
      EV_FOOTSTEP_PRONE_ROCK = 0x40,
      EV_FOOTSTEP_PRONE_SAND = 0x41,
      EV_FOOTSTEP_PRONE_SNOW = 0x42,
      EV_FOOTSTEP_PRONE_WATER = 0x43,
      EV_FOOTSTEP_PRONE_WOOD = 0x44,
      EV_FOOTSTEP_PRONE_ASPHALT = 0x45,
      EV_JUMP_DEFAULT = 0x46,
      EV_JUMP_BARK = 0x47,
      EV_JUMP_BRICK = 0x48,
      EV_JUMP_CARPET = 0x49,
      EV_JUMP_CLOTH = 0x4A,
      EV_JUMP_CONCRETE = 0x4B,
      EV_JUMP_DIRT = 0x4C,
      EV_JUMP_FLESH = 0x4D,
      EV_JUMP_FOLIAGE = 0x4E,
      EV_JUMP_GLASS = 0x4F,
      EV_JUMP_GRASS = 0x50,
      EV_JUMP_GRAVEL = 0x51,
      EV_JUMP_ICE = 0x52,
      EV_JUMP_METAL = 0x53,
      EV_JUMP_MUD = 0x54,
      EV_JUMP_PAPER = 0x55,
      EV_JUMP_PLASTER = 0x56,
      EV_JUMP_ROCK = 0x57,
      EV_JUMP_SAND = 0x58,
      EV_JUMP_SNOW = 0x59,
      EV_JUMP_WATER = 0x5A,
      EV_JUMP_WOOD = 0x5B,
      EV_JUMP_ASPHALT = 0x5C,
      EV_LANDING_DEFAULT = 0x5D,
      EV_LANDING_BARK = 0x5E,
      EV_LANDING_BRICK = 0x5F,
      EV_LANDING_CARPET = 0x60,
      EV_LANDING_CLOTH = 0x61,
      EV_LANDING_CONCRETE = 0x62,
      EV_LANDING_DIRT = 0x63,
      EV_LANDING_FLESH = 0x64,
      EV_LANDING_FOLIAGE = 0x65,
      EV_LANDING_GLASS = 0x66,
      EV_LANDING_GRASS = 0x67,
      EV_LANDING_GRAVEL = 0x68,
      EV_LANDING_ICE = 0x69,
      EV_LANDING_METAL = 0x6A,
      EV_LANDING_MUD = 0x6B,
      EV_LANDING_PAPER = 0x6C,
      EV_LANDING_PLASTER = 0x6D,
      EV_LANDING_ROCK = 0x6E,
      EV_LANDING_SAND = 0x6F,
      EV_LANDING_SNOW = 0x70,
      EV_LANDING_WATER = 0x71,
      EV_LANDING_WOOD = 0x72,
      EV_LANDING_ASPHALT = 0x73,
      EV_LANDING_PAIN_DEFAULT = 0x74,
      EV_LANDING_PAIN_BARK = 0x75,
      EV_LANDING_PAIN_BRICK = 0x76,
      EV_LANDING_PAIN_CARPET = 0x77,
      EV_LANDING_PAIN_CLOTH = 0x78,
      EV_LANDING_PAIN_CONCRETE = 0x79,
      EV_LANDING_PAIN_DIRT = 0x7A,
      EV_LANDING_PAIN_FLESH = 0x7B,
      EV_LANDING_PAIN_FOLIAGE = 0x7C,
      EV_LANDING_PAIN_GLASS = 0x7D,
      EV_LANDING_PAIN_GRASS = 0x7E,
      EV_LANDING_PAIN_GRAVEL = 0x7F,
      EV_LANDING_PAIN_ICE = 0x80,
      EV_LANDING_PAIN_METAL = 0x81,
      EV_LANDING_PAIN_MUD = 0x82,
      EV_LANDING_PAIN_PAPER = 0x83,
      EV_LANDING_PAIN_PLASTER = 0x84,
      EV_LANDING_PAIN_ROCK = 0x85,
      EV_LANDING_PAIN_SAND = 0x86,
      EV_LANDING_PAIN_SNOW = 0x87,
      EV_LANDING_PAIN_WATER = 0x88,
      EV_LANDING_PAIN_WOOD = 0x89,
      EV_LANDING_PAIN_ASPHALT = 0x8A,
      EV_FOLIAGE_SOUND = 0x8B,
      EV_STANCE_FORCE_STAND = 0x8C,
      EV_STANCE_FORCE_CROUCH = 0x8D,
      EV_STANCE_FORCE_PRONE = 0x8E,
      EV_STEP_VIEW = 0x8F,
      EV_ITEM_PICKUP = 0x90,
      EV_AMMO_PICKUP = 0x91,
      EV_NOAMMO = 0x92,
      EV_EMPTYCLIP = 0x93,
      EV_EMPTY_OFFHAND = 0x94,
      EV_RESET_ADS = 0x95,
      EV_RELOAD = 0x96,
      EV_RELOAD_FROM_EMPTY = 0x97,
      EV_RELOAD_START = 0x98,
      EV_RELOAD_END = 0x99,
      EV_RAISE_WEAPON = 0x9A,
      EV_PUTAWAY_WEAPON = 0x9B,
      EV_WEAPON_ALT = 0x9C,
      EV_PULLBACK_WEAPON = 0x9D,
      EV_FIRE_WEAPON = 0x9E,
      EV_FIRE_WEAPONB = 0x9F,
      EV_FIRE_WEAPON_LASTSHOT = 0xA0,
      EV_RECHAMBER_WEAPON = 0xA1,
      EV_EJECT_BRASS = 0xA2,
      EV_MELEE_SWIPE = 0xA3,
      EV_FIRE_MELEE = 0xA4,
      EV_PREP_OFFHAND = 0xA5,
      EV_USE_OFFHAND = 0xA6,
      EV_SWITCH_OFFHAND = 0xA7,
      EV_BINOCULAR_ENTER = 0xA8,
      EV_BINOCULAR_EXIT = 0xA9,
      EV_BINOCULAR_FIRE = 0xAA,
      EV_BINOCULAR_RELEASE = 0xAB,
      EV_BINOCULAR_DROP = 0xAC,
      EV_MELEE_HIT = 0xAD,
      EV_MELEE_MISS = 0xAE,
      EV_FIRE_WEAPON_MG42 = 0xAF,
      EV_FIRE_QUADBARREL_1 = 0xB0,
      EV_FIRE_QUADBARREL_2 = 0xB1,
      EV_BULLET_TRACER = 0xB2,
      EV_SOUND_ALIAS = 0xB3,
      EV_SOUND_ALIAS_AS_MASTER = 0xB4,
      EV_BULLET_HIT_SMALL = 0xB5,
      EV_BULLET_HIT_LARGE = 0xB6,
      EV_SHOTGUN_HIT = 0xB7,
      EV_BULLET_HIT_AP = 0xB8,
      EV_BULLET_HIT_CLIENT_SMALL = 0xB9,
      EV_BULLET_HIT_CLIENT_LARGE = 0xBA,
      EV_GRENADE_BOUNCE = 0xBB,
      EV_GRENADE_EXPLODE = 0xBC,
      EV_ROCKET_EXPLODE = 0xBD,
      EV_ROCKET_EXPLODE_NOMARKS = 0xBE,
      EV_CUSTOM_EXPLODE = 0xBF,
      EV_CUSTOM_EXPLODE_NOMARKS = 0xC0,
      EV_BULLET = 0xC1,
      EV_PLAY_FX = 0xC2,
      EV_PLAY_FX_ON_TAG = 0xC3,
      EV_EARTHQUAKE = 0xC4,
      EV_GRENADE_SUICIDE = 0xC5,
      EV_OBITUARY = 0xC6,
    } entity_event_t;

    enum scriptAnimEventTypes_t
    {
      ANIM_ET_PAIN = 0x0,
      ANIM_ET_DEATH = 0x1,
      ANIM_ET_FIREWEAPON = 0x2,
      ANIM_ET_JUMP = 0x3,
      ANIM_ET_JUMPBK = 0x4,
      ANIM_ET_LAND = 0x5,
      ANIM_ET_DROPWEAPON = 0x6,
      ANIM_ET_RAISEWEAPON = 0x7,
      ANIM_ET_CLIMB_MOUNT = 0x8,
      ANIM_ET_CLIMB_DISMOUNT = 0x9,
      ANIM_ET_RELOAD = 0xA,
      ANIM_ET_CROUCH_TO_PRONE = 0xB,
      ANIM_ET_PRONE_TO_CROUCH = 0xC,
      ANIM_ET_STAND_TO_CROUCH = 0xD,
      ANIM_ET_CROUCH_TO_STAND = 0xE,
      ANIM_ET_STAND_TO_PRONE = 0xF,
      ANIM_ET_PRONE_TO_STAND = 0x10,
      ANIM_ET_MELEEATTACK = 0x11,
      ANIM_ET_SHELLSHOCK = 0x12,
      NUM_ANIM_EVENTTYPES = 0x13,
    };

    enum StanceState
    {
      CL_STANCE_STAND = 0x0,
      CL_STANCE_CROUCH = 0x1,
      CL_STANCE_PRONE = 0x2,
      CL_STANCE_DIVE_TO_PRONE = 0x3,
    };

    typedef enum
    {
      TRACE_HITTYPE_NONE = 0x0,
      TRACE_HITTYPE_ENTITY = 0x1,
      TRACE_HITTYPE_DYNENT_MODEL = 0x2,
      TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
      TRACE_HITTYPE_GLASS = 0x4,
    } TraceHitType;

    typedef struct trace_s
    {
      float fraction;
      vec3_t normal;
      int surfaceFlags;
      int contents;
      const char *material;
      int entityNum;
      byte allsolid;
      byte startsolid;
      byte walkable;
      byte padding;
    } trace_t;

    typedef struct leakyBucket_s
    {
      netadrtype_t type;
      unsigned __int8 adr[4];
      int lastTime;
      signed __int8 burst;
      int hash;
      struct leakyBucket_s *prev;
      struct leakyBucket_s *next;
    } leakyBucket_t;

    typedef void netProfileInfo_t;

    typedef struct
    {
      int outgoingSequence;
      netsrc_t sock;
      int dropped;
      int incomingSequence;
      netadr_t remoteAddress;
      int qport;
      int fragmentSequence;
      int fragmentLength;
      byte fragmentBuffer[131072];
      int unsentFragments;
      int unsentFragmentStart;
      int unsentLength;
      byte unsentBuffer[131072];
      netProfileInfo_t *netProfile;
    } netchan_t;

    typedef struct
    {
      char command[1024];
      int cmdTime;
      int cmdType;
    } reliableCommands_t;

    typedef struct
    {
      netadr_t adr;
      int challenge;
      int time;
      int pingTime;
      int firstTime;
      int firstPing;
      int connected;
      int guid;
      char pbguid[64];
      int ipAuthorize;
    } challenge_t;

    typedef enum
    {
      STAT_HEALTH = 0x0,
      STAT_DEAD_YAW = 0x1,
      STAT_MAX_HEALTH = 0x2,
      STAT_FRIENDLY_LOOKAT_CLIENTNUM = 0x3,
      STAT_FRIENDLY_LOOKAT_HEALTH = 0x4,
      STAT_SPAWN_COUNT = 0x5,
    } statIndex_t;

    typedef struct
    {
      playerState_t ps;
      int num_entities;
      int num_clients;
      int first_entity;
      int first_client;
      unsigned int messageSent;
      unsigned int messageAcked;
      int messageSize;
    } clientSnapshot_t;

    #pragma pack(push, 1)
    typedef struct
    {
      char num;
      char data[256];
      int dataLen;
    } voices_t;
    #pragma pack(pop)

    typedef struct client_s
    {
      clientState_t state;
      int unksnapshotvar;
      int unksnapshotvar2;
      char userinfo[1024];
      reliableCommands_t reliableCommands[128];
      int reliableSequence;
      int reliableAcknowledge;
      int reliableSent;
      int messageAcknowledge;
      int gamestateMessageNum;
      int challenge;
      usercmd_t lastUsercmd;
      int lastClientCommand;
      char lastClientCommandString[1024];
      gentity_t *gentity;
      char name[32];
      char downloadName[64];
      fileHandle_t download;
      int downloadSize;
      int downloadCount;
      int downloadClientBlock;
      int downloadCurrentBlock;
      int downloadXmitBlock;
      unsigned __int8 *downloadBlocks[8];
      int downloadBlockSize[8];
      int downloadEOF;
      int downloadSendTime;
      char wwwDownloadURL[256];
      int wwwDownload;
      int wwwDownloadStarted;
      int wwwDlAck;
      int wwwDl_failed;
      int deltaMessage;
      int floodprotect;
      int lastPacketTime;
      int lastConnectTime;
      int nextSnapshotTime;
      int rateDelayed;
      int timeoutCount;
      clientSnapshot_t frames[32];
      int ping;
      int rate;
      int snapshotMsec;
      int pureAuthentic;
      netchan_t netchan;
      int guid;
      __int16 clscriptid;
      int bot;
      int serverId;
      voices_t voicedata[40];
      int unsentVoiceData;
      byte mutedClients[64];
      byte hasVoip;
      char pbguid[64];
    } client_t;

    typedef struct archivedSnapshot_s
    {
      int start;
      int size;
    } archivedSnapshot_t;

    typedef struct cachedClient_s
    {
      int playerStateExists;
      clientState_t *cs;
      playerState_t *ps;
    } cachedClient_t;

    typedef struct
    {
      int initialized;
      int time;
      int snapFlagServerBit;
      client_t *clients;
      int numSnapshotEntities;
      int numSnapshotClients;
      int nextSnapshotEntities;
      int nextSnapshotClients;
      entityState_t *snapshotEntities;
      clientState_t *snapshotClients;
      int archivedSnapshotEnabled;
      int nextArchivedSnapshotFrames;
      archivedSnapshot_t *archivedSnapshotFrames;
      int *archivedSnapshotBuffer;
      int nextArchivedSnapshotBuffer;
      int nextCachedSnapshotEntities;
      int nextCachedSnapshotClients;
      int nextCachedSnapshotFrames;
      cachedClient_t cachedSnapshotClients;
      int nextHeartbeatTime;
      int nextStatusResponseTime;
      challenge_t challenges[1024];
      netadr_t redirectAddress;
      netadr_t authorizeAddress;
      char netProfilingBuf[1504];
    } serverStatic_t;

    typedef struct
    {
      const char *key;
      const char *value;
    } keyValueStr_t;

    typedef struct
    {
      byte spawnVarsValid;
      int numSpawnVars;
      keyValueStr_t spawnVars[64];
      int numSpawnVarChars;
      char spawnVarChars[2048];
    } SpawnVar;

    typedef struct
    {
      unsigned __int16 entnum;
      unsigned __int16 otherEntnum;
      int useCount;
      int otherUseCount;
    } trigger_info_t;

    typedef struct __declspec(align(4))
    {
      struct gclient_s *clients;
      struct gentity_s *gentities;
      int gentitySize;
      int num_entities;
      struct gentity_s *firstFreeEnt;
      struct gentity_s *lastFreeEnt;
      fileHandle_t logFile;
      int initializing;
      int clientIsSpawning;
      objective_t objectives[16];
      int maxclients;
      int framenum;
      int time;
      int previousTime;
      int frameTime;
      int startTime;
      int teamScores[4];
      int lastTeammateHealthTime;
      int bUpdateScoresForIntermission;
      int manualNameChange;
      int numConnectedClients;
      int sortedClients[64];
      char voteString[1024];
      char voteDisplayString[1024];
      int voteTime;
      int voteExecuteTime;
      int voteYes;
      int voteNo;
      int numVotingClients;
      byte gap[2072];
      SpawnVar spawnVars;
      int savePersist;
      struct gentity_s *droppedWeaponCue[32];
      float fFogOpaqueDist;
      float fFogOpaqueDistSqrd;
      int remapCount;
      int currentPlayerClone;
      trigger_info_t pendingTriggerList[256];
      trigger_info_t currentTriggerList[256];
      int pendingTriggerListSize;
      int currentTriggerListSize;
      int finished;
      int bPlayerIgnoreRadiusDamage;
      int bPlayerIgnoreRadiusDamageLatched;
      int registerWeapons;
      int bRegisterItems;
      int currentEntityThink;
      void *openScriptIOFileHandles[1];
      char *openScriptIOFileBuffers[1];
      int field_3610;
      int field_3614;
      int field_3618;
      int field_361C;
      int field_3620;
    } level_locals_t;

    typedef enum
    {
      SS_DEAD = 0x0,
      SS_LOADING = 0x1,
      SS_GAME = 0x2,
    } serverState_t;

    typedef struct
    {
      int cluster;
      int area;
      int firstLeafBrush;
      int numLeafBrushes;
      int firstLeafSurface;
      int numLeafSurfaces;
    } cLeaf_t;

    typedef struct cmodel_s
    {
      vec3_t mins;
      vec3_t maxs;
      cLeaf_t leaf;
    } cmodel_t;

    typedef struct
    {
      int svFlags;
      int clientMask[2];
      vec3_t absmin;
      vec3_t absmax;
    } archivedEntityShared_t;

    typedef struct archivedEntity_s
    {
      entityState_t s;
      archivedEntityShared_t r;
    } archivedEntity_t;

    typedef struct svEntity_s
    {
      unsigned __int16 worldSector;
      unsigned __int16 nextEntityInWorldSector;
      archivedEntity_t baseline;
      int numClusters;
      int clusternums[16];
      int lastCluster;
      int linkcontents;
      float linkmin[2];
      float linkmax[2];
    } svEntity_t;

    typedef struct
    {
      serverState_t state;
      int restarting;
      int start_frameTime;
      int checksumFeed;
      int timeResidual;
      int unk;
      struct cmodel_s *models[256];
      char *configstrings[2048];
      svEntity_t svEntities[1024];
      char *entityParsePoint;
      gentity_t *gentities;
      int gentitySize;
      int num_entities;
      playerState_t *gameClients;
      int gameClientSize;
      int skelTimeStamp;
      int skelMemPos;
      int bpsWindow[20];
      int bpsWindowSteps;
      int bpsTotalBytes;
      int bpsMaxBytes;
      int ubpsWindow[20];
      int ubpsTotalBytes;
      int ubpsMaxBytes;
      float ucompAve;
      int ucompNum;
      char gametype[64];
    } server_t;

    enum weapType_t
    {
      WEAPTYPE_BULLET = 0x0,
      WEAPTYPE_GRENADE = 0x1,
      WEAPTYPE_PROJECTILE = 0x2,
      WEAPTYPE_BINOCULARS = 0x3,
      WEAPTYPE_NUM = 0x4,
    };

    enum weapClass_t
    {
      WEAPCLASS_RIFLE = 0x0,
      WEAPCLASS_MG = 0x1,
      WEAPCLASS_SMG = 0x2,
      WEAPCLASS_SPREAD = 0x3,
      WEAPCLASS_PISTOL = 0x4,
      WEAPCLASS_GRENADE = 0x5,
      WEAPCLASS_ROCKETLAUNCHER = 0x6,
      WEAPCLASS_TURRET = 0x7,
      WEAPCLASS_NON_PLAYER = 0x8,
      WEAPCLASS_ITEM = 0x9,
      WEAPCLASS_NUM = 0xA,
    };

    enum ImpactType_t
    {
      IMPACT_TYPE_NONE = 0x0,
      IMPACT_TYPE_BULLET_SMALL = 0x1,
      IMPACT_TYPE_BULLET_LARGE = 0x2,
      IMPACT_TYPE_BULLET_AP = 0x3,
      IMPACT_TYPE_SHOTGUN = 0x4,
      IMPACT_TYPE_GRENADE_BOUNCE = 0x5,
      IMPACT_TYPE_GRENADE_EXPLODE = 0x6,
      IMPACT_TYPE_ROCKET_EXPLODE = 0x7,
      IMPACT_TYPE_PROJECTILE_DUD = 0x8,
      IMPACT_TYPE_COUNT = 0x9,
    };

    enum weapInventoryType_t
    {
      WEAPINVENTORY_PRIMARY = 0x0,
      WEAPINVENTORY_OFFHAND = 0x1,
      WEAPINVENTORY_ITEM = 0x2,
      WEAPINVENTORY_ALTMODE = 0x3,
      WEAPINVENTORYCOUNT = 0x4,
    };

    enum OffhandClass_t
    {
      OFFHAND_CLASS_NONE = 0x0,
      OFFHAND_CLASS_FRAG_GRENADE = 0x1,
      OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
      OFFHAND_CLASS_COUNT = 0x3,
    };

    enum weapStance_t
    {
      WEAPSTANCE_STAND = 0x0,
      WEAPSTANCE_DUCK = 0x1,
      WEAPSTANCE_PRONE = 0x2,
      WEAPSTANCE_NUM = 0x3,
    };

    enum weapOverlayReticle_t
    {
      WEAPOVERLAYRETICLE_NONE = 0x0,
      WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
      WEAPOVERLAYRETICLE_NUM = 0x2,
    };

    enum weaponIconRatioType_t
    {
      WEAPON_ICON_RATIO_1TO1 = 0x0,
      WEAPON_ICON_RATIO_2TO1 = 0x1,
      WEAPON_ICON_RATIO_4TO1 = 0x2,
      WEAPON_ICON_RATIO_COUNT = 0x3,
    };

    enum weapProjExposion_t
    {
      WEAPPROJEXP_GRENADE = 0x0,
      WEAPPROJEXP_MOLOTOV = 0x1,
      WEAPPROJEXP_ROCKET = 0x2,
      WEAPPROJEXP_NONE = 0x3,
      WEAPPROJEXP_NUM = 0x4,
    };

    typedef const char FxEffectDef_t;

    typedef const char snd_alias_list_t;

    typedef const char Material_t;

    struct WeaponDef_t
    {
      const char *szInternalName;
      const char *szDisplayName;
      const char *szOverlayName;
      const char *szViewModelName;
      const char *szHandModelName;
      int unknown;
      const char *szXAnims[22];
      const char *szModeName;
      int playerAnimType;
      weapType_t weapType;
      weapClass_t weapClass;
      ImpactType_t impactType;
      weapInventoryType_t inventoryType;
      OffhandClass_t offhandClass;
      weapStance_t stance;
      FxEffectDef_t *viewFlashEffect;
      FxEffectDef_t *worldFlashEffect;
      snd_alias_list_t *pickupSound;
      snd_alias_list_t *ammoPickupSound;
      snd_alias_list_t *projectileSound;
      snd_alias_list_t *pullbackSound;
      snd_alias_list_t *fireSound;
      snd_alias_list_t *fireSoundPlayer;
      snd_alias_list_t *unknown4[4];
      snd_alias_list_t *fireLastSound;
      snd_alias_list_t *fireLastSoundPlayer;
      snd_alias_list_t *meleeSwipeSound;
      snd_alias_list_t *rechamberSound;
      snd_alias_list_t *rechamberSoundPlayer;
      snd_alias_list_t *reloadSound;
      snd_alias_list_t *reloadSoundPlayer;
      snd_alias_list_t *reloadEmptySound;
      snd_alias_list_t *reloadEmptySoundPlayer;
      snd_alias_list_t *reloadStartSound;
      snd_alias_list_t *reloadStartSoundPlayer;
      snd_alias_list_t *reloadEndSound;
      snd_alias_list_t *reloadEndSoundPlayer;
      snd_alias_list_t *altSwitchSound;
      snd_alias_list_t *raiseSound;
      snd_alias_list_t *putawaySound;
      snd_alias_list_t *noteTrackSoundA;
      snd_alias_list_t *noteTrackSoundB;
      snd_alias_list_t *noteTrackSoundC;
      snd_alias_list_t *noteTrackSoundD;
      FxEffectDef_t *shellEjectEffect;
      FxEffectDef_t *lastShotEjectEffect;
      Material_t *reticleCenter;
      Material_t *reticleSide;
      int iReticleCenterSize;
      int iReticleSideSize;
      int iReticleMinOfs;
      float vStandMove[3];
      float vStandRot[3];
      float vDuckedOfs[3];
      float vDuckedMove[3];
      float vDuckedRot[3];
      float vProneOfs[3];
      float vProneMove[3];
      float vProneRot[3];
      float fPosMoveRate;
      float fPosProneMoveRate;
      float fStandMoveMinSpeed;
      float fDuckedMoveMinSpeed;
      float fProneMoveMinSpeed;
      float fPosRotRate;
      float fPosProneRotRate;
      float fStandRotMinSpeed;
      float fDuckedRotMinSpeed;
      float fProneRotMinSpeed;
      const char *worldModel;
      Material_t *hudIcon;
      Material_t *modeIcon;
      int iStartAmmo;
      const char *szAmmoName;
      int iAmmoIndex;
      const char *szClipName;
      int iClipIndex;
      int iMaxAmmo;
      int iClipSize;
      int shotCount;
      const char *szSharedAmmoCapName;
      int iSharedAmmoCapIndex;
      int iSharedAmmoCap;
      int damage;
      int playerDamage;
      int iMeleeDamage;
      int iDamageType;
      int iFireDelay;
      int iMeleeDelay;
      int iFireTime;
      int iRechamberTime;
      int iRechamberBoltTime;
      int iHoldFireTime;
      int iMeleeTime;
      int iReloadTime;
      int iReloadEmptyTime;
      int iReloadAddTime;
      int iReloadStartTime;
      int iReloadStartAddTime;
      int iReloadEndTime;
      int iDropTime;
      int iRaiseTime;
      int iAltDropTime;
      int iAltRaiseTime;
      int quickDropTime;
      int quickRaiseTime;
      int fuseTime;
      float autoAimRange;
      float aimAssistRange;
      float aimAssistRangeAds;
      float aimPadding;
      float enemyCrosshairRange;
      int crosshairColorChange;
      float moveSpeedScale;
      float fAdsZoomFov;
      float fAdsZoomInFrac;
      float fAdsZoomOutFrac;
      Material_t *overlayMaterial;
      weapOverlayReticle_t overlayReticle;
      float overlayWidth;
      float overlayHeight;
      float fAdsBobFactor;
      float fAdsViewBobMult;
      float fHipSpreadStandMin;
      float fHipSpreadDuckedMin;
      float fHipSpreadProneMin;
      float hipSpreadStandMax;
      float hipSpreadDuckedMax;
      float hipSpreadProneMax;
      float fHipSpreadDecayRate;
      float fHipSpreadFireAdd;
      float fHipSpreadTurnAdd;
      float fHipSpreadMoveAdd;
      float fHipSpreadDuckedDecay;
      float fHipSpreadProneDecay;
      float fHipReticleSidePos;
      int iAdsTransInTime;
      int iAdsTransOutTime;
      float fAdsIdleAmount;
      float fHipIdleAmount;
      float adsIdleSpeed;
      float hipIdleSpeed;
      float fIdleCrouchFactor;
      float fIdleProneFactor;
      float fGunMaxPitch;
      float fGunMaxYaw;
      float swayMaxAngle;
      float swayLerpSpeed;
      float swayPitchScale;
      float swayYawScale;
      float swayHorizScale;
      float swayVertScale;
      float swayShellShockScale;
      float adsSwayMaxAngle;
      float adsSwayLerpSpeed;
      float adsSwayPitchScale;
      float adsSwayYawScale;
      float adsSwayHorizScale;
      float adsSwayVertScale;
      int bRifleBullet;
      int armorPiercing;
      int semiAuto;
      int bBoltAction;
      int aimDownSight;
      int bRechamberWhileAds;
      float adsViewErrorMin;
      float adsViewErrorMax;
      int bCookOffHold;
      int bClipOnly;
      int cancelAutoHolsterWhenEmpty;
      int suppressAmmoReserveDisplay;
      Material_t *killIcon;
      weaponIconRatioType_t killIconRatio;
      int flipKillIcon;
      int bNoPartialReload;
      int bSegmentedReload;
      int iReloadAmmoAdd;
      int iReloadStartAdd;
      const char *szAltWeaponName;
      unsigned int altWeaponIndex;
      int iDropAmmoMin;
      int iDropAmmoMax;
      int iExplosionRadius;
      int iExplosionInnerDamage;
      int iExplosionOuterDamage;
      int iProjectileSpeed;
      int iProjectileSpeedUp;
      const char *projectileModel;
      weapProjExposion_t projExplosion;
      FxEffectDef_t *projExplosionEffect;
      snd_alias_list_t *projExplosionSound;
      int bProjImpactExplode;
      float parallelBounce[23];
      float perpendicularBounce[23];
      FxEffectDef_t *projTrailEffect;
      int unknown2[4];
      float fAdsAimPitch;
      float fAdsCrosshairInFrac;
      float fAdsCrosshairOutFrac;
      int adsGunKickReducedKickBullets;
      float adsGunKickReducedKickPercent;
      float fAdsGunKickPitchMin;
      float fAdsGunKickPitchMax;
      float fAdsGunKickYawMin;
      float fAdsGunKickYawMax;
      float fAdsGunKickAccel;
      float fAdsGunKickSpeedMax;
      float fAdsGunKickSpeedDecay;
      float fAdsGunKickStaticDecay;
      float fAdsViewKickPitchMin;
      float fAdsViewKickPitchMax;
      float fAdsViewKickYawMin;
      float fAdsViewKickYawMax;
      float fAdsViewKickCenterSpeed;
      float fAdsViewScatterMin;
      float fAdsViewScatterMax;
      float fAdsSpread;
      int hipGunKickReducedKickBullets;
      float hipGunKickReducedKickPercent;
      float fHipGunKickPitchMin;
      float fHipGunKickPitchMax;
      float fHipGunKickYawMin;
      float fHipGunKickYawMax;
      float fHipGunKickAccel;
      float fHipGunKickSpeedMax;
      float fHipGunKickSpeedDecay;
      float fHipGunKickStaticDecay;
      float fHipViewKickPitchMin;
      float fHipViewKickPitchMax;
      float fHipViewKickYawMin;
      float fHipViewKickYawMax;
      float fHipViewKickCenterSpeed;
      float fHipViewScatterMin;
      float fHipViewScatterMax;
      float fightDist;
      float maxDist;
      const char *aiVsAiAccuracyGraph;
      const char *aiVsPlayerAccuracyGraph;
      int accuracyGraphKnotCount[2];
      int originalAccuracyGraphKnotCount[2];
      int iPositionReloadTransTime;
      float leftArc;
      float rightArc;
      float topArc;
      float bottomArc;
      float accuracy;
      float aiSpread;
      float playerSpread;
      int minVertTurnSpeed;
      int minHorTurnSpeed;
      int maxVertTurnSpeed;
      int maxHorTurnSpeed;
      float pitchConvergenceTime;
      float yawConvergenceTime;
      float suppressTime;
      float maxRange;
      float fAnimHorRotateInc;
      float fPlayerPositionDist;
      const char *szUseHintString;
      const char *dropHintString;
      int iUseHintStringIndex;
      int dropHintStringIndex;
      float horizViewJitter;
      float vertViewJitter;
      const char *szScript;
      float fOOPosAnimLength[2];
      int minDamage;
      int minPlayerDamage;
      float fMaxDamageRange;
      float fMinDamageRange;
      int unknown5[4];
      float locationDamageMultipliers[19];
      const char *fireRumble;
      const char *meleeImpactRumble;
    };

    typedef enum
    {
      ANIM_BP_UNUSED = 0x0,
      ANIM_BP_LEGS = 0x1,
      ANIM_BP_TORSO = 0x2,
      ANIM_BP_BOTH = 0x3,
      NUM_ANIM_BODYPARTS = 0x4,
    } animBodyPart_t;

    typedef enum
    {
      IT_BAD = 0x0,
      IT_WEAPON = 0x1,
      IT_AMMO = 0x2,
      IT_HEALTH = 0x3,
      IT_HOLDABLE = 0x4,
    } itemType_t;

    typedef struct gitem_s
    {
      char *classname;
      char *pickup_sound;
      char *world_model;
      int giTag;
      char *icon;
      char *display_name;
      int quantity;
      itemType_t giType;
      int giAmmoIndex;
      int giClipIndex;
      int giSharedAmmoCapIndex;
    } gitem_t;

    typedef struct XBoneInfo_s
    {
      float bounds[2][3];
      float offset[3];
      float radiusSquared;
    } XBoneInfo_t;

    typedef struct XModelCollSurf_s
    {
      float mins[3];
      float maxs[3];
      int boneIdx;
      int contents;
      int surfFlags;
    } XModelCollSurf_t;

    typedef struct XModelHighMipBounds_s
    {
      float mins[3];
      float maxs[3];
    } XModelHighMipBounds_t;

    typedef struct XModelStreamInfo_s
    {
      XModelHighMipBounds_t *highMipBounds;
    } XModelStreamInfo_t;

    typedef struct XModel_s
    {
      char numBones;
      char numRootBones;
      unsigned __int16 *boneNames;
      char *parentList;
      byte unk[72];
      XModelCollSurf_t *collSurfs;
      int numCollSurfs;
      int contents;
      XBoneInfo_t *boneInfo;
      vec3_t mins;
      vec3_t maxs;
      __int16 numLods;
      __int16 collLod;
      XModelStreamInfo_t streamInfo;
      int memUsage;
      const char *name;
      char flags;
      char bad;
    } XModel_t;

    typedef struct DObjSkeletonPartMatrix_s
    {
      float p1[4];
      float p2[4];
    } DObjSkeletonPartMatrix_t;

    typedef struct DSkelPartBits_s
    {
      int anim[4];
      int control[4];
      int skel[4];
    } DSkelPartBits_t;

    typedef struct DSkel_s
    {
      DSkelPartBits_t *partBits;
      int timeStamp;
      DObjSkeletonPartMatrix_t *mat;
    } DSkel_t;

    typedef struct DObj_s
    {
      int *tree;
      DSkel_t skel;
      unsigned __int16 duplicateParts;
      int unk2;
      byte numModels;
      byte numBones;
      byte duplicatePartsSize;
      byte pad;
      XModel_t *models;
    } DObj_t;

    struct pmove_t
    {
      struct playerState_s *ps;
      usercmd_t cmd;
      usercmd_t oldcmd;
      int tracemask;
      int numtouch;
      int touchents[32];
      vec3_t mins;
      vec3_t maxs;
      float xyspeed;
      int proneChange;
      byte mantleStarted;
      vec3_t mantleEndPos;
      int mantleDuration;
    };

    struct __declspec(align(4)) pml_t
    {
      vec3_t forward;
      vec3_t right;
      vec3_t up;
      float frametime;
      int msec;
      int walking;
      int groundPlane;
      int almostGroundPlane;
      trace_t groundTrace;
      float impactSpeed;
      vec3_t previous_origin;
      vec3_t previous_velocity;
      int field_78;
    };

    typedef struct
    {
      __int16 emptystring;
      __int16 allies;
      __int16 axis;
      __int16 current;
      __int16 damage;
      __int16 death;
      __int16 dlight;
      __int16 done;
      __int16 empty;
      __int16 entity;
      __int16 failed;
      __int16 fraction;
      __int16 goal;
      __int16 grenade;
      __int16 info_notnull;
      __int16 invisible;
      __int16 key1;
      __int16 key2;
      __int16 killanimscript;
      __int16 left;
      __int16 movedone;
      __int16 noclass;
      __int16 normal;
      __int16 pistol;
      __int16 plane_waypoint;
      __int16 player;
      __int16 position;
      __int16 primary;
      __int16 primaryb;
      __int16 prone;
      __int16 right;
      __int16 rocket;
      __int16 rotatedone;
      __int16 script_brushmodel;
      __int16 script_model;
      __int16 script_origin;
      __int16 spectator;
      __int16 stand;
      __int16 surfacetype;
      __int16 target_script_trigger;
      __int16 tempEntity;
      __int16 touch;
      __int16 trigger;
      __int16 trigger_use;
      __int16 trigger_use_touch;
      __int16 trigger_damage;
      __int16 trigger_lookat;
      __int16 truck_cam;
      __int16 worldspawn;
      __int16 binocular_enter;
      __int16 binocular_exit;
      __int16 binocular_fire;
      __int16 binocular_release;
      __int16 binocular_drop;
      __int16 begin;
      __int16 intermission;
      __int16 menuresponse;
      __int16 playing;
      __int16 none;
      __int16 dead;
      __int16 auto_change;
      __int16 manual_change;
      __int16 freelook;
      __int16 call_vote;
      __int16 vote;
      __int16 snd_enveffectsprio_level;
      __int16 snd_enveffectsprio_shellshock;
      __int16 snd_channelvolprio_holdbreath;
      __int16 snd_channelvolprio_pain;
      __int16 snd_channelvolprio_shellshock;
      __int16 tag_flash;
      __int16 tag_flash_11;
      __int16 tag_flash_2;
      __int16 tag_flash_22;
      __int16 tag_brass;
      __int16 j_head;
      __int16 tag_weapon;
      __int16 tag_player;
      __int16 tag_camera;
      __int16 tag_aim;
      __int16 tag_aim_animated;
      __int16 tag_origin;
      __int16 tag_butt;
      __int16 tag_weapon_right;
      __int16 back_low;
      __int16 back_mid;
      __int16 back_up;
      __int16 neck;
      __int16 head;
      __int16 pelvis;
    } stringIndex_t;

    struct __declspec(align(4)) bgs_s
    {
      byte animScriptData[736200];
      int multiplayer;
      int root;
      int torso;
      int legs;
      int turning;
      int turnAnimEndTime;
      int frametime;
      float angle;
      struct XModel *(__stdcall *GetXModel)(const char *);
      void (__stdcall *CreateDObj)(struct DObjModel_s *, unsigned __int16, struct XAnimTree_s *, int, int, struct clientInfo_t *);
      unsigned __int16 (__stdcall *AttachWeapon)(struct DObjModel_s *, unsigned __int16, struct clientInfo_t *);
      struct DObj_s *(__stdcall *GetDObj)(int, int);
      void *(__stdcall *AllocXAnim)(int);
      char field_B3BFC[4043];
      int field_B4BC8;
      int field_B4BCC;
      int field_B4BD0;
      int field_B4BD4;
      int field_B4BD8;
      int field_B4BDC;
      int field_B4BE0;
      int field_B4BE4;
      int field_B4BE8;
      int field_B4BEC;
      int field_B4BF0;
      int field_B4BF4;
      int field_B4BF8;
    };

    struct cg_t
    {
      char gap0[1001887];
      char field_F499F;
    };

    struct cgs_t
    {
      char gap0[174419];
      char field_2A953;
    };

    struct centity_s
    {
      char gap0[547];
      char field_223;
    };

    struct clientStatic_t
    {
      char gap0[3002367];
      char field_2DCFFF;
    };

    struct __declspec(align(4)) scrCompilePub_t
    {
      char gap_0[20];
      int bultinMeth;
      char gap_18[28];
      int func_table_size;
      int gap_38[1024];
    };
}
