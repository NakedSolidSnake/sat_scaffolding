#include <minimal_templates.h>
#include <stdio.h>

#define MAIN_FILENAME       "src/main.c"

static const char *content = 
{
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n\n"
    "int main (int argc, char *argv [])\n"
    "{\n"
    "    printf (\"Hello World!\\n\");\n\n"
    "    return EXIT_SUCCESS;\n"
    "}\n"
};

bool minimal_main_template_create (void)
{
    bool status = false;

    FILE *file = fopen (MAIN_FILENAME, "w");
    if (file != NULL)
    {
        fprintf (file, "%s", content);

        fclose (file);
        status = true;
    }

    return status;
}
