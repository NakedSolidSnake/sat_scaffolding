#ifndef SHARED_H
#define SHARED_H

#include <stdbool.h>
#include <stddef.h>

typedef struct
{
    const char *base_dir;
    const char *target_dir;    
} directory_target_t;

typedef struct
{
    directory_target_t *directories;
    size_t count;
} directory_target_list_t;

bool create_directories (const directory_target_list_t *const target_list);

bool create_directory (const char *const base_dir, const char *const target_dir);
// bool create_file (const char *const file_path, const char *const content);

#endif /* SHARED_H */
