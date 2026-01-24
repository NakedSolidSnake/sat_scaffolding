#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <minimal.h>

static void print_help (const char *program_name)
{
    printf ("Usage: %s <mode>\n", program_name);
    printf ("Modes:\n");
    printf ("  --project   Create a full project scaffolding\n");
    printf ("  --minimal   Create a minimal scaffolding\n");
    printf ("  --library   Create a library scaffolding\n");
}

int main (int argc, char *argv [])
{
    if (argc < 2)
    {
        fprintf (stderr, "Cannot create the template\nUsage.: %s <mode>\n", argv [0]);
        fprintf (stderr, "Type: %s --help for more information\n", argv [0]);

        return EXIT_FAILURE;
    }

    if (strcmp (argv [1], "--help") == 0 || strcmp (argv [1], "-h") == 0)
    {
        print_help (argv [0]);
    }

    else if (strcmp (argv [1], "--project") == 0 || strcmp (argv [1], "-p") == 0)
    {
        // Full project creation logic would go here
    }
    else if (strcmp (argv [1], "--minimal") == 0 || strcmp (argv [1], "-m") == 0)
    {
        int argc_offset = 2;

        minimal_create (argv [0], argc - argc_offset, argv + argc_offset);
    }
    else if (strcmp (argv [1], "--library") == 0 || strcmp (argv [1], "-l") == 0)
    {
        // Library creation logic would go here
    }
    else
    {
        fprintf (stderr, "Unknown mode: %s\n", argv [1]);
        return EXIT_FAILURE;
    }

    return 0;
}
