#include <full_templates.h>
#include <stdio.h>

#define README_FILE "README.md"

const char *const README_CONTENT =
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

bool full_readme_template_create (const char *const root_folder, const char *const project_name)
{
    char file_path [2048] = {0};
    snprintf (file_path, 2047, "%s/%s", root_folder, README_FILE);

    FILE *file = fopen (file_path, "w");
    if (file == NULL)
    {
        fprintf (stderr, "Failed to create %s file: %s\n", README_FILE, file_path);
        return false;
    }

    fprintf (file, README_CONTENT, project_name, project_name);

    fclose (file);
    return true;
}