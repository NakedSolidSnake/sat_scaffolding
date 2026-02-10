#ifndef FULL_TEMPLATES_H
#define FULL_TEMPLATES_H

#include <stdbool.h>

bool full_gitignore_template_create (const char *const root_folder);
bool full_cmake_template_create (const char *const root_folder, const char *const project_name);
bool full_dockerfile_template_create (const char *const root_folder);
bool full_docker_compose_template_create (const char *const root_folder, const char *const project_name);
bool full_readme_template_create (const char *const root_folder, const char *const project_name);

bool full_cmake_source_template_create (const char *const root_folder, const char *const project_name);

#endif /* FULL_TEMPLATES_H */
