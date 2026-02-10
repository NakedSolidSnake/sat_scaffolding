#include <full_templates.h>
#include <stdio.h>

#define DOCKER_COMPOSE "docker-compose.yaml"

const char *const DOCKER_COMPOSE_CONTENT =
"version: \"3\"\n"
"services:\n"
"  development:\n"
"    #build: .\n"
"    image: solidcris/development:latest\n"
"    container_name: %s\n"
"    volumes:\n"
"    - .:/development\n"
"    ports:\n"
"    - \"1234:1234\"\n";

bool full_docker_compose_template_create (const char *const root_folder, const char *const project_name)
{
    char file_path [2048] = {0};
    snprintf (file_path, 2047, "%s/%s", root_folder, DOCKER_COMPOSE);

    FILE *file = fopen (file_path, "w");
    if (file == NULL)
    {
        fprintf (stderr, "Failed to create %s file: %s\n", DOCKER_COMPOSE, file_path);
        return false;
    }

    fprintf (file, DOCKER_COMPOSE_CONTENT, project_name);

    fclose (file);
    return true;
}