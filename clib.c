#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp = NULL;
    fp = fopen("hello", "w+");
    char buf[] = "hello nihao ya";
    fwrite(buf, strlen(buf)+1, 1, fp);
    fflush(fp);  
    fseek(fp, 0, SEEK_SET);  //这时要考虑文件指针的问题，写完后文件指针在文件尾，再读的话要把文件指针移动到开头
    //char recv[100];
    //bzero(recv, sizeof(recv));
    //fread(recv, sizeof(recv), 1, fp);
    
    char fbuf[100];
    fgets(fbuf, 4, fp);
    printf("fbuf: %s\n", fbuf);
    return 0;
}
