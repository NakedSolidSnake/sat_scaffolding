#include <library_templates.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define INCLUDE_FILENAME    "include/%s.h"

static const char *content = 
{
    "#ifndef %s_H\n"
    "#define %s_H\n\n"
    "int %s_function (void);\n\n"
    "#endif /* %s_H */\n"
};

bool library_include_template_create (const char *const project_name)
{
    bool status = false;

    char header_guard [256] = {0};
    char buffer [256] = {0};

    for (size_t i = 0; i < strlen (project_name) && i < 250; i++)
    {
        header_guard [i] = toupper (project_name [i]);
    }

    snprintf (buffer, 255, INCLUDE_FILENAME, project_name);

    FILE *file = fopen (buffer, "w");
    if (file != NULL)
    {
        fprintf (file, content,
            header_guard,
            header_guard,
            project_name,
            header_guard
        );

        fclose (file);
        status = true;
    }

    return status;
}