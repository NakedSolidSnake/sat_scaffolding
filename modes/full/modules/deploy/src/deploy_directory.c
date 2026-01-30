#include <deploy_directory.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool deploy_directories_create (const char *const root_folder)
{
    char path [1024] = {0};
    snprintf (path, 1023, "%s/deploy", root_folder);

    if (mkdir (path, 0755) != 0)
    {
        fprintf (stderr, "Failed to create deploy directory: %s\n", path);
        return false;
    }

    return true;
}