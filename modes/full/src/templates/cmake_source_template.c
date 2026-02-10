#include <full_templates.h>
#include <stdio.h>

#define CMAKELISTS_FILE "CMakeLists.txt"

static const char *const CMAKELISTS_CONTENT = 
"add_subdirectory (common)\n"
"add_subdirectory (domain)\n"
"add_subdirectory (application)\n"
"add_subdirectory (adapters)\n"
"add_subdirectory (cmd)\n"
;

bool full_cmake_source_template_create (const char *const root_folder, const char *const project_name)
{
    char file_path [2048] = {0};
    snprintf (file_path, 2047, "%s/%s", root_folder, CMAKELISTS_FILE);

    FILE *file = fopen (file_path, "w");
    if (file == NULL)
    {
        fprintf (stderr, "Failed to create %s file: %s\n", CMAKELISTS_FILE, file_path);
        return false;
    }

    fprintf (file, CMAKELISTS_CONTENT, project_name);

    fclose (file);
    return true;
}