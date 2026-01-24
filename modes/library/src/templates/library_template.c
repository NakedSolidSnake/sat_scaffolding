#include <library_templates.h>
#include <stdio.h>

#define LIBRARY_FILENAME       "src/%s.c"

static const char *content = 
{
    "#include <%s.h>\n"
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n\n"
    "void %s_function (void)\n"
    "{\n"
    "    printf (\"Hello World!\\n\");\n\n"
    "}\n"
};

bool library_template_create (const char *const project_name)
{
    bool status = false;

    char buffer [256] = {0};
    snprintf (buffer, 255, LIBRARY_FILENAME, project_name);

    FILE *file = fopen (buffer, "w");
    if (file != NULL)
    {
        fprintf (file, content, project_name, project_name);

        fclose (file);
        status = true;
    }

    return status;
}
