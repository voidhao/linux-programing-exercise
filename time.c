#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    time_t times;
    times = time(0);
    printf("the time is %ld\n", times);
    struct tm *tm_ptr;
    tm_ptr = localtime(&times);
    printf("date: %02d/%02d/%02d\n", tm_ptr->tm_year, tm_ptr->tm_mon, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    printf("%s\n", ctime(&times));

    return 0;
}

