#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
void handler(int sig)
{
    signal(SIGINT, SIG_DFL);
    printf("sig\n");
}
int main()
{
    int sig = SIGINT;
    signal(sig, handler);
    while (1)
    {
        printf("hi\n");
        sleep(1);
    } 
    return 0;
}
