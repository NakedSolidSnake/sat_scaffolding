#include <full_root_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content = 
"add_subdirectory (common)\n"
"add_subdirectory (domain)\n"
"add_subdirectory (application)\n"
"add_subdirectory (adapters)\n"
"add_subdirectory (cmd)\n"
;

bool full_root_cmake_source_template_create (const char *const root_folder)
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