#include "stdinclude.h"
#include "utils/detour.h"
#include "utils/filesystem.h"
#include "loading.h"

namespace gsc
{
	detour Scr_AddSourceBufferdraw_detour;
	const char* Scr_AddSourceBuffer_hook(const char* filename, const char* ext_filename)
	{
		std::string file = "";
		std::string ext_filename_str = ext_filename;
		bool custom = ext_filename_str.compare(0, 3, "raw") == 0;
		if (custom) 
		{
			file = "game:\\" + ext_filename_str;
		}
		else
		{
			file = "game:\\raw\\" + ext_filename_str;
		}

		std::replace(file.begin(), file.end(), '/', '\\');
		if (filesystem::file_exists(file))
		{
			std::string buffer = filesystem::read_file_to_string(file);
			return buffer.c_str();
		}

		return Scr_AddSourceBufferdraw_detour.get_original<decltype(&Scr_AddSourceBuffer_hook)>()(filename, ext_filename);
	}

	void loading::init()
	{
		Scr_AddSourceBufferdraw_detour.create(game::Scr_AddSourceBuffer, Scr_AddSourceBuffer_hook);
	}

	void loading::unload()
	{
		Scr_AddSourceBufferdraw_detour.remove();
	}
}