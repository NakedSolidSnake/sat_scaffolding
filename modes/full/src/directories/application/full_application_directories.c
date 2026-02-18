#include <full_application_directories.h>
#include <application_templates.h>
#include <stdio.h>
#include <shared.h>

bool full_application_directory_create (const char *const base_folder, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/application", base_folder);
    directory_target_t targets [] = 
    {
        { .base_dir = folder, .target_dir = "context" },
        { .base_dir = folder, .target_dir = "context/include" },
        { .base_dir = folder, .target_dir = "context/src" },
        { .base_dir = folder, .target_dir = "services" },
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

    if (application_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (application_context_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (application_context_header_template_create (folder) == false)
    {
        return false;
    }

    if (application_context_source_template_create (folder) == false)
    {
        return false;
    }

    if (application_services_cmake_template_create (folder) == false)
    {
        return false;
    }

    if (application_tests_cmake_template_create (folder) == false)
    {
        return false;
    }

    return true;
}