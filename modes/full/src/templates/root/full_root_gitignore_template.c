#include <full_root_templates.h>
#include <stdio.h>

#define FILENAME ".gitignore"

static const char *const content = "build\n";

bool full_root_gitignore_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);
    return true;
}