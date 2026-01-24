#include <minimal.h>
#include <minimal_directories.h>
#include <stdio.h>

bool minimal_create (const char *application, int argc, char *argv [])
{
    if (argc != 2 || argv == NULL)
    {
        fprintf (stderr, "Invalid arguments for minimal_create\n");
        fprintf (stderr, "Usage: %s --minimal <path> <project_name>\n", application);
    }

    char *path = argv [0];
    char *project_name = argv [1];

    minimal_create_project_dir (path, project_name);

    return true;
}
