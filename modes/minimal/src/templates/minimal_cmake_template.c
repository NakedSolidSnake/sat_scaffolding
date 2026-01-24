#include <minimal_templates.h>
#include <stdio.h>

const char *minimal_cmake_template = 
    "cmake_minimum_required (VERSION 4.0.3)\n"
    "project (\"%s\")\n"
    "\n"
    "set (CMAKE_C_FLAGS \"-D_GNU_SOURCE -Wall -std=c99\")\n"
    "set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)\n"
    "set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)\n"
    "set (CMAKE_BUILD_TYPE Debug)\n"
    "\n"
    "add_executable (%s \"\")\n"
    "\n"
    "target_sources (%s\n"
    "  PUBLIC\n"
    "  ${CMAKE_CURRENT_LIST_DIR}/src/main.c\n"
    ")\n";

bool minimal_cmake_template_create (const char *const project_name)
{
    bool status = false;

    FILE *file = fopen ("CMakeLists.txt", "w");
    if (file != NULL)
    {
        fprintf (file, minimal_cmake_template, project_name, project_name, project_name);

        fclose (file);
        status = true;
    }

    return status;
}