#include <full_adapters_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_library (config \"\")\n"
"\n"
"target_sources (config \n"
"    PRIVATE\n"
"    ${CMAKE_CURRENT_LIST_DIR}/src/config.c\n"
")\n"
"\n"
"target_include_directories (config \n"
"    PUBLIC\n"
"    ${CMAKE_CURRENT_LIST_DIR}/include\n"
")\n"
"\n"
"target_link_libraries (config\n"
"    PRIVATE\n"
"    # Put here your libraries to link\n"
")\n";

bool full_adapters_config_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/config/%s", root_folder, FILENAME);
    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}