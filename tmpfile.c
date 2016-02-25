#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfd;

    filename = tmpnam(tmpname);
    printf("tmp file name is %s\n", filename);
    tmpfd = tmpfile();
    if (tmpfd)
        printf("open a tmpfile ok\n");
    else
        perror("tmpfile");

    char filen[] = "tmp_XXXXXX"; //这一点传给mkstemp的必须是一个数组，如果传字符串指针的话会段错误
    printf("%ld, %ld\n", sizeof(filen), strlen(filen));
    int fd = mkstemp(filen);
    if (fd != -1)
        printf("mkstemp ok\n");
    else
        perror("mktemp");
    unlink(filen);
    
    close(fd);
    return 0;
}
