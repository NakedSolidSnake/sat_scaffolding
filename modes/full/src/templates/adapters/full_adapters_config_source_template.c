#include <full_adapters_templates.h>
#include <stdio.h>

#define FILENAME "config.c"

static const char *const content =
"#include <config.h>\n"
"\n"
"sat_status_t config_load (config_t *const object, const char *const file)\n"
"{\n"
"    sat_status_t status;\n"
"    sat_properties_t properties;\n"
"\n"
"    do\n"
"    {\n"
"        sat_status_break_if_null (status, object, \"config_t is null\");\n"
"\n"
"        /*\n"
"            Map file format to properties object\n"
"        */\n"
"\n"
"        sat_properties_map_t map = \n"
"        {\n"
"            // Map your items here\n"
"        };\n"
"\n"
"        status = sat_properties_open (&properties, (char *)file);\n"
"        sat_status_break_on_error (status);\n"
"\n"
"        status = sat_properties_read (&properties, &map);\n"
"\n"
"    } while (false);\n"
"\n"
"    return status;\n"
"}\n";

bool full_adapters_config_source_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/config/src/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}