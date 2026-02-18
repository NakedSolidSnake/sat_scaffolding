#include <workspace_directories.h>
#include <stdio.h>
#include <shared.h>


bool workspace_create_project_dir (const char *const path, const char *const project_name)
{
    char folder [1024] = {0};

    snprintf (folder, 1023, "%s/%s", path, project_name);

    directory_target_t targets [] = 
    {
        { .base_dir = path,   .target_dir = project_name },
        { .base_dir = folder, .target_dir = "build" },
        { .base_dir = folder, .target_dir = "services" },
        { .base_dir = folder, .target_dir = "shared" },
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

    // if (full_source_directory_create (folder, project_name) == false)
    // {
    //     return false;
    // }

    // if (full_resources_directory_create (folder, project_name) == false)
    // {
    //     return false;
    // }

    // if (full_tools_directory_create (folder, project_name) == false)
    // {
    //     return false;
    // }

    // if (full_root_gitignore_template_create (folder) == false)
    // {
    //     return false;
    // }

    // if (full_root_cmake_template_create (folder, project_name) == false)
    // {
    //     return false;
    // }

    // if (full_root_dockerfile_template_create (folder) == false)
    // {
    //     return false;
    // }

    // if (full_root_docker_compose_template_create (folder, project_name) == false)
    // {
    //     return false;
    // }

    // if (full_root_readme_template_create (folder, project_name) == false)
    // {
    //     return false;
    // }

    return true;
}
