#include <full.h>
#include <full_root_directories.h>
#include <stdio.h>

bool full_create (const char *application, int argc, char *argv [])
{
    if (argc != 2 || argv == NULL)
    {
        fprintf (stderr, "Invalid arguments for project_create\n");
        fprintf (stderr, "Usage: %s --full <path> <project_name>\n", application);
        return false;
    }

    char *path = argv [0];
    char *project_name = argv [1];

    if (full_create_project_dir (path, project_name) == false)
    {
        // fprintf (stdout, "Full project '%s' cannot be created\n", project_name);

        // system ("rm -rf %s/%s", path, project_name);

        return false;
    }

    fprintf (stdout, "Full project '%s' created successfully\n", project_name);

    return true;
}
