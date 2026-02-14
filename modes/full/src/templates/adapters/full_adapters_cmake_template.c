#include <full_adapters_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

const char *const content =
"add_subdirectory (config)\n"
"add_subdirectory (factories)\n"
"add_subdirectory (ports)\n"
"add_subdirectory (repositories)\n"
"\n"
"add_library (adapters INTERFACE)\n"
"\n"
"target_link_libraries (adapters\n"
"    INTERFACE\n"
"    config\n"
"    application_services\n"
")\n";

bool full_adapters_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}