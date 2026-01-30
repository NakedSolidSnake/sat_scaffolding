#include <domain_directory.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool domain_directories_create (const char *const root_folder)
{
    char path [1024] = {0};
    snprintf (path, 1023, "%s/domain", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create domain directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/domain/models", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create domain/models directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/domain/ports", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create domain/ports directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/domain/services", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create domain/services directory: %s\n", path);
        return false;
    }

    return true;
}