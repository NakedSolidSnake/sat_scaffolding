#include <library_templates.h>
#include <stdio.h>

#define TESTS_CMAKE_FILENAME    "tests/CMakeLists.txt"

const char *library_tests_cmake_template = 
    "add_executable (%s_tests %s_test.c)\n"
    "add_test (NAME %s_tests COMMAND %s_tests)\n"
    "target_link_libraries (%s_tests PRIVATE %s)\n";


bool library_tests_cmake_template_create (const char *const project_name)
{
    bool status = false;

    char buffer [256] = {0};
    snprintf (buffer, 255, TESTS_CMAKE_FILENAME);

    FILE *file = fopen (buffer, "w");
    if (file != NULL)
    {
        fprintf (file, library_tests_cmake_template,
                         project_name,
                         project_name,
                         project_name,
                         project_name,
                         project_name,
                         project_name);

        fclose (file);
        status = true;
    }

    return status;
}