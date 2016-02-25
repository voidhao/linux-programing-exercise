#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int debug;
int main(int argc, char *argv[])
{
    if (argc > 1)
        if (!strcmp(argv[1], "-d"))
            debug = 1;
    if (debug)
        printf("debug, line: %d, file: %s, date: %s, time: %s\n", __LINE__, __FILE__, __DATE__, __TIME__);
    return 0;
}
