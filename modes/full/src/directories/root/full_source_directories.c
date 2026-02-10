#include <full_source_directories.h>
#include <full_adapters_directories.h>
#include <full_application_directories.h>
#include <full_common_directories.h>
#include <full_domain_directories.h>
#include <stdio.h>
#include <shared.h>

bool full_source_directory_create (const char *const base_folder, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/src", base_folder);

    directory_target_t targets [] = 
    {
        { .base_dir = folder, .target_dir = "adapters" },
        { .base_dir = folder, .target_dir = "application" },
        { .base_dir = folder, .target_dir = "cmd" },
        { .base_dir = folder, .target_dir = "common" },
        { .base_dir = folder, .target_dir = "domain" },
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

    if (full_adapters_directory_create (folder, project_name) == false)
    {
        return false;
    }

    if (full_application_directory_create (folder, project_name) == false)
    {
        return false;
    }

    if (full_common_directory_create (folder, project_name) == false)
    {
        return false;
    }

    if (full_domain_directory_create (folder, project_name) == false)
    {
        return false;
    }

    return true;
}