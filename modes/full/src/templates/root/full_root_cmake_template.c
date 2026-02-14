#include <full_root_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content = 
"cmake_minimum_required(VERSION 3.7.0)\n"
"project (%s)\n"
"\n"
"set (CMAKE_C_FLAGS \"-D_GNU_SOURCE -Wall -std=c99\")\n"
"set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)\n"
"set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)\n"
"set (CMAKE_BUILD_TYPE Debug)\n"
"\n"
"function (create_test binary library)\n"
"\n"
"    add_executable (${binary} ${CMAKE_CURRENT_LIST_DIR}/${binary}.c)\n"
"    target_link_libraries (${binary} PUBLIC ${library})\n"
"    add_test (NAME ${binary} COMMAND ${binary})\n"
"    set_target_properties (${binary} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests/)\n"
"\n"
"endfunction ()\n"
"\n"
"enable_testing ()\n"
"\n"
"add_subdirectory (src)\n"
;

bool full_root_cmake_template_create (const char *const root_folder, const char *const project_name)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, content, project_name);

    fclose (file);
    return true;
}