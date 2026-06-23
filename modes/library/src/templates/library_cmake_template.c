#include <library_templates.h>
#include <stdio.h>
#include <string.h>

const char *library_cmake_template = 
    "cmake_minimum_required (VERSION 3.7.0)\n"
    "project (\"%s\")\n"
    "\n"
    "set (CMAKE_C_FLAGS \"-D_GNU_SOURCE -Wall -std=c99\")\n"
    "set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)\n"
    "set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)\n"
    "set (CMAKE_BUILD_TYPE Debug)\n"
    "enable_testing ()\n"
    "\n"
    "add_library (%s %s \"\")\n"
    "\n"
    "target_sources (%s\n"
    "  PUBLIC\n"
    "  ${CMAKE_CURRENT_LIST_DIR}/src/%s.c\n"
    ")\n"
     "target_include_directories (%s\n"
    "  PUBLIC\n"
    "  ${CMAKE_CURRENT_LIST_DIR}/include\n"
    ")\n"
    "\n"
    "add_subdirectory (tests)\n";
    ;

bool library_cmake_template_create (const char *const project_name, const char *const type)
{
    bool status = false;

    if (strcmp (type, "static") != 0 && strcmp (type, "shared") != 0)
    {
        fprintf (stderr, "Invalid library type: %s. Use 'static' or 'shared'.\n", type);
        return false;
    }

    char *__type = (strcmp (type, "static") == 0) ? "STATIC" : "SHARED";

    FILE *file = fopen ("CMakeLists.txt", "w");
    if (file != NULL)
    {
        fprintf (file, library_cmake_template, project_name,
                                               project_name,
                                               __type,
                                               project_name,
                                               project_name,
                                               project_name);

        fclose (file);
        status = true;
    }

    return status;
}