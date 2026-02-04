#include <full_directories.h>
#include <full_templates.h>
#include <adapters_directory.h>
#include <application_directory.h>
#include <cmd_directory.h>
#include <common_directory.h>
#include <deploy_directory.h>
#include <domain_directory.h>
#include <resources_directory.h>
#include <tools_directory.h>
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

    if (adapters_directories_create (folder) == false)
    {
        return false;
    }

    if (application_directories_create (folder) == false)
    {
        return false;
    }

    if (cmd_directories_create (folder) == false)
    {
        return false;
    }

    if (common_directories_create (folder) == false)
    {
        return false;
    }

    if (deploy_directories_create (folder) == false)
    {
        return false;
    }
    
    if (domain_directories_create (folder) == false)
    {
        return false;
    }

    if (resources_directories_create (folder) == false)
    {
        return false;
    }

    if (tools_directories_create (folder) == false)
    {
        return false;
    }

    fprintf (stdout, "Full project '%s' created successfully at %s\n", project_name, folder);

    return true;
}
