#include <application_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_library (context \"\")\n"
"\n"
"target_sources (context \n"
"    PRIVATE\n"
"    ${CMAKE_CURRENT_LIST_DIR}/src/context.c\n"
")\n"
"\n"
"target_include_directories (context \n"
"    PUBLIC\n"
"    ${CMAKE_CURRENT_LIST_DIR}/include\n"
")\n"
"\n"
"target_link_libraries (context\n"
"    PRIVATE\n"
"    # Put here your libraries to link\n"
")\n";

bool application_context_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/context/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}