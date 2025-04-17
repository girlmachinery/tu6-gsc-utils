#include "stdinclude.h"
#include "filesystem.h"

namespace filesystem
{
    void create_nested_dirs(const char *path)
    {
        if (!path || !*path)
            return;

        char temp_path[256];
        strncpy(temp_path, path, sizeof(temp_path) - 1);
        temp_path[sizeof(temp_path) - 1] = '\0';

        char *p = temp_path;

        if ((p[0] && p[1] == ':') || strncmp(p, "game:\\", 6) == 0)
            p += (p[1] == ':' ? 3 : 6);

        for (; *p; p++)
        {
            if (*p == '\\' || *p == '/')
            {
                *p = '\0';
                _mkdir(temp_path);
                *p = '\\';
            }
        }

        _mkdir(temp_path);
    }

    int write_file_to_disk(const char *file_path, const char *data, size_t data_size)
    {
        if (!file_path || !data || data_size == 0)
        {
            xbox::DbgPrint("write_file_to_disk: Invalid parameters!\n");
            return 0;
        }

        char dir_path[256];
        strncpy(dir_path, file_path, sizeof(dir_path));
        char *last_slash = strrchr(dir_path, '\\');
        if (last_slash)
        {
            *last_slash = '\0';
            create_nested_dirs(dir_path);
        }

        FILE *file = fopen(file_path, "wb");
        if (file)
        {
            fwrite(data, 1, data_size, file);
            fclose(file);
            xbox::DbgPrint("Successfully wrote file: %s\n", file_path);
            return 1;
        }
        else
        {
            xbox::DbgPrint("Failed to write file: %s\n", file_path);
            return 0;
        }
    }

    bool file_exists(const std::string &file_path)
    {
        std::ifstream file(file_path.c_str());
        return file.good();
    }

    std::string read_file_to_string(const std::string &file_path)
    {
        std::ifstream file(file_path, std::ios::binary);
        if (!file)
        {
            xbox::DbgPrint("read_file_to_string: Failed to open file: %s\n", file_path.c_str());
            return "";
        }

        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }
}
