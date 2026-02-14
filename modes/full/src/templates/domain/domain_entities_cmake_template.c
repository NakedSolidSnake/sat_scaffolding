#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_library (entities \"\")\n"
"\n"
"target_sources (entities \n"
"    PRIVATE\n"
"    # Put here your entities source files\n"
"    ${CMAKE_CURRENT_LIST_DIR}/src/my_entity.c\n"
")\n"
"\n"
"target_include_directories (entities \n"
"    PUBLIC\n"
"    ${CMAKE_CURRENT_LIST_DIR}/include\n"
")\n"
"\n"
"target_link_libraries (entities\n"
"    PRIVATE\n"
"    # Put here your libraries to link\n"
")\n";

bool domain_entities_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/entities/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}