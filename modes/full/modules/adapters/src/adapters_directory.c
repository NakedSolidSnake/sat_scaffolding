#include <adapters_directory.h>
#include <adpters_template.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <shared.h>

bool adapters_directories_create (const char *const root_folder)
{
    char base_folder [1024] = {0};
    snprintf (base_folder, 1023, "%s/adapters", root_folder);

    if (create_directory (root_folder, "adapters") == false)
    {
        return false;
    }

    if (adapters_cmake_root_template_create (base_folder) == false)
    {
        return false;
    }

    if (create_directory (base_folder, "factories") == false)
    {
        return false;
    }

    if (create_directory (base_folder, "factories/include") == false)
    {
        return false;
    }

    if (create_directory (base_folder, "factories/src") == false)
    {
        return false;
    }

    if (create_directory (base_folder, "config") == false)
    {
        return false;
    }

    if (create_directory (base_folder, "config/include") == false)
    {
        return false;
    }

    if (create_directory (base_folder, "config/src") == false)
    {
        return false;
    }

    if (create_directory (base_folder, "ports") == false)
    {
        return false;
    }

    if (create_directory (base_folder, "repositories") == false)
    {
        return false;
    }

    return true;
}