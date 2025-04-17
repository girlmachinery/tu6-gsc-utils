#pragma once
#include "stdinclude.h"

namespace game
{
	enum VariableType
	{
		VAR_UNDEFINED = 0x0,
		VAR_BEGIN_REF = 0x1,
		VAR_POINTER = 0x1,
		VAR_STRING = 0x2,
		VAR_ISTRING = 0x3,
		VAR_VECTOR = 0x4,
		VAR_END_REF = 0x5,
		VAR_FLOAT = 0x5,
		VAR_INTEGER = 0x6,
		VAR_CODEPOS = 0x7,
		VAR_PRECODEPOS = 0x8,
		VAR_FUNCTION = 0x9,
		VAR_BUILTIN_FUNCTION = 0xA,
		VAR_BUILTIN_METHOD = 0xB,
		VAR_STACK = 0xC,
		VAR_ANIMATION = 0xD,
		VAR_PRE_ANIMATION = 0xE,
		VAR_THREAD = 0xF,
		VAR_NOTIFY_THREAD = 0x10,
		VAR_TIME_THREAD = 0x11,
		VAR_CHILD_THREAD = 0x12,
		VAR_OBJECT = 0x13,
		VAR_DEAD_ENTITY = 0x14,
		VAR_ENTITY = 0x15,
		VAR_ARRAY = 0x16,
		VAR_DEAD_THREAD = 0x17,
		VAR_COUNT = 0x18,
		VAR_FREE = 0x18,
		VAR_THREAD_LIST = 0x19,
		VAR_ENDON_LIST = 0x1A,
		VAR_TOTAL_COUNT = 0x1B,
	};

	//typedef void Font_s;
	typedef void SessionData;

	struct Font_s
	{
		const char *fontName;
		// int pixelHeight;
		// int glyphCount;
		// Material *material;
		// Material *glowMaterial;
		// Glyph *glyphs;
	};


	#define FONT_SMALL_DEV		"fonts/smallDevFont"
	#define FONT_BIG_DEV		"fonts/bigDevFont"
	#define FONT_CONSOLE		"fonts/consoleFont"
	#define FONT_BIG			"fonts/bigFont"
	#define FONT_SMALL			"fonts/smallFont"
	#define FONT_BOLD			"fonts/boldFont"
	#define FONT_NORMAL			"fonts/normalFont"
	#define FONT_OBJECTIVE		"fonts/objectiveFont"

	#define FLT_MIN          1.175494351e-38F
	#define FLT_MAX          3.402823466e+38F
	#define SCREEN_WIDTH 1280;
	#define SCREEN_HEIGHT 720;

	struct StringTableCell
	{
	  const char *string;
	  int hash;
	};

	/* 8937 */
	struct StringTable
	{
	  const char *name;
	  int columnCount;
	  int rowCount;
	  StringTableCell *values;
	};

	enum GamePadStick : __int32
	{
		GPAD_INVALID = 0x0,
		GPAD_LX = 0x40000000,
		GPAD_LY = 0x40000001,
		GPAD_RX = 0x40000002,
		GPAD_RY = 0x40000003,
	};

	enum keyNum_t : __int32
	{
	  K_NONE = 0x0,
	  K_FIRSTGAMEPADBUTTON_RANGE_1 = 0x1,
	  K_BUTTON_A = 0x1,
	  K_BUTTON_B = 0x2,
	  K_BUTTON_X = 0x3,
	  K_BUTTON_Y = 0x4,
	  K_BUTTON_LSHLDR = 0x5,
	  K_BUTTON_RSHLDR = 0x6,
	  K_LASTGAMEPADBUTTON_RANGE_1 = 0x6,
	  K_TAB = 0x9,
	  K_ENTER = 0xD,
	  K_FIRSTGAMEPADBUTTON_RANGE_2 = 0xE,
	  K_BUTTON_START = 0xE,
	  K_BUTTON_BACK = 0xF,
	  K_BUTTON_LSTICK = 0x10,
	  K_BUTTON_RSTICK = 0x11,
	  K_BUTTON_LTRIG = 0x12,
	  K_BUTTON_RTRIG = 0x13,
	  K_DPAD_UP = 0x14,
	  K_FIRSTDPAD = 0x14,
	  K_DPAD_DOWN = 0x15,
	  K_DPAD_LEFT = 0x16,
	  K_DPAD_RIGHT = 0x17,
	  K_BUTTON_LSTICK_ALTIMAGE = 0xBC,
	  K_BUTTON_RSTICK_ALTIMAGE = 0xBD,
	  K_LASTDPAD = 0x17,
	  K_LASTGAMEPADBUTTON_RANGE_2 = 0x17,
	  K_ESCAPE = 0x1B,
	  K_FIRSTGAMEPADBUTTON_RANGE_3 = 0x1C,
	  K_APAD_UP = 0x1C,
	  K_FIRSTAPAD = 0x1C,
	  K_APAD_DOWN = 0x1D,
	  K_APAD_LEFT = 0x1E,
	  K_APAD_RIGHT = 0x1F,
	  K_LASTAPAD = 0x1F,
	  K_LASTGAMEPADBUTTON_RANGE_3 = 0x1F,
	  K_SPACE = 0x20,
	  K_BACKSPACE = 0x7F,
	  K_ASCII_FIRST = 0x80,
	  K_ASCII_181 = 0x80,
	  K_ASCII_191 = 0x81,
	  K_ASCII_223 = 0x82,
	  K_ASCII_224 = 0x83,
	  K_ASCII_225 = 0x84,
	  K_ASCII_228 = 0x85,
	  K_ASCII_229 = 0x86,
	  K_ASCII_230 = 0x87,
	  K_ASCII_231 = 0x88,
	  K_ASCII_232 = 0x89,
	  K_ASCII_233 = 0x8A,
	  K_ASCII_236 = 0x8B,
	  K_ASCII_241 = 0x8C,
	  K_ASCII_242 = 0x8D,
	  K_ASCII_243 = 0x8E,
	  K_ASCII_246 = 0x8F,
	  K_ASCII_248 = 0x90,
	  K_ASCII_249 = 0x91,
	  K_ASCII_250 = 0x92,
	  K_ASCII_252 = 0x93,
	  K_END_ASCII_CHARS = 0x94,
	  K_COMMAND = 0x96,
	  K_CAPSLOCK = 0x97,
	  K_POWER = 0x98,
	  K_PAUSE = 0x99,
	  K_UPARROW = 0x9A,
	  K_DOWNARROW = 0x9B,
	  K_LEFTARROW = 0x9C,
	  K_RIGHTARROW = 0x9D,
	  K_ALT = 0x9E,
	  K_CTRL = 0x9F,
	  K_SHIFT = 0xA0,
	  K_INS = 0xA1,
	  K_DEL = 0xA2,
	  K_PGDN = 0xA3,
	  K_PGUP = 0xA4,
	  K_HOME = 0xA5,
	  K_END = 0xA6,
	  K_F1 = 0xA7,
	  K_F2 = 0xA8,
	  K_F3 = 0xA9,
	  K_F4 = 0xAA,
	  K_F5 = 0xAB,
	  K_F6 = 0xAC,
	  K_F7 = 0xAD,
	  K_F8 = 0xAE,
	  K_F9 = 0xAF,
	  K_F10 = 0xB0,
	  K_F11 = 0xB1,
	  K_F12 = 0xB2,
	  K_F13 = 0xB3,
	  K_F14 = 0xB4,
	  K_F15 = 0xB5,
	  K_KP_HOME = 0xB6,
	  K_KP_UPARROW = 0xB7,
	  K_KP_PGUP = 0xB8,
	  K_KP_LEFTARROW = 0xB9,
	  K_KP_5 = 0xBA,
	  K_KP_RIGHTARROW = 0xBB,
	  K_KP_END = 0xBC,
	  K_KP_DOWNARROW = 0xBD,
	  K_KP_PGDN = 0xBE,
	  K_KP_ENTER = 0xBF,
	  K_KP_INS = 0xC0,
	  K_KP_DEL = 0xC1,
	  K_KP_SLASH = 0xC2,
	  K_KP_MINUS = 0xC3,
	  K_KP_PLUS = 0xC4,
	  K_KP_NUMLOCK = 0xC5,
	  K_KP_STAR = 0xC6,
	  K_KP_EQUALS = 0xC7,
	  K_MOUSE1 = 0xC8,
	  K_MOUSE2 = 0xC9,
	  K_MOUSE3 = 0xCA,
	  K_MOUSE4 = 0xCB,
	  K_MOUSE5 = 0xCC,
	  K_MWHEELDOWN = 0xCD,
	  K_MWHEELUP = 0xCE,
	  K_AUX1 = 0xCF,
	  K_AUX2 = 0xD0,
	  K_AUX3 = 0xD1,
	  K_AUX4 = 0xD2,
	  K_AUX5 = 0xD3,
	  K_AUX6 = 0xD4,
	  K_AUX7 = 0xD5,
	  K_AUX8 = 0xD6,
	  K_AUX9 = 0xD7,
	  K_AUX10 = 0xD8,
	  K_AUX11 = 0xD9,
	  K_AUX12 = 0xDA,
	  K_AUX13 = 0xDB,
	  K_AUX14 = 0xDC,
	  K_AUX15 = 0xDD,
	  K_AUX16 = 0xDE,
	  K_LAST_KEY = 0xDF,
	};


	enum CompassType : __int32
	{
		COMPASS_TYPE_PARTIAL = 0x0,
		COMPASS_TYPE_FULL = 0x1,
	};

	struct scr_entref_t {
		unsigned short entnum;
		unsigned short classnum;
	};

	typedef enum
	{
		VISIONSET_NORMAL,
		VISIONSET_NIGHT,
		VISIONSET_MISSILECAM,
		VISIONSET_THERMAL,
		VISIONSET_PAIN,
		VISIONSETCOUNT
	} visionSetMode_t;

	struct VariableStackBuffer
	{
		const char* pos;
		unsigned __int16 size;
		unsigned __int16 bufLen;
		unsigned __int16 localId;
		unsigned __int8 time;
		char buf[1];
	};

	/* 9820 */
	struct field_t
	{
		int cursor;
		int scroll;
		int drawWidth;
		int widthInPixels;
		float charHeight;
		int fixedSize;
		char buffer[256];
	};

	enum meansOfDeath_t : __int32
	{
		MOD_UNKNOWN = 0x0,
		MOD_PISTOL_BULLET = 0x1,
		MOD_RIFLE_BULLET = 0x2,
		MOD_EXPLOSIVE_BULLET = 0x3,
		MOD_GRENADE = 0x4,
		MOD_GRENADE_SPLASH = 0x5,
		MOD_PROJECTILE = 0x6,
		MOD_PROJECTILE_SPLASH = 0x7,
		MOD_MELEE = 0x8,
		MOD_HEAD_SHOT = 0x9,
		MOD_CRUSH = 0xA,
		MOD_FALLING = 0xB,
		MOD_SUICIDE = 0xC,
		MOD_TRIGGER_HURT = 0xD,
		MOD_EXPLOSIVE = 0xE,
		MOD_IMPACT = 0xF,
		MOD_NUM = 0x10,
	};


	enum hitLocation_t : __int32
	{
		HITLOC_NONE = 0x0,
		HITLOC_HELMET = 0x1,
		HITLOC_HEAD = 0x2,
		HITLOC_NECK = 0x3,
		HITLOC_TORSO_UPR = 0x4,
		HITLOC_TORSO_LWR = 0x5,
		HITLOC_R_ARM_UPR = 0x6,
		HITLOC_L_ARM_UPR = 0x7,
		HITLOC_R_ARM_LWR = 0x8,
		HITLOC_L_ARM_LWR = 0x9,
		HITLOC_R_HAND = 0xA,
		HITLOC_L_HAND = 0xB,
		HITLOC_R_LEG_UPR = 0xC,
		HITLOC_L_LEG_UPR = 0xD,
		HITLOC_R_LEG_LWR = 0xE,
		HITLOC_L_LEG_LWR = 0xF,
		HITLOC_R_FOOT = 0x10,
		HITLOC_L_FOOT = 0x11,
		HITLOC_GUN = 0x12,
		HITLOC_SHIELD = 0x13,
		HITLOC_NUM = 0x14,
	};

	enum LocSelInputState : __int32
	{
		LOC_SEL_INPUT_NONE = 0x0,
		LOC_SEL_INPUT_CONFIRM = 0x1,
		LOC_SEL_INPUT_CANCEL = 0x2,
	};

	struct KeyState
	{
		int down;
		int repeats;
		const char* binding;
	};

	/* 10223 */
	struct PlayerKeyState
	{
		field_t chatField;
		int chat_team;
		int overstrikeMode;
		int anyKeyDown;
		KeyState keys[256];
		LocSelInputState locSelInputState;
	};

	struct Material
	{
		const char* name;
	};

	struct KerningPairs
	{
		unsigned __int16 wFirst;
		unsigned __int16 wSecond;
		int iKernAmount;
	};

