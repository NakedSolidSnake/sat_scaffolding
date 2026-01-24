#include <minimal_directories.h>
#include <minimal_templates.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool minimal_create_project_dir (const char *const path, const char *const project_name)
{
    char folder [1024] = {0};
    snprintf (folder, 1023, "%s/%s", path, project_name);

    if (mkdir (folder, 0755) != 0)
    {
        fprintf (stderr, "Failed to create project directory: %s\n", folder);
        return false;
    }

    if (chdir (folder) != 0)
    {
        fprintf (stderr, "Failed to change directory to: %s\n", folder);
        return false;
    }

    if (minimal_cmake_template_create (project_name) == false)
    {
        fprintf (stderr, "Failed to create CMakeLists.txt\n");
        return false;
    }

    if (mkdir ("build", 0755) != 0)
    {
        fprintf (stderr, "Failed to create build directory\n");
        return false;
    }

    if (mkdir ("src", 0755) != 0)
    {
        fprintf (stderr, "Failed to create src directory\n");
        return false;
    }

    if (minimal_main_template_create () == false)
    {
        fprintf (stderr, "Failed to create main.c\n");
        return false;
    }

    if (minimal_gitignore_template_create () == false)
    {
        fprintf (stderr, "Failed to create .gitignore\n");
        return false;
    }

    fprintf (stdout, "Minimal project '%s' created successfully at %s\n", project_name, folder);

    return true;
}
