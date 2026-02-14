#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"add_library (domain_services \"\")\n"
"\n"
"target_sources (domain_services \n"
"    PRIVATE\n"
"    # Put here your domain services source files\n"
"    ${CMAKE_CURRENT_LIST_DIR}/src/my_service.c\n"
")\n"
"\n"
"target_include_directories (domain_services \n"
"    PUBLIC\n"
"    ${CMAKE_CURRENT_LIST_DIR}/include\n"
")\n"
"\n"
"target_link_libraries (domain_services\n"
"    PRIVATE\n"
"    # Put here your libraries to link\n"
")\n";

bool domain_services_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/services/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}