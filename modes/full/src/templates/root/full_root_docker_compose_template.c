#include <full_root_templates.h>
#include <stdio.h>

#define FILENAME "docker-compose.yaml"

bool full_root_docker_compose_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fclose (file);
    return true;
}