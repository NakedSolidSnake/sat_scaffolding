#include <shared.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

bool create_directory (const char *const base_dir, const char *const target_dir)
{
    char base_folder [1024] = {0};

    snprintf (base_folder, 1023, "%s/%s", base_dir, target_dir);

    if (mkdir (base_folder, 0755) != 0)
    {
        fprintf (stderr, "Failed to create %s directory\n", base_folder);

        return false;
    }

    return true;
}

bool create_directories (const directory_target_list_t *const target_list)
{
    for (size_t i = 0; i < target_list->count; ++i)
    {
        const directory_target_t *target = &target_list->directories [i];

        if (create_directory (target->base_dir, target->target_dir) == false)
        {
            return false;
        }
    }

    return true;
}