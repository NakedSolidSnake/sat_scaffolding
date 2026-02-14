#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_library (value_objects \"\")\n"
"\n"
"target_sources (value_objects \n"
"    PRIVATE\n"
"    # Put here your value objects source files\n"
"    ${CMAKE_CURRENT_LIST_DIR}/src/my_value_object.c\n"
")\n"
"\n"
"target_include_directories (value_objects \n"
"    PUBLIC\n"
"    ${CMAKE_CURRENT_LIST_DIR}/include\n"
")\n"
"\n"
"target_link_libraries (value_objects\n"
"    PRIVATE\n"
"    # Put here your libraries to link\n"
")\n";

bool domain_value_objects_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/value_objects/%s", root_folder, FILENAME);
    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}