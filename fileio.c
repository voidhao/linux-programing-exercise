#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int fd;
    if ((fd = open("file", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR)) == -1)
    {
        perror("open");
        exit(1);
    }
    else
        printf("open file ok\n");
    char buf[] = "hello nihao ya"; 
    write(fd, buf, sizeof(buf));
    lseek(fd, 0, SEEK_SET);
    char recv[100] = {'\0'};
    read(fd, recv, sizeof(recv));
    printf("recv: %s\n", recv);
    return 0;
}
