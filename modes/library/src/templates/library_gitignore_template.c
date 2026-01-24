#include <library_templates.h>
#include <stdio.h>

bool library_gitignore_template_create (void)
{
    bool status = false;

    FILE *file = fopen (".gitignore", "w");
    if (file != NULL)
    {
        fprintf (file,
            "# Build artifacts\n"
            "build\n"
        );

        fclose (file);
        status = true;
    }

    return status;
}