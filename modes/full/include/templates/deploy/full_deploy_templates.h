#ifndef FULL_DEPLOY_TEMPLATES_H
#define FULL_DEPLOY_TEMPLATES_H

#include <stdbool.h>

bool full_deploy_dockerfile_template_create (const char *const root_folder);
bool full_deploy_docker_compose_template_create (const char *const root_folder);
bool full_deploy_generate_template_create (const char *const root_folder);

#endif /* FULL_DEPLOY_TEMPLATES_H */