	struct Glyph
	{
		unsigned __int16 letter;
		char x0;
		char y0;
		char dx;
		char pixelWidth;
		char pixelHeight;
		float s0;
		float t0;
		float s1;
		float t1;
	};

	struct Font
	{
		const char* fontName;
		int pixelHeight;
		int isScalingAllowed;
		int glyphCount;
		int kerningPairsCount;
		Material* material;
		Material* glowMaterial;
		Glyph* glyphs;
		KerningPairs* kerningPairs;
	};
	struct Cursor
	{
		float x;
		float y;
	};

	struct UiContext
	{
		int localClientNum;
		float bias;
		int realTime;
		int frameTime;
		Cursor cursor;
		int isCursorVisible;
		int paintFull;
		int screenWidth;
		int screenHeight;
		float screenAspect;
		float FPS;
		float blurRadiusOut;

	};

	typedef struct ScreenPlacement_t {
		float scaleVirtualToReal[2];
		float scaleVirtualToFull[2];
		float scaleRealToVirtual[2];
		float realViewportPosition[2];
		float realViewportSize[2];
		float virtualViewableMin[2];
		float virtualViewableMax[2];
		float realViewableMin[2];
		float realViewableMax[2];
		float virtualAdjustableMin[2];
		float virtualAdjustableMax[2];
		float realAdjustableMin[2];
		float realAdjustableMax[2];
		float subScreenLeft;
	} ScreenPlacement;

	/* 9453 */
	union VariableUnion
	{
		int int_value;
		float float_value;
		unsigned int string_value;
		const float* vectorValue;
		const char* codePosValue;
		unsigned int pointerValue;
		VariableStackBuffer* stackValue;
		unsigned int entityOffset;
	};

	/* 9454 */
	struct VariableValue
	{
		VariableUnion u;
		int type;
	};

	enum team_t : __int32
	{
		TEAM_FREE = 0x0,
		TEAM_AXIS = 0x1,
		TEAM_ALLIES = 0x2,
		TEAM_SPECTATOR = 0x3,
		TEAM_NUM_TEAMS = 0x4,
	};

	enum clientConnected_t : __int32
	{
		CON_DISCONNECTED = 0x0,
		CON_CONNECTING = 0x1,
		CON_CONNECTED = 0x2,
	};

	/* 767 */
	enum sessionState_t : __int32
	{
		SESS_STATE_PLAYING = 0x0,
		SESS_STATE_DEAD = 0x1,
		SESS_STATE_SPECTATOR = 0x2,
		SESS_STATE_INTERMISSION = 0x3,
	};

	enum hintType_t : __int32
	{
		HINT_NONE = 0x0,
		HINT_NOICON = 0x1,
		HINT_ACTIVATE = 0x2,
		HINT_HEALTH = 0x3,
		HINT_FRIENDLY = 0x4,
		FIRST_WEAPON_HINT = 0x5,
		LAST_WEAPON_HINT = 0x4B4,
		HINT_NUM_HINTS = 0x4B5,
	};

	enum svscmd_type : __int32
	{
		SV_CMD_CAN_IGNORE = 0x0,
		SV_CMD_RELIABLE = 0x1,
	};

	enum DvarType {
		Dvar_Bool = 0x00,
		Dvar_Float = 0x01,
		Dvar_Vec2 = 0x02,
		Dvar_Vec3 = 0x03,
		Dvar_Vec4 = 0x04,
		Dvar_Int = 0x05,
		Dvar_Enum = 0x06,
		Dvar_String = 0x07,
		Dvar_Color = 0x08,
		Dvar_DevTweak = 0x09
	};

	enum DynEntityType : __int32
	{
		DYNENT_TYPE_INVALID = 0x0,
		DYNENT_TYPE_CLUTTER = 0x1,
		DYNENT_TYPE_DESTRUCT = 0x2,
		DYNENT_TYPE_COUNT = 0x3,
	};

	enum DvarSetSource {
		DVAR_SOURCE_INTERNAL = 0x0,
		DVAR_SOURCE_EXTERNAL = 0x1,
		DVAR_SOURCE_SCRIPT = 0x2
	};

	union DvarLimits {
		struct enumeration {
			int stringCount;
			char** strings;
		};

		struct integer {
			int min;
			int max;
		};

