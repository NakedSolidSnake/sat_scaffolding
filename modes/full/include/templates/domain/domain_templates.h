#ifndef DOMAIN_TEMPLATES_H
#define DOMAIN_TEMPLATES_H

#include <stdbool.h>

bool domain_cmake_template_create (const char *const root_folder);
bool domain_entities_cmake_template_create (const char *const root_folder);
bool domain_entities_source_template_create (const char *const root_folder);
bool domain_ports_cmake_template_create (const char *const root_folder);
bool domain_services_cmake_template_create (const char *const root_folder);
bool domain_services_source_template_create (const char *const root_folder);
bool domain_value_objects_cmake_template_create (const char *const root_folder);
bool domain_value_objects_source_template_create (const char *const root_folder);

#endif /* DOMAIN_TEMPLATES_H */
