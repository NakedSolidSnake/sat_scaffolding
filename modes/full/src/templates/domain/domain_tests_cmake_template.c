#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content = 
"create_test (my_domain_test entities)\n"
;

bool domain_tests_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/tests/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}