#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
int main()
{
    char buf[1024];
    int in, out;
    if ((in = open("/home/lite/file.in", O_RDONLY|O_CREAT, S_IRUSR|S_IWUSR)) == -1)
    {
        perror("open_in");
        exit(1);
    }      
    if ((out = open("/home/lite/file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR)) == -1)
    {
        perror("open_out");
        exit(1);
    }      

    int nread;
    while ((nread = read(in, &buf, sizeof(buf))) > 0)
        write(out, &buf, nread);

	return 0;
}
