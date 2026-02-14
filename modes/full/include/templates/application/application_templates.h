#ifndef APPLICATION_TEMPLATES_H
#define APPLICATION_TEMPLATES_H

#include <stdbool.h>

bool application_cmake_template_create (const char *const root_folder);
bool application_context_cmake_template_create (const char *const root_folder);
bool application_context_header_template_create (const char *const root_folder);
bool application_context_source_template_create (const char *const root_folder);
bool application_services_cmake_template_create (const char *const root_folder);
bool application_services_source_template_create (const char *const root_folder);
bool application_tests_cmake_template_create (const char *const root_folder);
bool application_tests_source_template_create (const char *const root_folder);

#endif /* APPLICATION_TEMPLATES_H */
