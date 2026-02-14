#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

bool domain_ports_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/ports/%s", root_folder, FILENAME);
    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fclose (file);

    return true;
}