#include <adapters_directory.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool adapters_directories_create (const char *const root_folder)
{
    char path [1024] = {0};
    snprintf (path, 1023, "%s/adapters", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/adapters/factories", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters/factories directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/adapters/repositories", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters/repositories directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/adapters/ports", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters/ports directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/adapters/config", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create adapters/config directory: %s\n", path);
        return false;
    }

    return true;
}