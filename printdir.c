#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void printdir(char *dirname, int depth)
{
    DIR *dir = NULL;
    dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("opendir");
        exit(1);
    }
    chdir(dirname);
    struct dirent *sdir;
    struct stat statbuf;
    while ((sdir = readdir(dir)) != NULL)
    {
        lstat(sdir->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
            if (!strcmp("..", sdir->d_name) || !strcmp(".", sdir->d_name))
                continue;
            printf("%*s%s/\n", depth, "", sdir->d_name);
            printdir(sdir->d_name, depth+4); 
        }
        else
            printf("%*s%s\n", depth, "", sdir->d_name);
        sdir = NULL;
    }
    chdir("..");
    closedir(dir);
}
int main()
{
    char *dirname = "/home/lite/netmap";
    printdir(dirname, 0);
    return 0;
}
