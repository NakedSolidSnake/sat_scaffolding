#include <full_resources_directories.h>
#include <stdio.h>
#include <shared.h>


bool full_resources_directory_create (const char *const base_folder, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/resources", base_folder);

    directory_target_t targets [] = 
    {
        { .base_dir = folder, .target_dir = "assets" },
        { .base_dir = folder, .target_dir = "properties" },
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