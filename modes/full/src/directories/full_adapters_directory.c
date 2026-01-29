#include <full_directories.h>
#include <full_templates.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool full_adapters_directories_create (const char *const root_folder)
{
    char path [1024] = {0};
    snprintf (path, 1023, "%s/adapters", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/adapters/controllers", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters/controllers directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/adapters/repositories", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters/repositories directory: %s\n", path);
        return false;
    }

    return true;
}