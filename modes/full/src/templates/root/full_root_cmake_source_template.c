#include <full_root_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

bool full_root_cmake_source_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fclose (file);
    return true;
}