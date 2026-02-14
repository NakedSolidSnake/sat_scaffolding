#include <full_root_templates.h>
#include <stdio.h>

#define FILENAME "README.md"

static const char *const content =
"# Project %s\n"
"\n"
"## Description\n"
"\n"
"A brief description of what this project does and who it's for.\n"
"\n"
"## Getting Started\n"
"\n"
"### Prerequisites\n"
"\n"
"- CMake 3.7.0 or higher\n"
"- GCC or compatible C compiler\n"
"\n"
"### Building\n"
"\n"
"```bash\n"
"mkdir build\n"
"cd build\n"
"cmake ..\n"
"make\n"
"```\n"
"\n"
"### Running\n"
"\n"
"```bash\n"
"./bin/%s\n"
"```\n"
"\n"
"## Testing\n"
"\n"
"```bash\n"
"cd build\n"
"ctest\n"
"```\n"
"\n"
"## License\n"
"\n"
"This project is licensed under the MIT License.\n";

bool full_root_readme_template_create (const char *const root_folder, const char *const project_name)
{
    char filename [512];

    snprintf (filename, sizeof (filename), "%s/%s", root_folder, FILENAME);

    FILE *file = fopen (filename, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf (file, content, project_name, project_name);

    fclose (file);
    return true;
}