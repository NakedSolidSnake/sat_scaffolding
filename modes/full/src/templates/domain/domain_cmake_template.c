#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_subdirectory (entities)\n"
"add_subdirectory (ports)\n"
"add_subdirectory (services)\n"
"add_subdirectory (value_objects)\n"
"\n"
"add_library (domain INTERFACE)\n"
"\n"
"target_link_libraries (domain \n"
"    INTERFACE\n"
"    entities\n"
"    ports\n"
"    domain_services\n"
"    value_objects\n"
")\n";

bool domain_cmake_template_create (const char *const root_folder)
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