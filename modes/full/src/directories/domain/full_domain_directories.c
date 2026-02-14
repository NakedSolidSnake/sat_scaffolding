#include <full_domain_directories.h>
#include <domain_templates.h>
#include <stdio.h>
#include <shared.h>

bool full_domain_directory_create (const char *const base_folder, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/domain", base_folder);

    directory_target_t targets [] = 
    {
        { .base_dir = folder, .target_dir = "entities" },
        { .base_dir = folder, .target_dir = "entities/include" },
        { .base_dir = folder, .target_dir = "entities/src" },
        { .base_dir = folder, .target_dir = "ports" },
        { .base_dir = folder, .target_dir = "services" },
        { .base_dir = folder, .target_dir = "services/include" },
        { .base_dir = folder, .target_dir = "services/src" },
        { .base_dir = folder, .target_dir = "value_objects" },
        { .base_dir = folder, .target_dir = "value_objects/include" },
        { .base_dir = folder, .target_dir = "value_objects/src" },
        { .base_dir = folder, .target_dir = "tests" },
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

    if (domain_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (domain_entities_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (domain_entities_source_template_create (folder) == false)
    {
        return false;
    }

    if (domain_ports_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (domain_services_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (domain_services_source_template_create (folder) == false)
    {
        return false;
    }

    if (domain_value_objects_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (domain_value_objects_source_template_create (folder) == false)
    {
        return false;
    }

    if (domain_tests_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (domain_tests_source_template_create (folder) == false)
    {
        return false;
    }

    return true;
}