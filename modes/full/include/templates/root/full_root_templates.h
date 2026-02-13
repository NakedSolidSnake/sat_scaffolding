#ifndef FULL_ROOT_TEMPLATES_H
#define FULL_ROOT_TEMPLATES_H

#include <stdbool.h>

bool full_root_gitignore_template_create (const char *const root_folder);
bool full_root_cmake_template_create (const char *const root_folder);
bool full_root_dockerfile_template_create (const char *const root_folder);
bool full_root_docker_compose_template_create (const char *const root_folder);
bool full_root_readme_template_create (const char *const root_folder);
bool full_root_cmake_source_template_create (const char *const root_folder);

#endif /* FULL_ROOT_TEMPLATES_H */
