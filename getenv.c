/*查看参数arg1环境变量对应的值，如果给定两个参数，则把第二个参数设置为第一个参数的值*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *var, *value;
    if (argc == 1 || argc > 3)
    {
        fprintf(stderr, "usage: environ var [value]\n");
        exit(1);
    }
    var = argv[1];
    value = getenv(var);
    if (value)
    {
        printf("Variable %s has value %s\n", var, value);
    }
    else
        printf("Variable %s has no value\n", var);

    if (argc == 3)
    {
        char *string;
        value = argv[2];
        string = malloc(strlen(var) + strlen(value) + 2);
        if (!string)
        {
            printf("malloc: out of memory!\n");
            exit(1);
        }
        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        printf("string: %s\n", string);

        if (putenv(string) != 0)
        {
            fprintf(stderr, "putenv failed!\n");
            exit(1);
        }

        value = getenv(var);
        if (value)
            printf("now value of %s is %s\n", var, value);
        else
            printf("new value of %s is null??\n", var);
        
    }
    return 0;
}
