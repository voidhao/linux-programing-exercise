#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("%d\n", getuid());
    printf("%s\n", getlogin());
    return 0;
}

