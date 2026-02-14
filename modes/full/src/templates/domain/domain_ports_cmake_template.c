#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_library (ports INTERFACE)\n"
"\n"
"target_include_directories (ports\n"
"    INTERFACE\n"
"    ${CMAKE_CURRENT_LIST_DIR}/\n"
")\n";

bool domain_ports_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/ports/%s", root_folder, FILENAME);
    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}