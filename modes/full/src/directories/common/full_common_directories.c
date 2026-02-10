#include <full_common_directories.h>
#include <stdio.h>
#include <shared.h>

bool full_common_directory_create (const char *const base_folder, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/common", base_folder);

    directory_target_t targets [] = 
    {
        { .base_dir = folder, .target_dir = "include" },
        { .base_dir = folder, .target_dir = "src" },
    };

    directory_target_list_t target_list = 
    {
        .directories = targets,
        .count = sizeof (targets) / sizeof (directory_target_t)
    };

    if (create_directories (&target_list) == false)
    {
        return false;
    }

    return true;
}