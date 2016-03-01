#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "usage: useupper file\n");
        exit(1);
    }
    filename = argv[1];
    if (!freopen(filename, "r", stdin))
    {
        fprintf(stderr, "could not redirect stdin from file %s\n", filename);
        exit(1);
    }
    execl("./ex1", "ex1", 0);
    perror("could not exec\n");

    return 0;
}
