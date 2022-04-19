#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    fp = fopen("program.txt", "r");
    char rec[10], progname[10], len[10];
    char temp[10];
    int start_addr;
    fscanf(fp, "%s %s %s %s", rec, progname, temp, len);
    printf("\nProgram name: %s\n", progname);
    printf("\nMemory address\tValue\n");
    int locctr = start_addr;
    while (!feof(fp))
    {
        fscanf(fp, "%s", rec);
        if (strcmp(rec, "E") == 0)
            break;
        if (strcmp(rec, "T") == 0)
        {
            fscanf(fp, "%X", &start_addr);
            locctr = start_addr;
            fscanf(fp, "%s", len);
        }
        else
        {
            if (locctr > 0xFFFF)
                printf("0");
            else if (locctr > 0xFFF)
                printf("00");
            else if (locctr > 0xFF)
                printf("000");
            else if (locctr > 0xF)
                printf("0000");
            else
                printf("00000");
            printf("%X\t\t%s\n", locctr, rec);
            locctr += 3;
        }
    }
    return 0;
}