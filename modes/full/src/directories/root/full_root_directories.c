#include <full_root_directories.h>
#include <full_source_directories.h>
#include <full_resources_directories.h>
#include <full_tools_directories.h>
#include <stdio.h>
#include <shared.h>


bool full_create_project_dir (const char *const path, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/%s", path, project_name);

    directory_target_t targets [] = 
    {
        { .base_dir = path,   .target_dir = project_name },
        { .base_dir = folder, .target_dir = "build" },
        { .base_dir = folder, .target_dir = "src" },
        { .base_dir = folder, .target_dir = "deploy" },
        { .base_dir = folder, .target_dir = "resources" },
        { .base_dir = folder, .target_dir = "tools" },
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

    if (full_source_directory_create (folder, project_name) == false)
    {
        return false;
    }

    if (full_resources_directory_create (folder, project_name) == false)
    {
        return false;
    }

    if (full_tools_directory_create (folder, project_name) == false)
    {
        return false;
    }

    return true;
}
