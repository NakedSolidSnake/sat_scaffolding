#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "my_domain_test.c"

static const char *const content = 
"#include <sat.h>\n"
"\n"
"int main (void)\n"
"{\n"
"    // put your domain test code here\n"
"    return 0;\n"
"}\n";

bool domain_tests_source_template_create (const char *const root_folder)
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