		struct decimal {
			float min;
			float max;
		};
	};

	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		float value;
		float vector[4];
		const char *string;
		unsigned __int8 color[4];
	};

	struct dvar_t
	{
		const char *name;
		const char *description;
		unsigned __int16 flags;
		unsigned __int8 type;
		bool modified;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarLimits domain;
		dvar_t *hashNext;
	};

	typedef void(*BuiltinFunction)();
	typedef void(*BuiltinMethod)(scr_entref_t);

	struct BuiltinMethodDef
	{
		const char* actionString;
		BuiltinMethod actionFunc;
		int type;
	};
	struct BuiltinFunctionDef
	{
		const char* actionString;
		BuiltinFunction actionFunc;
		int type;
	};

	//POTENTIALLY BAD

	struct rectDef_s
	{
		float x;
		float y;
		float w;
		float h;
		unsigned __int8 horzAlign;
		unsigned __int8 vertAlign;
	};

	union GfxTexture
	{
		D3DBaseTexture basemap;
		D3DTexture map;
		D3DVolumeTexture volmap;
		D3DCubeTexture cubemap;
	};

	struct CardMemory
	{
		int platform[1];
	};

	struct GfxImage 
	{
		GfxTexture texture;
		char unknown[4];
		char mapType;
		char semantic;
		char category;
		char flags;
		CardMemory cardMemory;
		unsigned __int16 width;
		unsigned __int16 height;
		unsigned __int16 depth;
		char mipmap;
		bool streaming;
		unsigned char* pixels;
		char unknownData[0x20];
		const char* name;
	};

	struct StreamFile
	{
		char type;
		char pad[3];
		const char* folder;
		const char* file;
	};

	struct snd_alias_t
	{
		char pad[20];
		StreamFile* stream;
		char pad2[76];
	};

	struct snd_alias_list_t
	{
		const char* name;
		snd_alias_t* aliases;
		int numAliases;
	};

	union snd_alias_list_name
	{
		char* name;
		snd_alias_list_t* asset;
	};

	struct Bounds
	{
		float midPoint[3];
		float halfSize[3];
	};

	struct DObjAnimMat
	{
		float quat[4];
		float trans[3];
		float transWeight;
	};

	struct __declspec(align(4)) PhysPreset
	{
		const char* name;
		int type;
		float mass;
		float bounce;
		float friction;
		float bulletForceScale;
		float explosiveForceScale;
		const char* sndAliasPrefix;
		float piecesSpreadFraction;
		float piecesUpwardVelocity;
		bool tempDefaultToCylinder;
		bool perSurfaceSndAlias;
	};

	struct cplane_s
	{
		float normal[3];
		float dist;
		char type;
		char pad[3];
	};

	struct cbrushside_t
	{
		cplane_s* plane;
		unsigned __int16 materialNum;
		char firstAdjacentSideOffset;
		char edgeCount;
	};

	struct cbrush_t
	{
		unsigned __int16 numsides;
		unsigned __int16 glassPieceIndex;
		cbrushside_t* sides;
		char* baseAdjacentSide;
		__int16 axialMaterialNum[2][3];
		char firstAdjacentSideOffsets[2][3];
		char edgeCount[2][3];
	};

	struct BrushWrapper
	{
		Bounds bounds;
		cbrush_t brush;
		int totalEdgeCount;
		cplane_s* planes;
	};

	struct PhysGeomInfo
	{
		BrushWrapper* brushWrapper;
		int type;
		float orientation[3][3];
		Bounds bounds;
	};

	struct PhysMass
	{
		float centerOfMass[3];
		float momentsOfInertia[3];
		float productsOfInertia[3];
	};

	struct PhysCollmap
	{
		const char* name;
		unsigned int count;
		PhysGeomInfo* geoms;
		PhysMass mass;
		Bounds bounds;
	};

	union XAnimIndices
	{
		char* _1;
		unsigned __int16* _2;
		void* data;
	};

	struct XAnimNotifyInfo
	{
		unsigned __int16 name;
		float time;
	};

	union XAnimDynamicFrames
	{
		char(*_1)[3];
		unsigned __int16(*_2)[3];
	};

	union XAnimDynamicIndices
	{
		char _1[1];
		unsigned __int16 _2[1];
	};

	struct __declspec(align(4)) XAnimPartTransFrames
	{
		float mins[3];
		float size[3];
		XAnimDynamicFrames frames;
		XAnimDynamicIndices indices;
	};

	union XAnimPartTransData
	{
		XAnimPartTransFrames frames;
		float frame0[3];
	};

	struct XAnimPartTrans
	{
		unsigned __int16 size;
		char smallTrans;
		XAnimPartTransData u;
	};

	struct __declspec(align(4)) XAnimDeltaPartQuatDataFrames2
	{
		__int16(*frames)[2];
		XAnimDynamicIndices indices;
	};

	union XAnimDeltaPartQuatData2
	{
		XAnimDeltaPartQuatDataFrames2 frames;
		__int16 frame0[2];
	};

	struct XAnimDeltaPartQuat2
	{
		unsigned __int16 size;
		XAnimDeltaPartQuatData2 u;
	};

	struct __declspec(align(4)) XAnimDeltaPartQuatDataFrames
	{
		__int16(*frames)[4];
		XAnimDynamicIndices indices;
	};

	union XAnimDeltaPartQuatData
	{
		XAnimDeltaPartQuatDataFrames frames;
		__int16 frame0[4];
	};

	struct XAnimDeltaPartQuat
	{
		unsigned __int16 size;
		XAnimDeltaPartQuatData u;
	};

	struct XAnimDeltaPart
	{
		XAnimPartTrans* trans;
		XAnimDeltaPartQuat2* quat2;
		XAnimDeltaPartQuat* quat;
	};

	struct XAnimParts
	{
		const char* name;
		unsigned __int16 dataByteCount;
		unsigned __int16 dataShortCount;
		unsigned __int16 dataIntCount;
		unsigned __int16 randomDataByteCount;
		unsigned __int16 randomDataIntCount;
		unsigned __int16 numframes;
		char flags;
		char boneCount[10];
		char notifyCount;
		char assetType;
		bool isDefault;
		unsigned int randomDataShortCount;
		unsigned int indexCount;
		float framerate;
		float frequency;
		unsigned __int16* names;
		char* dataByte;
		__int16* dataShort;
		int* dataInt;
		__int16* randomDataShort;
		char* randomDataByte;
		int* randomDataInt;
		XAnimIndices indices;
		XAnimNotifyInfo* notify;
		XAnimDeltaPart* deltaPart;
	};

	struct XModelAngle
	{
		short x;
		short y;
		short z;
		short base;
	};

	struct XModelTagPos
	{
		float x;
		float y;
		float z;
	};

	struct XSurface
	{
		short pad;
		short numVertices;
		short numPrimitives;
		unsigned char streamHandle;
		char pad2;
		int pad3;
		void* indexBuffer;
		char pad4[12];
		void* vertexBuffer;
		char pad5[32];
	};

	struct XModelSurfs
	{
		const char* name;
		XSurface* surfaces;
		int numSurfaces;
		char pad[24];
	};

	struct XSurfaceLod
	{
		char pad[8];
		XModelSurfs* surfaces;
		char pad2[32];
	};

	struct XModelLodInfo
	{
		float dist;
		unsigned __int16 numsurfs;
		unsigned __int16 surfIndex;
		XModelSurfs* modelSurfs;
		int partBits[6];
		XSurface* surfs;
		char lod;
		char smcBaseIndexPlusOne;
		char smcSubIndexMask;
		char smcBucket;
	};

	struct XModelCollTri_s
	{
		float plane[4];
		float svec[4];
		float tvec[4];
	};

	struct XModelCollSurf_s
	{
		XModelCollTri_s* collTris;
		int numCollTris;
		Bounds bounds;
		int boneIdx;
		int contents;
		int surfFlags;
	};

	struct XBoneInfo
	{
		Bounds bounds;
		float radiusSquared;
	};

	struct XModel
	{
		const char* name;
		unsigned char numBones;
		unsigned char numRootBones;
		unsigned char numsurfs;
		unsigned char lodRampType;
		float scale;
		unsigned int noScalePartBits[6];
		unsigned __int16* boneNames;
		unsigned char* parentList;
		short* quats;
		float* trans;
		unsigned char* partClassification;
		DObjAnimMat* baseMat;
		Material** materialHandles;
		XModelLodInfo lodInfo[4];
		unsigned char maxLoadedLod;
		unsigned char numLods;
		unsigned char collLod;
		unsigned char flags;
		XModelCollSurf_s* collSurfs;
		int numCollSurfs;
		int contents;
		XBoneInfo* boneInfo;
		float radius;
		Bounds bounds;
		int memUsage;
		bool bad;
		PhysPreset* physPreset;
		PhysCollmap* physCollmap;
	};

	struct Tracer
	{
		const char* name;
		Material* material;
		unsigned int drawInterval;
		float speed;
		float beamLength;
		float beamWidth;
		float screwRadius;
		float screwDist;
		float colors[5][4];
	};



	enum weapFireType_t : int
	{
		WEAPON_FIRETYPE_FULLAUTO = 0x0,
		WEAPON_FIRETYPE_SINGLESHOT = 0x1,
		WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
		WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
		WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
		WEAPON_FIRETYPE_DOUBLE_BARREL = 0x5,
		WEAPON_FIRETYPE_MAX
	};

	enum weapInventoryType_t : int
	{
		WEAPINVENTORY_PRIMARY = 0,
		WEAPINVENTORY_OFFHAND = 1,
		WEAPINVENTORY_ITEM = 2,
		WEAPINVENTORY_ALTMODE = 3,
		WEAPINVENTORY_EXCLUSIVE = 4,
		WEAPINVENTORY_SCAVENGER = 5,
		WEAPINVENTORY_MAX
	};

	enum PenetrateType
	{
		PENETRATE_TYPE_NONE = 0x0,
		PENETRATE_TYPE_SMALL = 0x1,
		PENETRATE_TYPE_MEDIUM = 0x2,
		PENETRATE_TYPE_LARGE = 0x3,
		PENETRATE_TYPE_COUNT = 0x4
	};

	enum activeReticleType_t : int
	{
		VEH_ACTIVE_RETICLE_NONE = 0,
		VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 1,
		VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 2,
		VEH_ACTIVE_RETICLE_MAX
	};

	enum weapType_t : int
	{
		WEAPTYPE_BULLET = 0,
		WEAPTYPE_GRENADE = 1,
		WEAPTYPE_PROJECTILE = 2,
		WEAPTYPE_RIOTSHIELD = 3,
		WEAPTYPE_MAX
	};

	enum playerAnimType_t : int
	{
		none = 0x0,
		other = 0x1,
		pistol = 0x2,
		smg = 0x3,
		autorifle = 0x4,
		mg = 0x5,
		sniper = 0x6,
		rocketlauncher = 0x7,
		plosive = 0x8,
		grenade = 0x9,
		turret = 0xA,
		c4 = 0xB,
		m203 = 0xC,
		hold = 0xD,
		briefcase = 0xE,
		riotshield = 0xF,
		laptop = 0x10,
		throwingknife = 0x11
	};

	enum weapProjExplosion_t
	{
		WEAPPROJEXP_GRENADE = 0x0,
		WEAPPROJEXP_ROCKET = 0x1,
		WEAPPROJEXP_FLASHBANG = 0x2,
		WEAPPROJEXP_NONE = 0x3,
		WEAPPROJEXP_DUD = 0x4,
		WEAPPROJEXP_SMOKE = 0x5,
		WEAPPROJEXP_HEAVY = 0x6,
		WEAPPROJEXP_NUM = 0x7
	};

	enum WeapStickinessType
	{
		WEAPSTICKINESS_NONE = 0x0,
		WEAPSTICKINESS_ALL = 0x1,
		WEAPSTICKINESS_ALL_ORIENT = 0x2,
		WEAPSTICKINESS_GROUND = 0x3,
		WEAPSTICKINESS_GROUND_WITH_YAW = 0x4,
		WEAPSTICKINESS_KNIFE = 0x5,
		WEAPSTICKINESS_COUNT = 0x6
	};

	enum weaponIconRatioType_t
	{
		WEAPON_ICON_RATIO_1TO1 = 0x0,
		WEAPON_ICON_RATIO_2TO1 = 0x1,
		WEAPON_ICON_RATIO_4TO1 = 0x2,
		WEAPON_ICON_RATIO_COUNT = 0x3
	};

	enum ammoCounterClipType_t
	{
		AMMO_COUNTER_CLIP_NONE = 0x0,
		AMMO_COUNTER_CLIP_MAGAZINE = 0x1,
		AMMO_COUNTER_CLIP_SHORTMAGAZINE = 0x2,
		AMMO_COUNTER_CLIP_SHOTGUN = 0x3,
		AMMO_COUNTER_CLIP_ROCKET = 0x4,
		AMMO_COUNTER_CLIP_BELTFED = 0x5,
		AMMO_COUNTER_CLIP_ALTWEAPON = 0x6,
		AMMO_COUNTER_CLIP_COUNT = 0x7
	};

	enum weapOverlayReticle_t
	{
		WEAPOVERLAYRETICLE_NONE = 0x0,
		WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
		WEAPOVERLAYRETICLE_NUM = 0x2
	};

	enum WeapOverlayInterface_t
	{
		WEAPOVERLAYINTERFACE_NONE = 0x0,
		WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
		WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
		WEAPOVERLAYINTERFACECOUNT = 0x3
	};

	enum weapClass_t : __int32
	{
		WEAPCLASS_RIFLE = 0x0,
		WEAPCLASS_SNIPER = 0x1,
		WEAPCLASS_MG = 0x2,
		WEAPCLASS_SMG = 0x3,
		WEAPCLASS_SPREAD = 0x4,
		WEAPCLASS_PISTOL = 0x5,
		WEAPCLASS_GRENADE = 0x6,
		WEAPCLASS_ROCKETLAUNCHER = 0x7,
		WEAPCLASS_TURRET = 0x8,
		WEAPCLASS_THROWINGKNIFE = 0x9,
		WEAPCLASS_NON_PLAYER = 0xA,
		WEAPCLASS_ITEM = 0xB,
		WEAPCLASS_NUM = 0xC,
	};

	enum weapStance_t
	{
		WEAPSTANCE_STAND = 0x0,
		WEAPSTANCE_DUCK = 0x1,
		WEAPSTANCE_PRONE = 0x2,
		WEAPSTANCE_NUM = 0x3
	};

	enum ImpactType
	{
		IMPACT_TYPE_NONE = 0,
		IMPACT_TYPE_BULLET_SMALL = 1,
		IMPACT_TYPE_BULLET_LARGE = 2,
		IMPACT_TYPE_BULLET_AP = 3,
		IMPACT_TYPE_SHOTGUN_FMJ = 4,
		IMPACT_TYPE_SHOTGUN = 5,
		IMPACT_TYPE_GRENADE_BOUNCE = 7,
		IMPACT_TYPE_GRENADE_EXPLODE = 8,
		IMPACT_TYPE_ROCKET_EXPLODE = 9,
		IMPACT_TYPE_PROJECTILE_DUD = 10,
		IMPACT_TYPE_MAX
	};

	enum usercmdButtonBits
	{
		CMD_BUTTON_ATTACK = 1 << 0,
		CMD_BUTTON_SPRINT = 1 << 1,
		CMD_BUTTON_MELEE = 1 << 2,
		CMD_BUTTON_ACTIVATE = 1 << 3,
		CMD_BUTTON_RELOAD = 1 << 4,
		CMD_BUTTON_USE_RELOAD = 1 << 5,
		CMD_BUTTON_LEAN_LEFT = 1 << 6,
		CMD_BUTTON_LEAN_RIGHT = 1 << 7,
		CMD_BUTTON_PRONE = 1 << 8,
		CMD_BUTTON_CROUCH = 1 << 9,
		CMD_BUTTON_UP = 1 << 10,
		CMD_BUTTON_ADS = 1 << 11,
		CMD_BUTTON_DOWN = 1 << 12,
		CMD_BUTTON_BREATH = 1 << 13,
		CMD_BUTTON_FRAG = 1 << 14,
		CMD_BUTTON_OFFHAND_SECONDARY = 1 << 15,
		CMD_BUTTON_THROW = 1 << 19,
	};

	enum guidedMissileType_t
	{
		MISSILE_GUIDANCE_NONE = 0x0,
		MISSILE_GUIDANCE_SIDEWINDER = 0x1,
		MISSILE_GUIDANCE_HELLFIRE = 0x2,
		MISSILE_GUIDANCE_JAVELIN = 0x3,
		MISSILE_GUIDANCE_MAX
	};

	enum surfaceNames_t
	{
		bark,
		brick,
		carpet,
		cloth,
		concrete,
		dirt,
		flesh,
		foliage,
		glass,
		grass,
		gravel,
		ice,
		metal,
		mud,
		paper,
		plaster,
		rock,
		sand,
		snow,
		water,
		wood,
		asphalt,
		ceramic,
		plastic,
		rubber,
		cushion,
		fruit,
		paintedmetal,
		Riotshield,
		slush,
		opaqueglass
	};

	typedef enum : int
	{
		PLAYER_OFFHAND_NONE = 0x0,
		PLAYER_OFFHAND_FRAG = 0x1,
		PLAYER_OFFHAND_SMOKE = 0x2,
		PLAYER_OFFHAND_FLASH = 0x3,
		PLAYER_OFFHAND_THROWINGKNIFE = 0x4,
		PLAYER_OFFHAND_OTHER = 0x5
	} OffhandClass;

	struct WeaponDef
	{
		char* szInternalName;
		XModel** gunXModel;
		XModel* handXModel;
		const char** szXAnimsR;
		const char** szXAnimsL;
		char* szModeName;
		int noteTrackSoundMap[2];
		int noteTrackRumbleMap[2];
		playerAnimType_t playerAnimType;
		weapType_t weaponType;
		weapClass_t weaponClass;
		PenetrateType penetrateType;
		weapInventoryType_t inventoryType;
		weapFireType_t fireType;
		OffhandClass offhandClass;
		weapStance_t stance;
		void* viewFlashEffect;
		void* worldFlashEffect;
		snd_alias_list_name pickUpSound;
		snd_alias_list_name pickUpSoundPlayer;
		snd_alias_list_name ammoPickupSound;
		snd_alias_list_name ammoPickupSoundPlayer;
		snd_alias_list_name projectileSound;
		snd_alias_list_name pullbackSound;
		snd_alias_list_name pullbackSoundPlayer;
		snd_alias_list_name fireSound;
		snd_alias_list_name fireSoundPlayer;
		snd_alias_list_name fireSoundPlayerAkimbo;
		snd_alias_list_name loopFireSound;
		snd_alias_list_name loopFireSoundPlayer;
		snd_alias_list_name stopFireSound;
		snd_alias_list_name stopFireSoundPlayer;
		snd_alias_list_name lastShotSound;
		snd_alias_list_name lastShotSoundPlayer;
		snd_alias_list_name emptyFireSound;
		snd_alias_list_name emptyFireSoundPlayer;
		snd_alias_list_name meleeSwipeSound;
		snd_alias_list_name meleeSwipeSoundPlayer;
		snd_alias_list_name meleeHitSound;
		snd_alias_list_name meleeMissSound;
		snd_alias_list_name rechamberSound;
		snd_alias_list_name rechamberSoundPlayer;
		snd_alias_list_name reloadSound;
		snd_alias_list_name reloadSoundPlayer;
		snd_alias_list_name reloadEmptySound;
		snd_alias_list_name reloadEmptySoundPlayer;
		snd_alias_list_name reloadStartSound;
		snd_alias_list_name reloadStartSoundPlayer;
		snd_alias_list_name reloadEndSound;
		snd_alias_list_name reloadEndSoundPlayer;
		snd_alias_list_name detonateSound;
		snd_alias_list_name detonateSoundPlayer;
		snd_alias_list_name nightVisionWearSound;
		snd_alias_list_name nightVisionWearSoundPlayer;
		snd_alias_list_name nightVisionRemoveSound;
		snd_alias_list_name nightVisionRemoveSoundPlayer;
		snd_alias_list_name altSwitchSound;
		snd_alias_list_name altSwitchSoundPlayer;
		snd_alias_list_name raiseSound;
		snd_alias_list_name raiseSoundPlayer;
		snd_alias_list_name firstRaiseSound;
		snd_alias_list_name firstRaiseSoundPlayer;
		snd_alias_list_name putawaySound;
		snd_alias_list_name putawaySoundPlayer;
		snd_alias_list_name scanSound;
		snd_alias_list_name* bounceSound;
		void* viewShellEjectEffect;
		void* worldShellEjectEffect;
		void* viewLastShotEjectEffect;
		void* worldLastShotEjectEffect;
		Material* reticleCenter;
		Material* reticleSide;
		int iReticleCenterSize;
		int iReticleSideSize;
		int iReticleMinOfs;
		activeReticleType_t activeReticleType;
		float vStandMove[3];
		float vStandRot[3];
		float vStrafeMove[3];
		float vStrafeRot[3];
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
		XModel** worldModel;
		XModel* worldClipModel;
		XModel* rocketModel;
		XModel* knifeModel;
		XModel* worldKnifeModel;
		Material* hudIcon;
		weaponIconRatioType_t hudIconRatio;
		Material* pickupIcon;
		weaponIconRatioType_t pickupIconRatio;
		Material* ammoCounterIcon;
		weaponIconRatioType_t ammoCounterIconRatio;
		ammoCounterClipType_t ammoCounterClip;
		int iStartAmmo;
		const char* szAmmoName;
		int iAmmoIndex;
		const char* szClipName;
		int iClipIndex;
		int iMaxAmmo;
		int shotCount;
		const char* szSharedAmmoCapName;
		int iSharedAmmoCapIndex;
		int iSharedAmmoCap;
		int damage;
		int playerDamage;
		int iMeleeDamage;
		int iDamageType;
		int iFireDelay;
		int iMeleeDelay;
		int meleeChargeDelay;
		int iDetonateDelay;
		int iRechamberTime;
		int iRechamberOneHanded;
		int iRechamberBoltTime;
		int iHoldFireTime;
		int iDetonateTime;
		int iMeleeTime;
		int meleeChargeTime;
		int iReloadTime;
		int reloadShowRocketTime;
		int iReloadEmptyTime;
		int iReloadAddTime;
		int iReloadStartTime;
		int iReloadStartAddTime;
		int iReloadEndTime;
		int iDropTime;
		int iRaiseTime;
		int iAltDropTime;
		int quickDropTime;
		int quickRaiseTime;
		int iFirstRaiseTime;
		int iEmptyRaiseTime;
		int iEmptyDropTime;
		int sprintInTime;
		int sprintLoopTime;
		int sprintOutTime;
		int stunnedTimeBegin;
		int stunnedTimeLoop;
		int stunnedTimeEnd;
		int nightVisionWearTime;
		int nightVisionWearTimeFadeOutEnd;
		int nightVisionWearTimePowerUp;
		int nightVisionRemoveTime;
		int nightVisionRemoveTimePowerDown;
		int nightVisionRemoveTimeFadeInStart;
		int fuseTime;
		int aifuseTime;
		float autoAimRange;
		float aimAssistRange;
		float aimAssistRangeAds;
		float aimPadding;
		float enemyCrosshairRange;
		float moveSpeedScale;
		float adsMoveSpeedScale;
		float sprintDurationScale;
		float adsZoomInFrac;
		float adsZoomOutFrac;
		Material* AdsOverlayShader;
		Material* AdsOverlayShaderLowRes;
		Material* AdsOverlayShaderEMP;
		Material* AdsOverlayShaderEMPLowRes;
		weapOverlayReticle_t adsOverlayReticle;
		WeapOverlayInterface_t adsOverlayInterface;
		float adsOverlayWidth;
		float adsOverlayHeight;
		float adsOverlayWidthSplitscreen;
		float adsOverlayHeightSplitscreen;
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
		float adsViewErrorMin;
		float adsViewErrorMax;
		void* collisions;
		float dualWieldViewModelOffset;
		weaponIconRatioType_t killIconRatio;
		int iReloadAmmoAdd;
		int iReloadStartAdd;
		int iDropAmmoMin;
		int ammoDropClipPercentMin;
		int ammoDropClipPercentMax;
		int iExplosionRadius;
		int iExplosionRadiusMin;
		int iExplosionInnerDamage;
		int iExplosionOuterDamage;
		float damageConeAngle;
		float bulletExplDmgMult;
		float bulletExplRadiusMult;
		int iProjectileSpeed;
		int iProjectileSpeedUp;
		int iProjectileSpeedForward;
		int iProjectileActivateDist;
		float projLifetime;
		float timeToAccelerate;
		float projectileCurvature;
		XModel* projectileModel;
		weapProjExplosion_t projExplosiveType;
		void* projExplosionEffect;
		void* projDudEffect;
		snd_alias_list_name projExplosionSound;
		snd_alias_list_name projDudSound;
		WeapStickinessType stickiness;
		float lowAmmoWarningThreshold;
		float ricochetChance;
		float* parallelBounce;
		float* perpendicularBounce;
		void* projTrailEffect;
		void* projBeaconEffect;
		float vProjectileColor[3];
		guidedMissileType_t guidedMissileType;
		float maxSteeringAccel;
		float projIgnitionDelay;
		void* projIgnitionEffect;
		snd_alias_list_name projIgnitionSound;
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
		float fHipViewScatterMin;
		float fHipViewScatterMax;
		float fightDist;
		float maxDist;
		const char* accuracyGraphName[2];
		float accuracyGraphKnots[2];
		float originalAccuracyGraphKnots[2];
		short accuracyGraphKnotCount;
		short originalAccuracyGraphKnotCount;
		int iPositionReloadTransTime;
		float leftArc;
		float rightArc;
		float topArc;
		float bottomArc;
		float accuracy;
		float aiSpread;
		float playerSpread;
		float minVertTurnSpeed;
		float minHorTurnSpeed;
		float maxVertTurnSpeed;
		float maxHorTurnSpeed;
		float pitchConvergenceTime;
		float yawConvergenceTime;
		float suppressTime;
		float maxRange;
		float fAnimHorRotateInc;
		float fPlayerPositionDist;
		const char* szUseHintString;
		const char* dropHintString;
		int iUseHintStringIndex;
		int dropHintStringIndex;
		float horizViewJitter;
		float vertViewJitter;
		float scanSpeed;
		float scanAccel;
		int scanPauseTime;
		const char* szScript;
		float fOOPosAnimLength[2];
		int minDamage;
		int minPlayerDamage;
		float maxDamageRange;
		float minDamageRange;
		float destabilizationRateTime;
		float destabilizationCurvatureMax;
		int destabilizeDistance;
		float* locationDamageMultipliers;
		const char* fireRumble;
		const char* meleeImpactRumble;
		Tracer* tracer;
		int turretScopeZoomRate;
		int turretScopeZoomMin;
		int turretScopeZoomMax;
		int turretOverheatUpRate;
		int turretOverheatDownRate;
		int turretOverheatPenalty;
		snd_alias_list_name turretOverheatSound;
		void* turretOverheatEffect;
		char* turretBarrelSpinRumble;
		int turretBarrelSpinUpTime;
		int turretBarrelSpinDownTime;
		int turretBarrelSpinSpeed;
		snd_alias_list_name turretBarrelSpinMaxSnd;
		snd_alias_list_name turretBarrelSpinUpSnds[4];
		snd_alias_list_name turretBarrelSpinDownSnds[4];
		snd_alias_list_name missileConeSoundAlias;
		snd_alias_list_name missileConeSoundAliasAtBase;
		float missileConeSoundRadiusAtTop;
		float missileConeSoundRadiusAtBase;
		float missileConeSoundHeight;
		float missileConeSoundOriginOffset;
		float missileConeSoundVolumescaleAtCore;
		float missileConeSoundVolumescaleAtEdge;
		float missileConeSoundVolumescaleCoreSize;
		float missileConeSoundPitchAtTop;
		float missileConeSoundPitchAtBottom;
		float missileConeSoundPitchTopSize;
		float missileConeSoundPitchBottomSize;
		float missileConeSoundCrossfadeTopSize;
		float missileConeSoundCrossfadeBottomSize;
		bool shareAmmo;
		bool lockonSupported;
		bool requireLockonToFire;
		bool bigExplosion;
		bool noAdsWhenMagEmpty;
		bool avoidDropCleanup;
		bool inheritsPerks;
		bool crosshairColorChange;
		bool rifleBullet;
		bool armorPiercing;
		bool boltAction;
		bool aimDownSight;
		bool rechamberWhileAds;
		bool bBulletExplosiveDamage;
		bool cookOffHold;
		bool clipOnly;
		bool noAmmoPickup;
		bool adsFire;
		bool cancelAutoHolsterWhenEmpty;
		bool disableSwitchToWhenEmpty;
		bool suppressAmmoReserveDisplay;
		bool laserSightDuringNightvision;
		bool markableViewmodel;
		bool noDualWield;
		bool flipKillIcon;
		bool noPartialReload;
		bool segmentedReload;
		bool blocksProne;
		bool silenced;
		bool isRollingGrenade;
		bool projExplosionEffectForceNormalUp;
		bool projImpactExplode;
		bool stickToPlayers;
		bool hasDetonator;
		bool disableFiring;
		bool timedDetonation;
		bool rotate;
		bool holdButtonToThrow;
		bool freezeMovementWhenFiring;
		bool thermalScope;
		bool altModeSameWeapon;
		bool turretBarrelSpinEnabled;
		bool missileConeSoundEnabled;
		bool missileConeSoundPitchshiftEnabled;
		bool missileConeSoundCrossfadeEnabled;
		bool offhandHoldIsCancelable;
	};

	struct WeaponCompleteDef
	{
		const char* szInternalName;
		WeaponDef* weapDef;
		const char* szDisplayName;
		unsigned short* hideTags;
		const char** szXAnims;
		float fAdsZoomFov;
		int iAdsTransInTime;
		int iAdsTransOutTime;
		int iClipSize;
		ImpactType impactType;
		int iFireTime;
		weaponIconRatioType_t dpadIconRatio;
		float penetrateMultiplier;
		float fAdsViewKickCenterSpeed;
		float fHipViewKickCenterSpeed;
		const char* szAltWeaponName;
		unsigned int altWeaponIndex;
		int iAltRaiseTime;
		Material* killIcon;
		Material* dpadIcon;
		int fireAnimLength;
		int iFirstRaiseTime;
		int ammoDropStockMax;
		float adsDofStart;
		float adsDofEnd;
		unsigned __int16 accuracyGraphKnotCount[2];
		float(*accuracyGraphKnots[2])[2];
		bool motionTracker;
		bool enhanced;
		bool dpadIconShowsAmmo;
	};

	//Start Of Risky Stuff

	enum ViewLockTypes : __int32
	{
		PLAYERVIEWLOCK_NONE = 0x0,
		PLAYERVIEWLOCK_FULL = 0x1,
		PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
		PLAYERVIEWLOCKCOUNT = 0x3,
	};

	enum PlayerHandIndex : __int32
	{
		WEAPON_HAND_RIGHT = 0x0,
		WEAPON_HAND_LEFT = 0x1,
		NUM_WEAPON_HANDS = 0x2,
		WEAPON_HAND_DEFAULT = 0x0,
	};

	struct GlobalAmmo
	{
		int ammoType;
		int ammoCount;
	};

	/* 8775 */
	struct ClipAmmo
	{
		int clipIndex;
		int ammoCount[2];
	};


	struct color_s
	{
		BYTE r;
		BYTE g;
		BYTE b;
		BYTE a;
	};

	union hudelem_color_t
	{
		color_s _s0;
		int rgba;
	};

	typedef enum {
		RT = 0x100,
		RS = 0x400,
		X = 0x2000,
		PRONE = 0x10000,
		CROUCH = 0x20000,
		A = 0x40000,
		LS = 0x200200,
		RB = 0x400000,
		LB = 0x800000,
		LT = 0x8080000
	}buttons_t;

	struct usercmd_s
	{
		int servertime;
		buttons_t buttons;
		int angle[2];
		char padding[4];
		short weapon;
		char _padding[2];
		short offHandIndex;
		char forwardMove;
		char rightMove;
		char __padding[0xC];
	};

	struct SprintState
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
	};

	/* 8772 */
	struct MantleState
	{
		float yaw;
		int timer;
		int transIndex;
		int flags;
	};

	enum weaponStates
	{
		WEAPON_READY = 0x0,
		WEAPON_RAISING = 0x1,
		WEAPON_RAISING_ALTSWITCH = 0x2,
		WEAPON_DROPPING = 0x3,
		WEAPON_DROPPING_QUICK = 0x4,
		WEAPON_DROPPING_ALT = 0x5,
		WEAPON_FIRING = 0x6,
		WEAPON_RECHAMBERING = 0x7,
		WEAPON_RELOADING = 0x8,
		WEAPON_RELOADING_INTERUPT = 0x9,
		WEAPON_RELOAD_START = 0xA,
		WEAPON_RELOAD_START_INTERUPT = 0xB,
		WEAPON_RELOAD_END = 0xC,
		WEAPON_MELEE_INIT = 0xD,
		WEAPON_MELEE_FIRE = 0xE,
		WEAPON_MELEE_END = 0xF,
		WEAPON_OFFHAND_INIT = 0x10,
		WEAPON_OFFHAND_PREPARE = 0x11,
		WEAPON_OFFHAND_HOLD = 0x12,
		WEAPON_OFFHAND_FIRE = 0x13,
		WEAPON_OFFHAND_DETONATE = 0x14,
		WEAPON_OFFHAND_END = 0x15,
		WEAPON_DETONATING = 0x16,
		WEAPON_SPRINT_RAISE = 0x17,
		WEAPON_SPRINT_LOOP = 0x18,
		WEAPON_SPRINT_DROP = 0x19,
		WEAPON_STUNNED_START = 0x1A,
		WEAPON_STUNNED_LOOP = 0x1B,
		WEAPON_STUNNED_END = 0x1C,
		WEAPON_NIGHTVISION_WEAR = 0x1D,
		WEAPON_NIGHTVISION_REMOVE = 0x1E,
		WEAPONSTATES_NUM = 0x1F,
	};

	enum weaponAnim
	{
		WEAP_IDLE = 0x0,
		WEAP_FORCE_IDLE = 0x1,
		WEAP_ATTACK = 0x2,
		WEAP_ATTACK_LASTSHOT = 0x3,
		WEAP_RECHAMBER = 0x4,
		WEAP_ADS_ATTACK = 0x5,
		WEAP_ADS_ATTACK_LASTSHOT = 0x6,
		WEAP_ADS_RECHAMBER = 0x7,
		WEAP_MELEE_ATTACK = 0x8,
		WEAP_MELEE_CHARGE = 0x9,
		WEAP_DROP = 0xA,
		WEAP_RAISE = 0xB,
		WEAP_FIRST_RAISE = 0xC,
		WEAP_RELOAD = 0xD,
		WEAP_RELOAD_EMPTY = 0xE,
		WEAP_RELOAD_START = 0xF,
		WEAP_RELOAD_END = 0x10,
		WEAP_ALTSWITCHFROM = 0x11,
		WEAP_ALTSWITCHTO = 0x12,
		WEAP_QUICK_DROP = 0x13,
		WEAP_QUICK_RAISE = 0x14,
		WEAP_EMPTY_DROP = 0x15,
		WEAP_EMPTY_RAISE = 0x16,
		WEAP_SPRINT_IN = 0x17,
		WEAP_SPRINT_LOOP = 0x18,
		WEAP_SPRINT_OUT = 0x19,
		WEAP_STUNNED_START = 0x1A,
		WEAP_STUNNED_LOOP = 0x1B,
		WEAP_STUNNED_END = 0x1C,
		WEAP_HOLD_FIRE = 0x1D,
		WEAP_DETONATE = 0x1E,
		WEAP_NIGHTVISION_WEAR = 0x1F,
		WEAP_NIGHTVISION_REMOVE = 0x20,
		MAX_WP_ANIMATIONS = 0x21,
	};

	/* 8773 */
	struct PlayerEquippedWeaponState
	{
		bool usedBefore;
		bool dualWielding;
		unsigned __int8 weaponModel;
		bool needsRechamber[2];
	};

	struct PlayerActiveWeaponState
	{
		int weapAnim;
		int weaponTime;
		int weaponDelay;
		int weaponRestrictKickTime;
		int weaponState;
		int weapHandFlags;
		unsigned int weaponShotCount;
	};

	struct PlayerWeaponCommonState
	{
		int offHandIndex;
		OffhandClass offhandPrimary;
		OffhandClass offhandSecondary;
		unsigned int weapon;
		unsigned int primaryWeaponForAltMode;
		int weapFlags;
		float fWeaponPosFrac;
		float aimSpreadScale;
		int adsDelayTime;
		int spreadOverride;
		int spreadOverrideState;
		PlayerHandIndex lastWeaponHand;
		GlobalAmmo ammoNotInClip[15];
		ClipAmmo ammoInClip[15];
		int weapLockFlags;
		int weapLockedEntnum;
		float weapLockedPos[3];
		int weaponIdleTime;
	};

	enum ActionSlotType : int
	{
		ACTIONSLOTTYPE_DONOTHING = 0x0,
		ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
		ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
		ACTIONSLOTTYPE_NIGHTVISION = 0x3,
		ACTIONSLOTTYPECOUNT = 0x4,
	};

	struct ActionSlotParam_SpecifyWeapon
	{
		unsigned int index;
	};

	struct ActionSlotParam
	{
		ActionSlotParam_SpecifyWeapon specifyWeapon;
	};

	enum objectiveState_t
	{
		OBJST_EMPTY = 0x0,
		OBJST_ACTIVE = 0x1,
		OBJST_INVISIBLE = 0x2,
		OBJST_DONE = 0x3,
		OBJST_CURRENT = 0x4,
		OBJST_FAILED = 0x5,
		OBJST_NUMSTATES = 0x6,
	};

	struct objective_t
	{
		objectiveState_t state;
		float origin[3];
		int entNum;
		int teamNum;
		int icon;
	};

	/* 8780 */
	struct playerState_s
	{
		int commandTime;
		int pm_type;
		int pm_time;
		int pm_flags;
		int otherFlags;
		int linkFlags;
		int bobCycle;
		float origin[3];
		float velocity[3];
		int grenadeTimeLeft;
		int throwbackGrenadeOwner;
		int throwbackGrenadeTimeLeft;
		unsigned int throwbackWeaponIndex;
		int remoteEyesEnt;
		int remoteEyesTagname;
		int remoteControlEnt;
		int foliageSoundTime;
		int gravity;
		float leanf;
		int speed;
		float delta_angles[3];
		int groundEntityNum;
		float vLadderVec[3];
		int jumpTime;
		float jumpOriginZ;
		int legsTimer;
		int legsAnim;
		int torsoTimer;
		int torsoAnim;
		int legsAnimDuration;
		int torsoAnimDuration;
		int damageTimer;
		int damageDuration;
		int flinchYawAnim;
		int corpseIndex;
		int movementDir;
		int eFlags;
		int eventSequence;
		int events[4];
		unsigned int eventParms[4];
		int oldEventSequence;
		int unpredictableEventSequence;
		int unpredictableEventSequenceOld;
		int unpredictableEvents[4];
		unsigned int unpredictableEventParms[4];
		int clientNum;
		int viewmodelIndex;
		float viewangles[3];
		int viewHeightTarget;
		float viewHeightCurrent;
		int viewHeightLerpTime;
		int viewHeightLerpTarget;
		int viewHeightLerpDown;
		float viewAngleClampBase[2];
		float viewAngleClampRange[2];
		int damageEvent;
		int damageYaw;
		int damagePitch;
		int damageCount;
		int damageFlags;
		int stats[4];
		float proneDirection;
		float proneDirectionPitch;
		float proneTorsoPitch;
		ViewLockTypes viewlocked;
		int viewlocked_entNum;
		float linkAngles[3];
		float linkWeaponAngles[3];
		int linkWeaponEnt;
		int loopSound;
		int cursorHint;
		int cursorHintString;
		int cursorHintEntIndex;
		int cursorHintDualWield;
		int iCompassPlayerInfo;
		int radarEnabled;
		int radarBlocked;
		int radarMode;
		int locationSelectionInfo;
		SprintState sprintState;
		float holdBreathScale;
		int holdBreathTimer;
		float moveSpeedScaleMultiplier;
		MantleState mantleState;
		PlayerActiveWeaponState weapState[2];
		unsigned int weaponsEquipped[15];
		PlayerEquippedWeaponState weapEquippedData[15];
		PlayerWeaponCommonState weapCommon;
		float meleeChargeYaw;
		int meleeChargeDist;
		int meleeChargeTime;
		unsigned int perks[2];
		unsigned int perkSlots[8];
		ActionSlotType actionSlotType[4];
		ActionSlotParam actionSlotParam[4];
		int weaponHudIconOverrides[6];
		int animScriptedType;
		int shellshockIndex;
		int shellshockTime;
		int shellshockDuration;
		float dofNearStart;
		float dofNearEnd;
		float dofFarStart;
		float dofFarEnd;
		float dofNearBlur;
		float dofFarBlur;
		float dofViewmodelStart;
		float dofViewmodelEnd;
		objective_t objective[0x20];
		int deltaTime;
		int killCamEntity;
		int killCamLookAtEntity;
		int killCamClientNum;
		char _Unknown[0x1F0C];
		float LocationOrigin[3];
		char ___Unknown[0x998];
		int partbits[6];
		int recoilScale;
		int diveDirection;
		int stunTime;
		char still_unknown[0x64];
	};
	static_assert(sizeof(playerState_s) == 0x3180, "size of playerState_s different than 0x3180");

	enum TraceHitType : __int32
	{
		TRACE_HITTYPE_NONE = 0x0,
		TRACE_HITTYPE_ENTITY = 0x1,
		TRACE_HITTYPE_DYNENT_MODEL = 0x2,
		TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
		TRACE_HITTYPE_GLASS = 0x4,
	};

	struct weaponState_t
	{
		playerState_s* ps;
		float xyspeed;
		float frametime;
		float fLastIdleFactor;
		int time;
		int damageTime;
		float v_dmg_pitch;
		float v_dmg_roll;
		int* weapIdleTime;
		float baseAngles[3];
		float baseOrigin[3];
		float recoilAngles[3];
		float recoilSpeed[3];
		float swayAngles[3];
		float swayOrigin[3];
		float swayViewAngles[3];
		float bobAngles[3];
		int shellShockStart;
		int shellShockDuration;
		int shellShockFadeTime;
	};



	/* 8662 */
	struct TriggerSlab
	{
		float dir[3];
		float midPoint;
		float halfSize;
	};

	/* 8665 */
	struct TriggerHull
	{
		Bounds bounds;
		int contents;
		unsigned __int16 slabCount;
		unsigned __int16 firstSlab;
	};

	/* 8782 */
	struct TriggerModel
	{
		int contents;
		unsigned __int16 hullCount;
		unsigned __int16 firstHull;
	};

	/* 8799 */
	struct cStaticModel_s
	{
		XModel* xmodel;
		float origin[3];
		float invScaledAxis[3][3];
		Bounds absBounds;
	};

	/* 8800 */
	struct ClipMaterial
	{
		const char* name;
		int surfaceFlags;
		int contents;
	};

	/* 8801 */
	struct cNode_t
	{
		cplane_s* plane;
		__int16 children[2];
	};

	/* 8802 */
	struct cLeaf_t
	{
		unsigned __int16 firstCollAabbIndex;
		unsigned __int16 collAabbCount;
		int brushContents;
		int terrainContents;
		Bounds bounds;
		int leafBrushNode;
	};

	/* 8803 */
	struct cLeafBrushNodeLeaf_t
	{
		unsigned __int16* brushes;
	};

	/* 8804 */
	struct cLeafBrushNodeChildren_t
	{
		float dist;
		float range;
		unsigned __int16 childOffset[2];
	};

	/* 8805 */
	union cLeafBrushNodeData_t
	{
		cLeafBrushNodeLeaf_t leaf;
		cLeafBrushNodeChildren_t children;
	};

	/* 8806 */
	struct cLeafBrushNode_s
	{
		unsigned __int8 axis;
		__int16 leafBrushCount;
		int contents;
		cLeafBrushNodeData_t data;
	};

	/* 8807 */
	struct CollisionBorder
	{
		float distEq[3];
		float zBase;
		float zSlope;
		float start;
		float length;
	};

	/* 8808 */
	struct CollisionPartition
	{
		unsigned __int8 triCount;
		unsigned __int8 borderCount;
		unsigned __int8 firstVertSegment;
		int firstTri;
		CollisionBorder* borders;
	};

	/* 8809 */
	union CollisionAabbTreeIndex
	{
		int firstChildIndex;
		int partitionIndex;
	};

	/* 8810 */
	struct CollisionAabbTree
	{
		float midPoint[3];
		unsigned __int16 materialIndex;
		unsigned __int16 childCount;
		float halfSize[3];
		CollisionAabbTreeIndex u;
	};

	/* 8811 */
	struct cmodel_t
	{
		Bounds bounds;
		float radius;
		cLeaf_t leaf;
	};

	/* 8812 */
	struct MapTriggers
	{
		unsigned int count;
		TriggerModel* models;
		unsigned int hullCount;
		TriggerHull* hulls;
		unsigned int slabCount;
		TriggerSlab* slabs;
	};

	/* 8813 */
	struct __declspec(align(2)) Stage
	{
		const char* name;
		float origin[3];
		unsigned __int16 triggerIndex;
		unsigned __int8 sunPrimaryLightIndex;
	};

	/* 8814 */
	struct __declspec(align(4)) MapEnts
	{
		const char* name;
		char* entityString;
		int numEntityChars;
		MapTriggers trigger;
		Stage* stages;
		unsigned __int8 stageCount;
	};

	/* 8815 */
	struct SModelAabbNode
	{
		Bounds bounds;
		unsigned __int16 firstChild;
		unsigned __int16 childCount;
	};

	/* 8816 */
	struct GfxPlacement
	{
		float quat[4];
		float origin[3];
	};

	/* 8817 */
	struct DynEntityDef
	{
		DynEntityType type;
		GfxPlacement pose;
		XModel* xModel;
		unsigned __int16 brushModel;
		unsigned __int16 physicsBrushModel;
		const void* destroyFx;
		PhysPreset* physPreset;
		int health;
		PhysMass mass;
		int contents;
	};

	/* 8818 */
	struct DynEntityPose
	{
		GfxPlacement pose;
		float radius;
	};

	/* 8819 */
	struct DynEntityClient
	{
		int physObjId;
		unsigned __int16 flags;
		unsigned __int16 lightingHandle;
		int health;
	};

	/* 8820 */
	struct DynEntityColl
	{
		unsigned __int16 sector;
		unsigned __int16 nextEntInSector;
		float linkMins[2];
		float linkMaxs[2];
	};

	struct __declspec(align(64)) clipMap_t
	{
		const char* name;
		int isInUse;
		int planeCount;
		cplane_s* planes;
		unsigned int numStaticModels;
		cStaticModel_s* staticModelList;
		unsigned int numMaterials;
		ClipMaterial* materials;
		unsigned int numBrushSides;
		cbrushside_t* brushsides;
		unsigned int numBrushEdges;
		unsigned __int8* brushEdges;
		unsigned int numNodes;
		cNode_t* nodes;
		unsigned int numLeafs;
		cLeaf_t* leafs;
		unsigned int leafbrushNodesCount;
		cLeafBrushNode_s* leafbrushNodes;
		unsigned int numLeafBrushes;
		unsigned __int16* leafbrushes;
		unsigned int numLeafSurfaces;
		unsigned int* leafsurfaces;
		unsigned int vertCount;
		float(*verts)[3];
		int triCount;
		unsigned __int16* triIndices;
		unsigned __int8* triEdgeIsWalkable;
		int borderCount;
		CollisionBorder* borders;
		int partitionCount;
		CollisionPartition* partitions;
		int aabbTreeCount;
		CollisionAabbTree* aabbTrees;
		unsigned int numSubModels;
		cmodel_t* cmodels;
		unsigned __int16 numBrushes;
		cbrush_t* brushes;
		Bounds* brushBounds;
		int* brushContents;
		MapEnts* mapEnts;
		unsigned __int16 smodelNodeCount;
		SModelAabbNode* smodelNodes;
		unsigned __int16 dynEntCount[2];
		DynEntityDef* dynEntDefList[2];
		DynEntityPose* dynEntPoseList[2];
		DynEntityClient* dynEntClientList[2];
		DynEntityColl* dynEntCollList[2];
		unsigned int checksum;
	};



	/* 8958 */
	//is wrong
	struct __declspec(align(4)) trace_t
	{
		float fraction;
		float normal[3];
		int surfaceFlags;
		int contents;
		const char* material;
		TraceHitType hitType;
		unsigned __int16 hitId;
		float fractionForHitType;
		unsigned __int16 modelIndex;
		unsigned __int16 partName;
		unsigned __int16 partGroup;
		bool allsolid;
		bool startsolid;
		bool walkable;
	};

	typedef enum : int
	{
		TR_STATIONARY = 0x0,
		TR_INTERPOLATE = 0x1,
		TR_LINEAR = 0x2,
		TR_LINEAR_STOP = 0x3,
		TR_SINE = 0x4,
		TR_GRAVITY = 0x5,
		TR_ACCELERATE = 0x6,
		TR_DECELERATE = 0x7,
		TR_PHYSICS = 0x8,
		TR_RAGDOLL = 0xC,
	} trType_t;

	struct trajectory_t
	{
		int trTime;
		trType_t trType;
		float trDelta[3];
		float trBase[3];
		int trDuration;
	};

	struct LerpEntityStateVehicle
	{
		int indices;
		int flags;
		float bodyPitch;
		float bodyRoll;
		float steerYaw;
		float gunPitch;
		float gunYaw;
		int playerIndex;
		int pad;
	};

	struct LerpEntityStatePlane
	{
		int ownerNum;
		int enemyIcon;
		int friendIcon;
	};

	struct LerpEntityStatePlayer
	{
		float leanf;
		int movementDir;
		float waistPitch;
		float torsoPitch;
		int offhandWeapon;
		int lastSpawnTime;
	};

	struct LerpEntityStateAnonymous
	{
		int data[9];
	};

	struct LerpEntityStateTurret
	{
		float gunAngles[3];
		int lastBarrelRotChangeTime;
		int lastBarrelRotChangeRate;
		int lastHeatChangeLevel;
		int lastHeatChangeTime;
	};

	struct LerpEntityStateScriptMover
	{
		int entToTakeMarksFrom;
		int xModelIndex;
		int animIndex;
		int animTime;
	};

	struct LerpEntityStateLoopFX
	{
		float cullDist;
		int period;
	};

	struct LerpEntityStateMissile
	{
		int launchTime;
		int flightMode;
	};

	struct LerpEntityStateSoundBlend
	{
		int lerp;
	};

	union LerpEntityStateTypeUnion
	{
		LerpEntityStateSoundBlend soundBlend;
		LerpEntityStateMissile missile;
		LerpEntityStateLoopFX loopFx;
		LerpEntityStateScriptMover scriptMover;
		LerpEntityStateTurret turret;
		LerpEntityStateAnonymous anonymous;
		LerpEntityStatePlayer player;
		LerpEntityStatePlane plane;
		LerpEntityStateVehicle vehicle;
	};

	struct LerpEntityState
	{
		int eFlags;
		trajectory_t pos;
		trajectory_t apos;
		LerpEntityStateTypeUnion u;
	};

	struct clientControllers_t
	{
		float angles[4][3];
		float tag_origin_angles[3];
		float tag_origin_offset[3];
	};

	struct CEntPlayerInfo
	{
		clientControllers_t* control;
		unsigned __int8 tag[4];
	};

	struct CEntTurretAngles
	{
		float pitch;
		float yaw;
	};

	union $062DBEF1E2477FBB6A8D36FDF573DC79
	{
		CEntTurretAngles angles;
		const float* viewAngles;
	};

	struct CEntTurretInfo
	{
		$062DBEF1E2477FBB6A8D36FDF573DC79 ___u0;
		float barrelPitch;
		bool playerUsing;
		unsigned __int8 tagIdx_aim;
		unsigned __int8 tagIdx_aim_animated;
		unsigned __int8 tagIdx_aim_pivot;
		unsigned __int8 tagIdx_flash;
		unsigned __int8 tagIdx_barrel;
		float barrelRoll;
		bool barrelRollSndLastRotating;
		bool barrelRollSndNotified;
		int barrelRollSndTime;
		unsigned __int8 barrelRollSndIndex;
		bool wasOverheat;
	};

	struct CEntVehicleInfo
	{
		__int16 pitch;
		__int16 yaw;
		__int16 roll;
		__int16 barrelPitch;
		float barrelRoll;
		__int16 steerYaw;
		float time;
		unsigned __int16 wheelFraction[6];
		unsigned __int8 wheelBoneIndex[6];
		unsigned __int8 wheelSurfaceType[6];
		unsigned __int8 tag_body;
		unsigned __int8 tag_turret;
		unsigned __int8 tag_barrel;
	};

	struct CEntFx
	{
		int triggerTime;
		void* effect;
	};

	struct XAnimParent
	{
		unsigned short flags;
		unsigned short children;
	};

	struct XAnimEntry
	{
		unsigned short numAnims;
		unsigned short parent;

		union
		{
			XAnimParts* parts;
			XAnimParent animParent;
		};
	};

	struct XAnim_s
	{
		unsigned int size;
		const char* debugName;
		const char** debugAnimNames;
		XAnimEntry entries[1];
	};

	struct __declspec(align(4)) XAnimTree_s
	{
		XAnim_s* anims;
		int info_usage;
		volatile int calcRefCount;
		volatile int modifyRefCount;
		unsigned __int16 children;
	};

	union $79C409BC84BCEABA56F6D25E37F2711D
	{
		CEntPlayerInfo player;
		CEntTurretInfo turret;
		CEntVehicleInfo vehicle;
		CEntFx fx;
	};

	struct cpose_t
	{
		unsigned __int16 lightingHandle;
		unsigned __int8 eType;
		unsigned __int8 cullIn;
		unsigned int usedInScene;
		unsigned __int8 isRagdoll;
		int ragdollHandle;
		int killcamRagdollHandle;
		int physObjId;
		float origin[3];
		float angles[3];
		$79C409BC84BCEABA56F6D25E37F2711D ___u10;
	};

	struct clientLinkInfo_t
	{
		__int16 parentId;
		char tagName;
		char flags;
	};

	struct entityState_s
	{
		int number;
		int eType;
		LerpEntityState lerp;
		int time2;
		int otherEntityNum;
		int attackerEntityNum;
		int groundEntityNum;
		int loopSound;
		int surfType;
		union
		{
			int brushModel;
			int triggerModel;
			int item;
			int xmodel;
			int primaryLight;
		} index;
		int clientNum;
		int iHeadIcon;
		int iHeadIconTeam;
		int solid;
		unsigned int eventParm;
		int eventSequence;
		int events[4];
		unsigned int eventParms[4];
		unsigned __int16 weapon;
		int legsAnim;
		int torsoAnim;
		union
		{
			int eventParm2;
			int hintString;
			int fxId;
			int helicopterStage;
		} un1;
		union
		{
			int hintType;
			struct
			{
				unsigned __int16 vehicleXModel;
				char weaponModel;
			} __s1;
			int actorFlags;
		} un2;
		clientLinkInfo_t clientLinkInfo;
		unsigned int partBits[6];
		int clientMask[1];
	};

	struct centity_s
	{
		cpose_t pose;
		LerpEntityState prevState;
		entityState_s nextState;
		int flags;
		unsigned __int8 tracerDrawRateCounter;
		unsigned __int8 weaponVisTestCounter;
		int previousEventSequence;
		int pickupPredictionTime;
		float lightingOrigin[3];
		XAnimTree_s* tree;
		void* updateDelayedNext;
	};

	struct playerEntity_t
	{
		int bPositionToADS;
		float fLastIdleFactor;
		float baseMoveOrigin[3];
		float baseMoveAngles[3];
	};


	enum DemoType
	{
		DEMO_TYPE_NONE = 0x0,
		DEMO_TYPE_CLIENT = 0x1,
		DEMO_TYPE_SERVER = 0x2,
	};

	enum CubemapShot
	{
		CUBEMAPSHOT_NONE = 0x0,
		CUBEMAPSHOT_RIGHT = 0x1,
		CUBEMAPSHOT_LEFT = 0x2,
		CUBEMAPSHOT_BACK = 0x3,
		CUBEMAPSHOT_FRONT = 0x4,
		CUBEMAPSHOT_UP = 0x5,
		CUBEMAPSHOT_DOWN = 0x6,
		CUBEMAPSHOT_COUNT = 0x7,
	};

	struct cg_s
	{
		playerState_s predictedPlayerState;
		centity_s predictedPlayerEntity;
		playerEntity_t playerEntity;
		int predictedErrorTime;
		float predictedError[3];
		int clientNum;
		int localClientNum;
		DemoType demoType;
		CubemapShot cubemapShot;
		int cubemapSize;
		int renderScreen;
		int latestSnapshotNum;
		int latestSnapshotTime;
		char pad0[16];
		void* snap;
		void* nextSnap;
		char _pad1[0x673DC];
		int frametime;	// + 0x6A754
		int time;
		int oldTime;
		int physicalsTime;
		char _pad2[0x9600]; // + 0x6A758
		float compassMapWorldSize[2]; // + 0x73D64
		char _pad3[0x74]; // + 0x73D6C
		float selectedLocation[2]; // + 0x73DE0
		float selectedLocationAngle;
		float selectedAngleLocation[2];
		float selectedLocationPrev[2];
		float selectedLocationAnglePrev;
		char _pad4[0x89740];
	};

	//union $79C409BC84BCEABA56F6D25E37F2711D
	//{
	//	CEntPlayerInfo player;
	//	CEntTurretInfo turret;
	//	CEntVehicleInfo vehicle;
	//	CEntFx fx;
	//};
	//
	//struct cpose_t
	//{
	//	unsigned __int16 lightingHandle;
	//	unsigned __int8 eType;
	//	unsigned __int8 cullIn;
	//	unsigned int usedInScene;
	//	unsigned __int8 isRagdoll;
	//	int ragdollHandle;
	//	int killcamRagdollHandle;
	//	int physObjId;
	//	float origin[3];
	//	float angles[3];
	//	$79C409BC84BCEABA56F6D25E37F2711D ___u10;
	//};
	//
	//struct centity_s
	//{
	//	cpose_t pose;
	//	LerpEntityState prevState;
	//	entityState_s nextState;
	//	int flags;
	//	unsigned __int8 tracerDrawRateCounter;
	//	unsigned __int8 weaponVisTestCounter;
	//	int previousEventSequence;
	//	int pickupPredictionTime;
	//	float lightingOrigin[3];
	//	XAnimTree_s* tree;
	//	centity_s* updateDelayedNext;
	//};
	//
	//struct visionSetVars_t
	//{
	//	bool glowEnable;
	//	float glowBloomCutoff;
	//	float glowBloomDesaturation;
	//	float glowBloomIntensity0;
	//	float glowBloomIntensity1;
	//	float glowRadius0;
	//	float glowRadius1;
	//	float glowSkyBleedIntensity0;
	//	float glowSkyBleedIntensity1;
	//	bool filmEnable;
	//	float filmBrightness;
	//	float filmContrast;
	//	float filmDesaturation;
	//	float filmDesaturationDark;
	//	bool filmInvert;
	//	float filmLightTint[3];
	//	float filmMediumTint[3];
	//	float filmDarkTint[3];
	//	bool charPrimaryUseTweaks;
	//	float charPrimaryDiffuseScale;
	//	float charPrimarySpecularScale;
	//};
	//
	//struct visionSetLerpData_t
	//{
	//	int timeStart;
	//	int timeDuration;
	//	visionSetLerpStyle_t style;
	//};
	//
	///* 9047 */
	//struct cg_s::<unnamed_type_lastFrame>
	//{
	//	float aimSpreadScale;
	//};
	//
	///* 9048 */
	//struct transPlayerState_t
	//{
	//	int otherFlags;
	//	int damageEvent;
	//	int eventSequence;
	//	int events[4];
	//	int unpredictableEventSequence;
	//	int unpredictableEvents[4];
	//};
	//
	///* 9049 */
	//struct hudElemSoundInfo_t
	//{
	//	int lastPlayedTime;
	//};
	//
	///* 9050 */
	//struct HudGrenade
	//{
	//	float origin[3];
	//	Material* material;
	//};
	//
	///* 9051 */
	//struct HudSplash
	//{
	//	int splashIndex;
	//	int splashStartTime;
	//	int splashDuration;
	//	int optionalNumParam;
	//};
	//
	///* 9052 */
	//struct ShieldHitDelayedEvent
	//{
	//	unsigned int eventParm;
	//};
	//
	//struct CachedPlayerCard
	//{
	//	unsigned __int16 iconIndex;
	//	unsigned __int16 titleIndex;
	//	Material* iconMaterial;
	//	Material* titleMaterial;
	//};
	//
	//struct __declspec(align(128)) cg_s
	//{
	//	playerState_s predictedPlayerState;
	//	centity_s predictedPlayerEntity;
	//	playerEntity_t playerEntity;
	//	int predictedErrorTime;
	//	float predictedError[3];
	//	int clientNum;
	//	int localClientNum;
	//	DemoType demoType;
	//	CubemapShot cubemapShot;
	//	int cubemapSize;
	//	int renderScreen;
	//	int latestSnapshotNum;
	//	int latestSnapshotTime;
	//	snapshot_s* snap;
	//	snapshot_s* nextSnap;
	//	snapshot_s activeSnapshots[2];
	//	float frameInterpolation;
	//	int frametime;
	//	int time;
	//	int oldTime;
	//	int physicsTime;
	//	int mapRestart;
	//	int renderingThirdPerson;
	//	float landChange;
	//	int landTime;
	//	float heightToCeiling;
	//	refdef_t refdef;
	//	float refdefViewAngles[3];
	//	float baseGunAngles[3];
	//	float aimAssistEyeOrigin[3];
	//	float aimAssistViewOrigin[3];
	//	float aimAssistViewAngles[3];
	//	float thirdPersonGunPitch;
	//	float thirdPersonGunYaw;
	//	float thirdPersonAdsLerp;
	//	float swayViewAngles[3];
	//	float swayAngles[3];
	//	float swayOffset[3];
	//	float recoilAngles[3];
	//	float recoilSpeed[3];
	//	int iEntityLastType[2048];
	//	XModel* pEntityLastXModel[2048];
	//	float zoomSensitivity;
	//	int vehicleInitView;
	//	float prevVehicleInvAxis[3][3];
	//	char objectiveText[1024];
	//	char scriptMainMenu[256];
	//	int scoresRequestTime;
	//	int numScores;
	//	int teamScores[4];
	//	int teamPings[4];
	//	int teamPlayers[4];
	//	score_t scores[18];
	//	int scoreLimit;
	//	int scoreFadeTime;
	//	int scoresTop;
	//	int scoresOffBottom;
	//	int scoresBottom;
	//	int selectedGamerIndex;
	//	int bannerLines[4];
	//	unsigned __int64 selectedGamerXuid;
	//	int unmutableNoticeTime;
	//	int crosshairClientNum;
	//	int crosshairClientLastTime;
	//	int crosshairClientStartTime;
	//	int cursorHintIcon;
	//	int cursorHintEntType;
	//	int cursorHintTime;
	//	int cursorHintFade;
	//	int cursorHintString;
	//	int cursorHintDualWield;
	//	int lastClipFlashTime;
	//	InvalidCmdHintType invalidCmdHintType;
	//	int invalidCmdHintWeapon;
	//	int invalidCmdHintTime;
	//	int lastHealthPulseTime;
	//	int lastHealthLerpDelay;
	//	int lastHealthClient;
	//	float lastHealth;
	//	int showHud;
	//	float bloodOverlayAlpha;
	//	int lastStance;
	//	int lastStanceChangeTime;
	//	int lastStanceFlashTime;
	//	int voiceTime;
	//	unsigned int weaponSelect;
	//	int weaponSelectTime;
	//	unsigned int weaponLatestPrimaryIdx;
	//	unsigned __int16 primaryWeaponForAlt[1200];
	//	unsigned int prevViewmodelWeapon;
	//	int prevDualWielding;
	//	int equippedOffHand;
	//	viewDamage_t viewDamage[12];
	//	int damageTime;
	//	float damageX;
	//	float damageY;
	//	float damageValue;
	//	float viewFade;
	//	int weapIdleTime;
	//	int v_dmg_time;
	//	int v_dmg_stun_time;
	//	float v_dmg_pitch;
	//	float v_dmg_roll;
	//	float xyspeed;
	//	float kickAVel[3];
	//	float kickAngles[3];
	//	float offsetAngles[3];
	//	float gunPitch;
	//	float gunYaw;
	//	float gunXOfs;
	//	float gunYOfs;
	//	float gunZOfs;
	//	float viewModelAxis[4][3];
	//	float rumbleScale;
	//	float compassNorthYaw;
	//	float compassNorth[2];
	//	Material* compassMapMaterial;
	//	float compassMapUpperLeft[2];
	//	float compassMapWorldSize[2];
	//	int compassFadeTime;
	//	int healthFadeTime;
	//	int ammoFadeTime;
	//	int stanceFadeTime;
	//	int sprintFadeTime;
	//	int offhandFadeTime;
	//	int offhandFlashTime;
	//	shellshock_t shellshock;
	//	cg_s::<unnamed_type_testShock> testShock;
	//	int holdBreathTime;
	//	int holdBreathInTime;
	//	int holdBreathDelay;
	//	float holdBreathFrac;
	//	bool painVisionActive;
	//	float painVisionLerp;
	//	bool painVisionSoundActive;
	//	PlayerDiveView diveView;
	//	float radarProgress;
	//	float selectedLocation[2];
	//	float selectedLocationAngle;
	//	float selectedLocationPrev[2];
	//	float selectedLocationAnglePrev;
	//	SprintState sprintStates;
	//	int packetAnalysisFrameCount;
	//	unsigned __int8 bitsSent[100][14];
	//	int entBitsUsed[10][19];
	//	int numEntsSent[10][19];
	//	int numEntFields[10][19];
	//	int numSnapshots;
	//	int adsViewErrorDone;
	//	int inKillCam;
	//	bool killCamFirstFrameRan;
	//	int killCamEntity;
	//	int invalidKillCamEntity;
	//	KillCamEntityType killCamEntityType;
	//	float killCamLastEntityOrg[3];
	//	float killCamLastEntityAngles[3];
	//	KillCamEntityRestState killCamEntityRestState;
	//	int killCamLookAtEntity;
	//	float killCamLookAt[3];
	//	float killCamHelicopterOffset[3];
	//	int killCamStoppedTime;
	//	float killCamStoppedDecelTime;
	//	float killCamStoppedPos[3];
	//	float killCamStoppedVel[3];
	//	float killCamPrevBombOrigin[3];
	//	int killCamLerpEndTime;
	//	float killCamOldViewAngles[3];
	//	float killCamOldViewOrg[3];
	//	bgs_t bgs;
	//	cpose_t viewModelPose;
	//	cpose_t viewModelPoseLeftHand;
	//	visionSetVars_t visionSetPreLoaded[4];
	//	char visionSetPreLoadedName[4][64];
	//	visionSetVars_t visionSetFrom[5];
	//	visionSetVars_t visionSetTo[5];
	//	visionSetVars_t visionSetCurrent[5];
	//	visionSetLerpData_t visionSetLerpData[5];
	//	char visionName[5][64];
	//	int extraButtons;
	//	bool playerTeleported;
	//	int stepViewStart;
	//	float stepViewChange;
	//	cg_s::<unnamed_type_lastFrame> lastFrame;
	//	int oldCommandTime;
	//	float oldOrigin[3];
	//	float oldViewangles[3];
	//	transPlayerState_t oldTransPlayerState;
	//	hudElemSoundInfo_t hudElemSound[32];
	//	HudGrenade hudGrenades[32];
	//	unsigned int hudGrenadeCount;
	//	HudSplash splashes[4];
	//	bool remoteMissileCam;
	//	bool remoteMissileCamInitialized;
	//	float remoteMissileCamAngles[3];
	//	unsigned int teamFx[1];
	//	unsigned int teamFxPlaying[1];
	//	int killcamFXWeapons[5];
	//	float radarJammedDist;
	//	float turretFov;
	//	bool thermalVisionActive;
	//	unsigned int weaponAltWasUsedLast[38];
	//	float motionTrackerPrevCenter[2];
	//	float motionTrackerProgress;
	//	float targetPosCached[2];
	//	int targetPosCachedTime;
	//	int delayedShieldHitEventsCount;
	//	ShieldHitDelayedEvent delayedShieldHitEvents[2];
	//	Material* thermalBodyMaterial;
	//	float streamOrigin[3];
	//	bool streamOriginValid;
	//	CachedPlayerCard cachedPlayerCard[18];
	//};

	/* 10300 */
	struct pml_t
	{
		float forward[3];
		float right[3];
		float up[3];
		float frametime;
		int msec;
		int walking;
		int groundPlane;
		int almostGroundPlane;
		trace_t groundTrace;
		float impactSpeed;
		float previous_origin[3];
		float previous_velocity[3];
		unsigned int holdrand;
	};

	struct pmove_t
	{
		playerState_s* ps;
		usercmd_s cmd;
		usercmd_s oldcmd;
		int tracemask;
		int numtouch;
		int touchents[32];
		Bounds bounds;
		float xyspeed;
		int proneChange;
		float maxSprintTimeMultiplier;
		bool mantleStarted;
		float mantleEndPos[3];
		int mantleDuration;
		int viewChangeTime;
		float viewChange;
		float fTorsoPitch;
		float fWaistPitch;
		unsigned __int8 handler;
	};

	struct LocalizeEntry
	{
		const char* value;
		const char* name;
	};

	enum XAssetType
	{
		ASSET_TYPE_PHYSPRESET,
		ASSET_TYPE_phys_collmap,
		ASSET_TYPE_xanim,
		ASSET_TYPE_xmodelsurfs,
		ASSET_TYPE_xmodel,
		ASSET_TYPE_material,
		ASSET_TYPE_pixelshader,
		ASSET_TYPE_techset,
		ASSET_TYPE_image,
		ASSET_TYPE_sound,
		ASSET_TYPE_sndcurve,
		ASSET_TYPE_loaded_sound,
		ASSET_TYPE_col_map_sp,
		ASSET_TYPE_col_map_mp,
		ASSET_TYPE_com_map,
		ASSET_TYPE_game_map_sp,
		ASSET_TYPE_game_map_mp,
		ASSET_TYPE_map_ents,
		ASSET_TYPE_fx_map,
		ASSET_TYPE_gfx_map,
		ASSET_TYPE_lightdef,
		ASSET_TYPE_ui_map,
		ASSET_TYPE_font,
		ASSET_TYPE_menufile,
		ASSET_TYPE_menu,
		ASSET_TYPE_localize,
		ASSET_TYPE_weapon,
		ASSET_TYPE_snddriverglobals,
		ASSET_TYPE_fx,
		ASSET_TYPE_impactfx,
		ASSET_TYPE_aitype,
		ASSET_TYPE_mptype,
		ASSET_TYPE_character,
		ASSET_TYPE_xmodelalias,
		ASSET_TYPE_rawfile,
		ASSET_TYPE_stringtable,
		ASSET_TYPE_leaderboarddef,
		ASSET_TYPE_structureddatadef,
		ASSET_TYPE_tracer,
		ASSET_TYPE_vehicle,
		ASSET_TYPE_addon_map_ents
	};

	struct RawFile
	{
		const char *name;
		int compressedLen;
		int len;
		const char *buffer;
	};

	union XAssetHeader
	{
		void* PHYSPRESET;
		void* phys_collmap;
		XAnimParts* xanim;
		void* xmodelsurfs;
		XModel* xmodel;
		Material* material;
		void* pixelshader;
		void* techset;
		GfxImage* image;
		snd_alias_list_name* sound;
		void* sndcurve;
		void* loaded_sound;
		void* col_map_sp;
		clipMap_t* col_map_mp;
		void* com_map;
		void* game_map_sp;
		void* game_map_mp;
		void* map_ents;
		void* fx_map;
		void* gfx_map;
		void* lightdef;
		void* ui_map;
		Font_s* font;
		void* menufile;
		void* menu;
		LocalizeEntry* localize;
		WeaponCompleteDef* weapon;
		void* snddriverglobals;
		void* fx;
		void* impactfx;
		void* aitype;
		void* mptype;
		void* character;
		void* xmodelalias;
		RawFile* rawfile;
		game::StringTable* stringtable;
		void* leaderboarddef;
		void* structureddatadef;
		Tracer* tracer;
		void* vehicle;
		void* addon_map_ents;
	};

	struct XAsset
	{
		XAssetType type;
		XAssetHeader header;
	};


	struct XAssetEntry
	{
		XAsset asset;
		unsigned __int8 zoneIndex;
		volatile unsigned __int8 inuseMask;
		bool printedMissingAsset;
		unsigned __int16 nextHash;
		unsigned __int16 nextOverride;
	};

	/* 10130 */
	union XAssetEntryPoolEntry
	{
		XAssetEntry entry;
		XAssetEntryPoolEntry* next;
	};

	template<typename T> union XAssetPoolEntry
	{
		T entry;
		T* next;                            //Pointer to the next asset, only if this asset is free
	};

	template<typename T, int count> struct XAssetPool
	{
		T* freeHead;                        //Pointer to the first free asset
		XAssetPoolEntry<T> entries[count];
	};

	//G_ENTITIES

	struct absBox_t
	{
		float midPoint[3];
		float halfSize[3];
	};

	struct entityShared_t
	{
		int clientMask;
		char linked;
		char bmodel;
		char svFlags;
		char inuse;
		absBox_t absBox;
		int content;
		float absmin[3];
		float absmax[3];
		float Origin[3];
		float angles[3];
		int ownerNum;
		int eventTime;
	};

	union index_t
	{
		int brushmodel;
		int item;
		int xmodel;
		int primaryLight;
	};



	/* entityState_s->eType */
	enum entityType_t : int
	{
		ET_GENERAL = 0x0,
		ET_PLAYER = 0x1,
		ET_PLAYER_CORPSE = 0x2,
		ET_ITEM = 0x3,
		ET_MISSILE = 0x4,
		ET_INVISIBLE = 0x5,
		ET_SCRIPTMOVER = 0x6,
		ET_SOUND_BLEND = 0x7,
		ET_FX = 0x8,
		ET_LOOP_FX = 0x9,
		ET_PRIMARY_LIGHT = 0xA,
		ET_TURRET = 0xB,
		ET_HELICOPTER = 0xC,
		ET_PLANE = 0xD,
		ET_VEHICLE = 0xE,
		ET_VEHICLE_COLLMAP = 0xF,
		ET_VEHICLE_CORPSE = 0x10,
		ET_VEHICLE_SPAWNER = 0x11
	};

	struct entityState_t
	{
		int number;
		entityType_t eType;
		int time2;
		LerpEntityState lerp;
		int otherEntityNum;
		int attackerEntityNum;
		int groundEntityNum;
		index_t index;
		int loopSound;
		int surfType;
		int clientNum;
		int iHeadIconTeam;
		int iHeadIcon;
		int eventParm;
		int solid;
		int eventSequence;
		int events[4];
		int eventParms[4];
		int wes;
		int torsoAnim;
		int legsAnim;
		union
		{
			int scale;
			int eventParm2;
			int helicopterStage;
		} un1;
		union
		{
			int hintString;
			int grenadeInPickupRange;
			int vehicleXModel;
		} un2;
		int clientLinkInfo;
		int partBits[6];
	};


	struct clientState_s
	{
		int clientIndex;
		team_t team;
		int modelindex;
		int dualWielding;
		int riotShieldNext;
		int attachModelIndex[6];
		int attachTagIndex[6];
		char name[32];
		float maxSprintTimeMultiplier;
		int rank;
		int prestige;
		unsigned int perks[2];
		int diveState;
		int voiceConnectivityBits;
		char clanAbbrev[8];
		int player_card_icon;
		int player_card_title;
		int playerCardNameplate;
	};
	static_assert(sizeof(clientState_s) == 0x94, "size of clientState_s different than 0x94");
	/* 9074 */
	struct EntHandle
	{
		unsigned __int16 number;
		unsigned __int16 infoIndex;
	};

	/* 9076 */
	struct playerTeamState_t
	{
		int location;
	};



	/* 9077 */
	struct clientSession_t
	{
		sessionState_t sessionState;
		int forceSpectatorClient;
		int killCamEntity;
		int killCamLookAtEntity;
		int status_icon;
		int archiveTime;
		int score;
		int deaths;
		int kills;
		int assists;
		unsigned __int16 scriptPersId;
		clientConnected_t connected;
		usercmd_s cmd;
		usercmd_s oldcmd;
		int localClient;
		int predictItemPickup;
		char newnetname[32];
		int maxHealth;
		int enterTime;
		playerTeamState_t teamState;
		int voteCount;
		int teamVoteCount;
		float moveSpeedScaleMultiplier;
		int viewmodelIndex;
		int noSpectate;
		int teamInfo;
		clientState_s cs;
		int psOffsetTime;
		int hasRadar;
		int isRadarBlocked;
		int radarMode;
		int weaponHudIconOverrides[6];
		unsigned int unusableEntFlags[64];
		float spectateDefaultPos[3];
		float spectateDefaultAngles[3];
	};

	/* 9078 */
	struct viewClamp
	{
		float start[2];
		float current[2];
		float goal[2];
	};

	/* 9079 */
	struct viewClampState
	{
		viewClamp min;
		viewClamp max;
		float accelTime;
		float decelTime;
		float totalTime;
		float startTime;
	};

	struct gclient_s
	{
		playerState_s ps;
		clientSession_t sess;
		int flags;
		int spectatorClient;
		int lastCmdTime;
		int mpviewer;
		int buttons;
		int oldbutton;
		int latched_buttons;
		int buttonsSinceLastFrame;
		float oldOrigin[3];
		float fGunPitch;
		float fGunYaw;
		int damage_blood;
		int damage_stun;
		float damage_from[3];
		int damage_fromWorld;
		int accurateCount;
		int accuracy_shots;
		int accuracy_hits;
		int inactivityTime;
		int inactivityWarning;
		int lastVoiceTime;
		int switchTeamTime;
		float currentAimSpreadScale;
		float prevLinkedInvQuat[4];
		char prevLinkAnglesSet;
		char link_rotationMovesEyePos;
		char link_doCollision;
		char link_useTagAnglesForViewAngles;
		float linkAnglesFrac;
		viewClampState link_viewClamp;
		int persistantPowerup;//#offset
		int portalID;
		int dropWeaponTime;
		int sniperRifleFiredTime;
		float sniperRifleMuzzleYaw;
		int PCSpecialPickedUpCount;
		int useHoldEntitychar;
		int useHoldTime;
		int usebuttonDone;
		int iLastCompassPlayerInfoEnt;
		int compassPingTime;
		int damageTime;
		float v_dmg_roll;
		float v_dmg_pitch;
		float baseAngles[3];
		float baseOrigin[3];
		float swayViewAngles[3];
		float swayOffset[3];
		float swayAngles[3];
		float recoilAngles[3];
		float recoilSpeed[3];
		float fLastIdleFactor;
		int weapIdleTime;
		int lastServerTime;
		int lastWeapon;
		char previouslyFiring;
		char previouslyFiringLeftHand;
		char previouslyUsingNightVision;
		char previouslySprinting;
		int visionDuration[5];
		char visionName[0x140];
		int lastStand;
		int lastStandTime;
		int hudElemLastAssignedSoundID;
		float lockedTargetOffset[3];
		int attachShieldTagName;
		int hintForcedType;
		int hintForcedString;
		char undefined[0x4];
	};

	/* 9082 */
	struct gentity_s
	{
		entityState_t state;
		entityShared_t r;
		gclient_s* client;
		int pTurretInfo;
		int scr_vehicle;
		int physicsBody;
		unsigned __int16 model;
		char physicsObject;
		char takeDamage;
		char active;
		char handler;
		char team;
		char freeAfterEvent;
		unsigned __int16 pad;
		unsigned __int16 code_classname;
		unsigned __int16 classname;
		unsigned __int16 script_linkname;
		unsigned __int16 target;
		unsigned __int16 targetname;
		int attachIgnoreCollision;
		int spawnFlags;
		int flags;
		int eventTime;
		int clipMask;
		int processedFrame;
		int parent;
		int nextthink;
		int health;
		int maxhealth;
		int dmg;
		int count;
		char still_unknown[0x18];
		float slidevelocity[3];
		char still_Unknown_[0x3C];
		int projEntity;
		int linkedEntity;
		int tagInfo;
		gentity_s* tagChildren;
		char unknown[0x4C];
		int useCount;
		int nextFree;
		int birthtime;
		char still_Unknown[0xC];
	};
	static_assert(sizeof(gentity_s) == 0x280, "size of gentity_s different than 0x280");

	enum netsrc_t : __int32
	{
	  NS_CLIENT1 = 0x0,
	  NS_CLIENT2 = 0x1,
	  NS_CLIENT3 = 0x2,
	  NS_CLIENT4 = 0x3,
	  NS_SERVER = 0x4,
	  NS_MAXCLIENTS = 0x4,
	  NS_PACKET = 0x5,
	};

	enum netadrtype_t : __int32
	{
	  NA_BOT = 0x0,
	  NA_BAD = 0x1,
	  NA_LOOPBACK = 0x2,
	  NA_BROADCAST = 0x3,
	  NA_IP = 0x4,
	};

	struct __declspec(align(4)) netadr_t
	{
	  netadrtype_t type;
	  unsigned __int8 ip[4];
	  unsigned __int16 port;
	};

	struct netProfilePacket_t
	{
	  int iTime;
	  int iSize;
	  int bFragment;
	};

	/* 8753 */
	struct netProfileStream_t
	{
	  netProfilePacket_t packets[60];
	  int iCurrPacket;
	  int iBytesPerSecond;
	  int iLastBPSCalcTime;
	  int iCountedPackets;
	  int iCountedFragments;
	  int iFragmentPercentage;
	  int iLargestPacket;
	  int iSmallestPacket;
	};

	struct netProfileInfo_t
	{
	  netProfileStream_t send;
	  netProfileStream_t recieve;
	};

	struct netchan_t
	{
	  int outgoingSequence;
	  netsrc_t sock;
	  int dropped;
	  int incomingSequence;
	  netadr_t remoteAddress;
	  int fragmentSequence;
	  int fragmentLength;
	  unsigned __int8 *fragmentBuffer;
	  int fragmentBufferSize;
	  int unsentFragments;
	  int unsentFragmentStart;
	  int unsentLength;
	  unsigned __int8 *unsentBuffer;
	  int unsentBufferSize;
	  netProfileInfo_t prof;
	};

	struct clientHeader_t
	{
	  int state;
	  int sendAsActive;
	  int deltaMessage;
	  int rateDelayed;
	  netchan_t netchan;
	  float predictedOrigin[3];
	  int predictedOriginServerTime;
	  int demorecording;
	  int demoFirstMessage;
	  int migrationState;
	};

	struct svscmd_info_t
	{
	  char cmd[1024];
	  int time;
	  int type;
	};

	struct clientSnapshot_t
	{
	  playerState_s ps;
	  int num_entities;
	  int num_clients;
	  int first_entity;
	  int first_client;
	  int messageSent;
	  int messageAcked;
	  int messageSize;
	  int serverTime;
	  int timeDelta;
	  unsigned __int8 padding[92];
	};

	struct client_t
	{
	  clientHeader_t header;
	  const char *dropReason;
	  char userinfo[1024];
	  svscmd_info_t reliableCommandInfo[128];
	  int reliableSequence;
	  int reliableAcknowledge;
	  int reliableSent;
	  int messageAcknowledge;
	  int gamestateMessageNum;
	  int challenge;
	  usercmd_s lastUsercmd;
	  int lastClientCommand;
	  char lastClientCommandString[1024];
	  gentity_s *gentity;
	  char name[32];
	  char clanAbbrev[5];
	  int nextReliableTime;
	  int lastPacketTime;
	  int lastConnectTime;
	  int nextSnapshotTime;
	  int timeoutCount;
	  int ping;
	  int rate;
	  int snapshotMsec;
	  int snapshotBackoffCount;
	  int pureAuthentic;
	  char netchanOutgoingBuffer[65536];
	  char netchanIncomingBuffer[2048];
	  char playerGuid[17];
	  unsigned __int16 scriptId;
	  int bIsTestClient;
	  int serverId;
	  bool usingOnlineStatsOffline;
	  unsigned __int8 stats[8192];
	  unsigned __int8 statsModifiedFlags[1024];
	  bool statsModified;
	  unsigned __int8 statPacketsReceived;
	  void *demofile;
	  void (__cdecl *demowrite)(const void *, int, int);
	  int demoWriteMessage;
	  bool sendMatchData;
	  int matchDataSendTime;
	  bool tempPacketDebugging;
	  unsigned __int8 padding[99];
	  clientSnapshot_t frames[32];
	};

	struct XKeyboardProperties
    {
        const char* noti;
        const char* desc;
        int lenght;
        scr_entref_t entity;
    };
}