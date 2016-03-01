#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

typedef struct
{
    char integer;
    char string[9];
}RECORD;

#define NRECORDS 10

int main()
{
    RECORD record, *mapped;
    int i, f;
    FILE *fp;

    fp = fopen("records.dat", "w+");

    for (i=0; i<NRECORDS; i++) 
    {
        record.integer = '1';
        bzero(record.string, sizeof(record.string));
        sprintf(record.string, "RECORD-%d\n", i);
        fwrite(&record, sizeof(record), 1, fp);
    }
    fclose(fp);

    
    fp = fopen("records.dat", "r+");
    if (!fp)
        printf("error\n");
    
    fseek(fp, 43*sizeof(record), SEEK_SET);
    fread(&record, sizeof(record), 1, fp);
    printf("%d, %s\n", record.integer, record.string);
    
    
    record.integer = 143;
    sprintf(record.string, "RECORD-%d", record.integer);
    
    fseek(fp, 43*sizeof(record), SEEK_SET);
    fwrite(&record, sizeof(record), 1, fp);
    
    fclose(fp);
    
    f = open("records.dat", O_RDWR);
    
    mapped = (RECORD *)mmap(0, NRECORDS*sizeof(record), PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);
    printf("%d, %s\n", mapped[43].integer, mapped[43].string);

    mapped[43].integer =243;
    sprintf(mapped[43].string, "RECORD-%d", mapped[43].integer);
     
    printf("%d, %s\n", mapped[43].integer, mapped[43].string);
    msync((void *)mapped, NRECORDS*sizeof(record), MS_ASYNC);
    munmap((void *)mapped, NRECORDS*sizeof(record));
    close(f);
    
    fp = fopen("record.dat", "r+");    
    if (!fp)
        printf("error\n");
    return 0;
}
