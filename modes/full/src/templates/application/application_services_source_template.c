#include <application_templates.h>
#include <stdio.h>

#define FILENAME "my_application_service.c"

bool application_services_source_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/services/src/%s", root_folder, FILENAME);
    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fclose (file);

    return true;
}