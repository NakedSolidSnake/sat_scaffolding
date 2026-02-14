#include <full_root_templates.h>
#include <stdio.h>

#define FILENAME "docker-compose.yaml"

static const char *const content =
"services:\n"
"  development:\n"
"    #build: .\n"
"    image: solidcris/development:latest\n"
"    container_name: %s\n"
"    volumes:\n"
"    - .:/development\n"
"    ports:\n"
"    - \"1234:1234\"\n"
;

bool full_root_docker_compose_template_create (const char *const root_folder, const char *const project_name)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, content, project_name);

    fclose (file);
    return true;
}