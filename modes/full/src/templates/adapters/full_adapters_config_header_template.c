#include <full_adapters_templates.h>
#include <stdio.h>

#define FILENAME "config.h"

static const char *const content =
"#ifndef CONFIG_H\n"
"#define CONFIG_H\n"
"\n"
"#include <sat.h>\n"
"\n"
"typedef struct\n"
"{\n"
"    // Put your configuration options here\n"
"    int dummy;\n"
"} config_t;\n"
"\n"
"sat_status_t config_load (config_t *const object, const char *const file);\n"
"\n"
"#endif /* CONFIG_H */\n";

bool full_adapters_config_header_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/config/include/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}