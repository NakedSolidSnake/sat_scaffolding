#include <workspace.h>
#include <workspace_directories.h>
#include <stdio.h>

bool workspace_create (const char *application, int argc, char *argv [])
{
    if (argc != 2 || argv == NULL)
    {
        fprintf (stderr, "Invalid arguments for workspace_create\n");
        fprintf (stderr, "Usage: %s --workspace <path> <project_name>\n", application);
        return false;
    }

    char *path = argv [0];
    char *project_name = argv [1];

    if (workspace_create_project_dir (path, project_name) == false)
    {
        // fprintf (stdout, "Workspace project '%s' cannot be created\n", project_name);

        // system ("rm -rf %s/%s", path, project_name);

        return false;
    }

    fprintf (stdout, "Workspace project '%s' created successfully\n", project_name);

    return true;
}
