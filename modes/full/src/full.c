#include <full.h>
#include <full_directories.h>
#include <stdio.h>

bool full_create (const char *application, int argc, char *argv [])
{
    if (argc != 2 || argv == NULL)
    {
        fprintf (stderr, "Invalid arguments for project_create\n");
        fprintf (stderr, "Usage: %s --project <path> <project_name>\n", application);
        return false;
    }

    char *path = argv [0];
    char *project_name = argv [1];

    return full_create_project_dir (path, project_name);
}
