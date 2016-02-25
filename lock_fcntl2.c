#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_NAME "test_lock"
void show_lock_info(struct flock *flock)
{
    printf("\tl_type: %d, l_whence: %d, l_start: %ld, l_len: %ld, l_pid: %d\n", flock->l_type, 
            flock->l_whence, flock->l_start, flock->l_len, flock->l_pid);
}
int main()
{
    int fd;
    struct flock test;
    fd = open(FILE_NAME, O_RDWR | O_CREAT, 0666);
    if (!fd)
    {
        fprintf(stderr, "unable to open %s for read/write\n", FILE_NAME);
        exit(1);
    }

    int i;
    for (i=0; i<100; i+=5)
    {
        test.l_type = F_WRLCK;
        test.l_whence = SEEK_SET;
        test.l_start = i;
        test.l_len = 5;
        test.l_pid = -1;
        printf("testing F_WRLCK on region from %d to %d\n", i, i+5);
        int res = fcntl(fd, F_GETLK, &test); 
        if (res == -1)
        {
            fprintf(stderr, "F_GETLK failed\n");
            exit(1);
        }
        if (test.l_pid != -1)
        {
            printf("lock would fail. F_GETLK returned\n");
            show_lock_info(&test);
        }
        else
            printf("F_GETLK - lock would succeed.\n");

        test.l_type = F_RDLCK;
        test.l_whence = SEEK_SET;
        test.l_start = i;
        test.l_len = 5;
        test.l_pid = -1;
        printf("testing F_RDLCK on region from %d to %d\n", i, i+5);
        res = fcntl(fd, F_GETLK, &test);
        if (res == -1)
        {
            fprintf(stderr, "F_GETLK failed\n");
            exit(1);
        }
        if (test.l_pid != -1)
        {
            printf("lock would fail. F_GETLK returned\n");
            show_lock_info(&test);
        }
        else
            printf("F_GETLK - lock would succeed.\n");
    }
    close(fd);
    return 0;
}
