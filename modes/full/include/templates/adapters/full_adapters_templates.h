#ifndef FULL_ADAPTERS_TEMPLATES_H
#define FULL_ADAPTERS_TEMPLATES_H

#include <stdbool.h>

bool full_adapters_cmake_template_create (const char *const root_folder);
bool full_adapters_factory_cmake_template_create (const char *const root_folder);
bool full_adapters_ports_cmake_template_create (const char *const root_folder);
bool full_adapters_repositories_cmake_template_create (const char *const root_folder);
bool full_adapters_controllers_cmake_template_create (const char *const root_folder);

bool full_adapters_config_header_template_create (const char *const root_folder);
bool full_adapters_config_source_template_create (const char *const root_folder);
bool full_adapters_config_cmake_template_create (const char *const root_folder);


#endif /* FULL_ADAPTERS_TEMPLATES_H */
