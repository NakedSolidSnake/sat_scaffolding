#include <full_directories.h>
#include <full_templates.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool full_tools_directories_create (const char *const root_folder)
{
    char path [1024] = {0};
    snprintf (path, 1023, "%s/tools", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create tools directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/tools/scripts", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create tools/scripts directory: %s\n", path);
        return false;
    }

    snprintf (path, 1023, "%s/tools/sql", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create tools/sql directory: %s\n", path);
        return false;
    }

    return true;
}