#include "stdinclude.h"
#include "function.h"
#include "utils/detour.h"

namespace gsc
{
    std::unordered_map<std::string, game::BuiltinFunctionDef> function_map;

	void function::add_function(const char* name, const game::BuiltinFunction function)
	{
		if (function_map.find(name) != function_map.end())
		{
			return;
		}

		game::BuiltinFunctionDef def;
		def.actionString = name;
		def.type = 0;
		def.actionFunc = function;

		function_map[name] = def;
		game::Scr_RegisterFunction(function, name);
	}

	detour Common_GetFunction_detour;
	game::BuiltinFunction Common_GetFunction_hook(const char** pName, int* type)
	{
		if (pName != nullptr && function_map.find(*pName) != function_map.end())
		{
			game::BuiltinFunctionDef& def = function_map[*pName];
			game::Scr_RegisterFunction(def.actionFunc, *pName);
			*pName = def.actionString;
			*type = def.type;

			return def.actionFunc;
		}

		return Common_GetFunction_detour.get_original<decltype(&Common_GetFunction_hook)>()(pName, type);
	}

	void exec()
	{
		std::string value = game::Scr_GetString(0);
		game::Cbuf_AddText(0, value.c_str());
	}

    void function::init()
    {
        Common_GetFunction_detour.create(game::Common_GetFunction, Common_GetFunction_hook);

		add_function("exec", exec);
    }

    void function::unload()
    {
        Common_GetFunction_detour.remove();
    }
}