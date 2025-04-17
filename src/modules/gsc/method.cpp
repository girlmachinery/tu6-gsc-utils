#include "stdinclude.h"
#include "method.h"
#include "utils/detour.h"

namespace gsc
{
    std::unordered_map<std::string, game::BuiltinMethodDef> method_map;

	void method::add_method(const char* name, game::BuiltinMethod function)
	{
		if (method_map.find(name) != method_map.end())
		{
			return;
		}

		game::BuiltinMethodDef def;
		def.actionString = name;
		def.type = 0;
		def.actionFunc = function;

		method_map[name] = def;
		game::Scr_RegisterFunction(function, name);
	}

    detour Player_GetMethod_detour;
	game::BuiltinMethod Player_GetMethod_hook(const char** pName)
	{
		if (pName != nullptr && method_map.find(*pName) != method_map.end())
		{
			game::BuiltinMethodDef method = method_map[*pName];
			game::Scr_RegisterFunction(method.actionFunc, *pName);
			*pName = method.actionString;

			return method.actionFunc;
		}

		return Player_GetMethod_detour.get_original<decltype(&Player_GetMethod_hook)>()(pName);
	}

	void PlayerCmd_SetWeaponFlag(game::scr_entref_t entref) 
    {
        if (game::Scr_GetNumParam() != 1 || game::Scr_GetType(0) != game::VAR_INTEGER)
            return;

        int value = game::Scr_GetInt(0);
        auto entity = game::GetEntity(entref);
        entity->client->ps.weapCommon.weapFlags = value;
    }

    void PlayerCmd_SetGamertag(game::scr_entref_t entref) 
    {
        if (game::Scr_GetNumParam() != 1 || game::Scr_GetType(0) != game::VAR_STRING)
            return;

        auto value = game::Scr_GetString(0);
        game::set_gamertag(entref.entnum, value);
    }

    void PlayerCmd_SetClantag(game::scr_entref_t entref) 
    {
        if (game::Scr_GetNumParam() != 1 || game::Scr_GetType(0) != game::VAR_STRING)
            return;

        auto value = game::Scr_GetString(0);
        game::set_clantag(entref.entnum, value);
    }

	void PlayerCmd_XShowKeyboardUI(game::scr_entref_t entref)
    {
        if (game::Scr_GetNumParam() != 3 || game::Scr_GetType(0) != game::VAR_STRING)
            return;

        if (game::Scr_GetType(0) != game::VAR_STRING || game::Scr_GetType(1) != game::VAR_STRING)
            return;

        if (game::Scr_GetType(2) != game::VAR_INTEGER)
            return;

		game::XKeyboardProperties* p = new game::XKeyboardProperties();
        p->noti = game::Scr_GetString(0);
        p->desc = game::Scr_GetString(1);
        p->lenght = game::Scr_GetInt(2);
        p->entity = entref;

        CreateThread(NULL, NULL, game::XShowKeyboard, p, NULL, NULL);

    }

    void method::init()
    {
		Player_GetMethod_detour.create(game::Player_GetMethod, Player_GetMethod_hook);

		add_method("setweaponflag", PlayerCmd_SetWeaponFlag);
		add_method("setgamertag", PlayerCmd_SetGamertag);
		add_method("setclantag", PlayerCmd_SetClantag);
		add_method("xshowkeyboardui", PlayerCmd_XShowKeyboardUI);
    }

    void method::unload()
    {
        Player_GetMethod_detour.remove();
    }
}