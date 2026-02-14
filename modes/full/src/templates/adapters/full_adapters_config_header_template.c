#include <full_adapters_templates.h>
#include <stdio.h>

#define FILENAME "config.h"

bool full_adapters_config_header_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/config/include/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fclose (file);

    return true;
}