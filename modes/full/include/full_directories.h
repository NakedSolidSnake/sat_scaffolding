#ifndef FULL_DIRECTORIES_H
#define FULL_DIRECTORIES_H

#include <stdbool.h>

bool full_create_project_dir (const char *const path, const char *const project_name);

bool full_adapters_directories_create (const char *const root_folder);
bool full_application_directories_create (const char *const root_folder);
bool full_cmd_directories_create (const char *const root_folder);
bool full_common_directories_create (const char *const root_folder);
bool full_config_directories_create (const char *const root_folder);
bool full_deploy_directories_create (const char *const root_folder);
bool full_domain_directories_create (const char *const root_folder);
bool full_resources_directories_create (const char *const root_folder);
bool full_tools_directories_create (const char *const root_folder);

#endif /* FULL_DIRECTORIES_H */
