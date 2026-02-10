#include <full_templates.h>
#include <stdio.h>

#define GITIGNORE ".gitignore"

const char *const GITIGNORE_CONTENT = "build\n";

bool full_gitignore_template_create (const char *const root_folder)
{
    char file_path [2048] = {0};
    snprintf (file_path, 2047, "%s/%s", root_folder, GITIGNORE);

    FILE *file = fopen (file_path, "w");
    if (file == NULL)
    {
        fprintf (stderr, "Failed to create %s file: %s\n", GITIGNORE, file_path);
        return false;
    }

    fprintf (file, "%s", GITIGNORE_CONTENT);

    fclose (file);
    return true;
}