#ifndef LIBRARY_TEMPLATES_H
#define LIBRARY_TEMPLATES_H

#include <stdbool.h>

bool library_template_create (const char *const project_name);
bool library_include_template_create (const char *const project_name);
bool library_cmake_template_create (const char *const project_name, const char *const type);
bool library_gitignore_template_create (void);
bool library_tests_template_create (const char *const project_name);
bool library_tests_cmake_template_create (const char *const project_name);

#endif /* LIBRARY_TEMPLATES_H */
