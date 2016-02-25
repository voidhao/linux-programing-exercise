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
    if ((fd = open("file", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR)) == -1)
    {
        perror("open");
        exit(1);
    }
    else
        printf("file ok\n");
    struct stat sbuf;  //不能定义为指针，因为要用这个结构去存储从函数返回的内容
    fstat(fd, &sbuf);

    if (S_ISREG(sbuf.st_mode))
        printf("is a file\n");
    int res;
    off_t ofset = 0;
    res = lseek(fd, ofset, SEEK_END);
    char buf[] = "hello i am ok\n";
    write(fd, buf, strlen(buf)); 
    return 0;
}
