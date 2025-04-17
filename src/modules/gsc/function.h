#pragma once

namespace gsc
{
	class function
	{
	public:
		static void add_function(const char* name, const game::BuiltinFunction function);
		static void init();
		static void unload();
	};
}