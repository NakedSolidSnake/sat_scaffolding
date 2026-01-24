#include <library_templates.h>
#include <stdio.h>

#define TESTS_FILENAME       "tests/%s_test.c"

static const char *content = 
{
    "#include <%s.h>\n"
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n\n"
    "int main (void)\n"
    "{\n"
    "    printf (\"Running tests for %s library...\\n\");\n\n"
    "    // Add test cases here\n\n"
    "    return EXIT_SUCCESS;\n"
    "}\n"
};

bool library_tests_template_create (const char *const project_name)
{
    bool status = false;

    char buffer [256] = {0};
    snprintf (buffer, 255, TESTS_FILENAME, project_name);

    FILE *file = fopen (buffer, "w");
    if (file != NULL)
    {
        fprintf (file, content, project_name, project_name);

        fclose (file);
        status = true;
    }

    return status;
}