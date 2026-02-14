#include <application_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_subdirectory (context)\n"
"add_subdirectory (services)\n"
"add_subdirectory (tests)\n"
"\n"
"add_library (application INTERFACE)\n"
"\n"
"target_link_libraries (application \n"
"    INTERFACE\n"
"    context\n"
"    application_services\n"
")\n";

bool application_cmake_template_create (const char *const root_folder)
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