#include <application_templates.h>
#include <stdio.h>

#define FILENAME "context.h"

static const char *const content =
"#ifndef CONTEXT_H\n"
"#define CONTEXT_H\n"
"\n"
"#include <sat.h>\n"
"\n"
"typedef struct\n"
"{\n"
"    // put here your context fields\n"
"    int dummy;\n"
"} context_t;\n"
"\n"
"typedef struct\n"
"{\n"
"    // put here your context args fields\n"
"    int dummy;\n"
"} context_args_t;\n"
"\n"
"sat_status_t context_open (context_t *const object, const context_args_t *const args);\n"
"\n"
"/* Adapt for your goals */\n"
"sat_status_t context_process (context_t *const object);\n"
"\n"
"\n"
"sat_status_t context_run (context_t *const object);\n"
"sat_status_t context_close (context_t *const object);\n"
"\n"
"#endif /* CONTEXT_H */\n";

bool application_context_header_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/context/include/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}