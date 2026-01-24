#include <library.h>
#include <library_directories.h>
#include <stdio.h>

bool library_create (const char *application, int argc, char *argv [])
{
    if (argc != 3 || argv == NULL)
    {
        fprintf (stderr, "Invalid arguments for library_create\n");
        fprintf (stderr, "Usage: %s --library <type> <path> <project_name>\n", application);
        fprintf (stderr, "Where <type> is 'static' or 'shared'\n");
        return false;
    }

    char *type = argv [0];
    char *path = argv [1];
    char *project_name = argv [2];

    return library_create_project_dir (type, path, project_name);
}
