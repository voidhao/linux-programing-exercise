#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
    int file_desc;
    int save_errno;
    file_desc = open("/tmp/LCK.test", O_RDWR | O_CREAT | O_EXCL, 0444);
    if (file_desc == -1)
    {
        save_errno = errno;
        printf("open filed with error %d\n", save_errno);
    }
    else
        printf("open success\n");
    return 0;
}
