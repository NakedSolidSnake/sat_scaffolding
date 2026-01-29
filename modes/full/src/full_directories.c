#include <full_directories.h>
#include <full_templates.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool full_create_project_dir (const char *const path, const char *const project_name)
{
    char folder [1024] = {0};
    snprintf (folder, 1023, "%s/%s", path, project_name);

    if (mkdir (folder, 0755) != 0)
    {
        fprintf (stderr, "Failed to create project directory: %s\n", folder);
        return false;
    }

    if (full_adapters_directories_create (folder) == false)
    {
        return false;
    }

    if (full_application_directories_create (folder) == false)
    {
        return false;
    }

    if (full_cmd_directories_create (folder) == false)
    {
        return false;
    }

    if (full_common_directories_create (folder) == false)
    {
        return false;
    }

    if (full_config_directories_create (folder) == false)
    {
        return false;
    }

    if (full_deploy_directories_create (folder) == false)
    {
        return false;
    }

    if (full_domain_directories_create (folder) == false)
    {
        return false;
    }

    if (full_resources_directories_create (folder) == false)
    {
        return false;
    }

    if (full_tools_directories_create (folder) == false)
    {
        return false;
    }

    fprintf (stdout, "Full project '%s' created successfully at %s\n", project_name, folder);

    return true;
}
