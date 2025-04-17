#pragma once

namespace gsc
{
	class method
	{
	public:
        static void add_method(const char* name, game::BuiltinMethod function);
		static void init();
		static void unload();
	};
}