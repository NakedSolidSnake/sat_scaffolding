#include <library_directories.h>
#include <library_templates.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool library_create_project_dir (const char *const type, const char *const path, const char *const project_name)
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

    if (library_cmake_template_create (project_name, type) == false)
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

    if (library_template_create (project_name) == false)
    {
        fprintf (stderr, "Failed to create %s.c\n", project_name);
        return false;
    }

    if (mkdir ("include", 0755) != 0)
    {
        fprintf (stderr, "Failed to create include directory\n");
        return false;
    }

    if (library_include_template_create (project_name) == false)
    {
        fprintf (stderr, "Failed to create %s.h\n", project_name);
        return false;
    }

    if (library_gitignore_template_create () == false)
    {
        fprintf (stderr, "Failed to create .gitignore\n");
        return false;
    }

    if (mkdir ("tests", 0755) != 0)
    {
        fprintf (stderr, "Failed to create tests directory\n");
        return false;
    }

    if (library_tests_template_create (project_name) == false)
    {
        fprintf (stderr, "Failed to create tests/%s_test.c\n", project_name);
        return false;
    }

    if (library_tests_cmake_template_create (project_name) == false)
    {
        fprintf (stderr, "Failed to create tests/CMakeLists.txt\n");
        return false;
    }

    fprintf (stdout, "Library project '%s' created successfully at %s\n", project_name, folder);

    return true;
}
