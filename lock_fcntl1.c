#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILE_NAME "test_lock"
int main()
{
    struct flock l1;
    struct flock l2;
    int fd = open(FILE_NAME, O_RDWR | O_CREAT, 0666);
    int cnt;
    if (!fd)
    {
        fprintf(stderr, "unable to open %s for read/write\n", FILE_NAME);
        exit(1);
    }
    for (cnt=0; cnt<100; cnt++)
        write(fd, "A", 1);
    l1.l_type = F_RDLCK;
    l1.l_whence = SEEK_SET;
    l1.l_start = 10;
    l1.l_len = 20;

    l2.l_type = F_WRLCK;
    l2.l_whence = SEEK_SET;
    l2.l_start = 40;
    l2.l_len = 10;

    printf("process %d locking file\n", getpid());
    int res = fcntl(fd, F_SETLK, &l1);
    if (res == -1)
        fprintf(stderr, "failed to lock region 1\n");
    res = fcntl(fd, F_SETLK, &l2);
    if (res == -1)
        fprintf(stderr, "failed to lock region 2\n");
    
    sleep(60);

    printf("process %d closing file\n", getpid());
    close(fd);

    return 0;
}
