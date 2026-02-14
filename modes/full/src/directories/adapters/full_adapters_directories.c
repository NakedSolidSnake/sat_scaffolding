#include <full_adapters_directories.h>
#include <full_adapters_templates.h>
#include <stdio.h>
#include <shared.h>

bool full_adapters_directory_create (const char *const base_folder, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/adapters", base_folder);

    directory_target_t targets [] = 
    {
        { .base_dir = folder, .target_dir = "factories" },
        { .base_dir = folder, .target_dir = "factories/include" },
        { .base_dir = folder, .target_dir = "factories/src" },
        { .base_dir = folder, .target_dir = "config" },
        { .base_dir = folder, .target_dir = "config/include" },
        { .base_dir = folder, .target_dir = "config/src" },
        { .base_dir = folder, .target_dir = "ports" },
        { .base_dir = folder, .target_dir = "repositories" },
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

    if (full_adapters_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (full_adapters_factory_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (full_adapters_ports_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (full_adapters_repositories_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (full_adapters_config_header_template_create (folder) == false)
    {
        return false;
    }

    if (full_adapters_config_source_template_create (folder) == false)
    {
        return false;
    }

    if (full_adapters_config_cmake_template_create (folder) == false)
    {
        return false;
    }

    return true;
}