#include <application_templates.h>
#include <stdio.h>

#define FILENAME "context.h"

bool application_context_header_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/context/include/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fclose (file);

    return true;
}