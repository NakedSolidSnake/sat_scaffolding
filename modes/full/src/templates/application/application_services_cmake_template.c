#include <application_templates.h>
#include <stdio.h>

#define FILENAME "CMakeLists.txt"

static const char *const content =
"# Add your services here\n"
"\n"
"add_library (application_services INTERFACE)\n"
"\n"
"target_link_libraries (application_services \n"
"    INTERFACE\n"
"    #Put your service libraries here\n"
")\n";


bool application_services_cmake_template_create (const char *const root_folder)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/services/%s", root_folder, FILENAME);
    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, "%s", content);

    fclose (file);

    return true;
}