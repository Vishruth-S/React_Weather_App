#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char bitmask[], char mask[])
{
    strcpy(bitmask, "");
    for (int i = 0; i < strlen(mask); i++)
    {
        switch (mask[i])
        {
        case '0':
            strcat(bitmask, "0000");
            break;
        case '1':
            strcat(bitmask, "0001");
            break;
        case '2':
            strcat(bitmask, "0010");
            break;
        case '3':
            strcat(bitmask, "0011");
            break;
        case '4':
            strcat(bitmask, "0100");
            break;
        case '5':
            strcat(bitmask, "0101");
            break;
        case '6':
            strcat(bitmask, "0110");
            break;
        case '7':
            strcat(bitmask, "0111");
            break;
        case '8':
            strcat(bitmask, "1000");
            break;
        case '9':
            strcat(bitmask, "1001");
            break;
        case 'A':
            strcat(bitmask, "1010");
            break;
        case 'B':
            strcat(bitmask, "1011");
            break;
        case 'C':
            strcat(bitmask, "1100");
            break;
        case 'D':
            strcat(bitmask, "1101");
            break;
        case 'E':
            strcat(bitmask, "1110");
            break;
        case 'F':
            strcat(bitmask, "1111");
            break;
        }
    }
}

int main()
{
    FILE *fp;
    fp = fopen("program2.txt", "r");
    char rec[10], progname[10], len[10];
    char temp[10];
    int start_addr, actual_start = 0;
    printf("\nEnter the actual starting address\n");
    scanf("%x", &actual_start);
    printf("\nActual start: %x\n", actual_start);
    fscanf(fp, "%s %s %s %s", rec, progname, temp, len);
    printf("\nProgram name: %s\n", progname);
    printf("\nMemory address\tValue\n");

    int locctr = start_addr;
    char bitmask[30], mask[30];
    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s", rec);
        if (strcmp(rec, "E") == 0)
            break;
        if (strcmp(rec, "T") == 0)
        {
            fscanf(fp, "%x", &start_addr);
            fscanf(fp, "%s", len);
            fscanf(fp, "%s", mask);

            convert(bitmask, mask);
            locctr = start_addr;
            i = 0;
        }
        else
        {
            int address = locctr;
            if (bitmask[i] == '1')
            {
                address = locctr + actual_start;
            }
            if (address > 0xFFFF)
                printf("0");
            else if (address > 0xFFF)
                printf("00");
            else if (address > 0xFF)
                printf("000");
            else if (address > 0xF)
                printf("0000");
            else
                printf("00000");

            printf("%X\t\t%s\n", address, rec);
            locctr += 3;
            i++;
        }
    }
    return 0;
}