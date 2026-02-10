#include <adpters_template.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define CMAKELISTS_FILE "CMakeLists.txt"

const char *const ADAPTERS_CMAKE_ROOT_CONTENT =
"add_subdirectory (config)\n"
"add_subdirectory (factories)\n"
"add_subdirectory (ports)\n"
"add_subdirectory (repositories)\n"
"\n"
"add_library (adapters INTERFACE)\n"
"\n"
"target_link_libraries (adapters\n"
"    INTERFACE\n"
"    config\n"
"    application_services\n"
")\n";


bool adapters_cmake_root_template_create (const char *const root_folder)
{
    char file_path [2048] = {0};
    snprintf (file_path, 2047, "%s/%s", root_folder, CMAKELISTS_FILE);

    FILE *file = fopen (file_path, "w");
    if (file == NULL)
    {
        fprintf (stderr, "Failed to create %s file: %s\n", CMAKELISTS_FILE, file_path);
        return false;
    }

    fprintf (file, "%s", ADAPTERS_CMAKE_ROOT_CONTENT);

    fclose (file);
    return true;
}