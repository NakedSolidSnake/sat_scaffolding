#include <cmd_templates.h>
#include <stdio.h>

#define FILENAME "main.c"

static const char *const content =
"#include <config.h>\n"
"\n"
"int main (int argc, char *argv [])\n"
"{\n"
"    sat_status_t status;\n"
"    config_t config;\n"
"\n"
"    // Put your logic here\n"
"\n"
"    return 0;\n"
"}\n";

bool cmd_main_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/cmd/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}