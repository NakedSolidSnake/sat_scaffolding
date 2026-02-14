#include <domain_templates.h>
#include <stdio.h>

#define FILENAME "my_value_object.c"

bool domain_value_objects_source_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/value_objects/src/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fclose (file);

    return true;
}