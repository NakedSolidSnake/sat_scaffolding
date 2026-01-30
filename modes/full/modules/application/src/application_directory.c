#include <application_directory.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool application_directories_create (const char *const root_folder)
{
    char path [1024] = {0};
    snprintf (path, 1023, "%s/application", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create application directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/application/context", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create application/context directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/application/services", root_folder);
    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create application/services directory: %s\n", path);
        return false;
    }

    return true;
}