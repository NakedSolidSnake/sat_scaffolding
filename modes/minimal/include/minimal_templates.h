#ifndef MINIMAL_TEMPLATES_H
#define MINIMAL_TEMPLATES_H

#include <stdbool.h>

bool minimal_main_template_create (void);
bool minimal_cmake_template_create (const char *const project_name);
bool minimal_gitignore_template_create (void);

#endif /* MINIMAL_TEMPLATES_H */
