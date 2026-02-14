#include <cmd_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *content =
"add_executable (%s \"\")\n"
"\n"
"target_sources (%s\n"
"    PRIVATE\n"
"    ${CMAKE_CURRENT_LIST_DIR}/main.c\n"
")\n"
"\n"
"target_include_directories (%s\n"
"    PUBLIC\n"
")\n"
"\n"
"target_link_libraries (%s\n"
"    PRIVATE\n"
"    # Put here your libraries to link\n"
"    adapters\n"
")\n";

bool cmd_cmake_template_create (const char *const root_folder, const char *const project_name)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/cmd/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, content, project_name,
                            project_name,
                            project_name,
                            project_name);

    fclose (file);

    return true;
}