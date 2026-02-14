#include <application_templates.h>
#include <stdio.h>
    
#define FILENAME "context.c"

static const char *const content =
"#include <context.h>\n"
"\n"
"static sat_status_t context_is_args_valid (const context_args_t *const args);\n"
"\n"
"sat_status_t context_open (context_t *const object, const context_args_t *const args)\n"
"{\n"
"    sat_status_t status = sat_status_success (&status);\n"
"\n"
"    do\n"
"    {\n"
"        // Put your validation logic here\n"
"    } while (false);\n"
"\n"
"    return status;\n"
"}\n"
"\n"
"sat_status_t context_process (context_t *const object)\n"
"{\n"
"    sat_status_t status = sat_status_success (&status);\n"
"\n"
"    do\n"
"    {\n"
"        // Put your validation logic here\n"
"        \n"
"    } while (false);\n"
"\n"
"    return status;\n"
"}\n"
"\n"
"sat_status_t context_run (context_t *const object)\n"
"{\n"
"    sat_status_t status = sat_status_success (&status);\n"
"\n"
"    do\n"
"    {\n"
"        // Put your validation logic here\n"
"        \n"
"    } while (false);\n"
"\n"
"    return status;\n"
"}\n"
"\n"
"sat_status_t context_close (context_t *const object)\n"
"{\n"
"    sat_status_t status = sat_status_success (&status);\n"
"\n"
"    do\n"
"    {\n"
"        // Put your validation logic here\n"
"        \n"
"    } while (false);\n"
"\n"
"    return status;\n"
"}\n"
"\n"
"static sat_status_t context_is_args_valid (const context_args_t *const args)\n"
"{\n"
"    sat_status_t status = sat_status_success (&status);\n"
"\n"
"    do\n"
"    {\n"
"        // Put your validation logic here\n"
"        \n"
"    } while (false);\n"
"\n"
"    return status;\n"
"}\n";

bool application_context_source_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/context/src/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}