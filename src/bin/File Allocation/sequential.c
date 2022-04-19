#include <stdio.h>
#include <stdlib.h>

struct File
{
    char name[100];
    int start, len;
};

void sequential(int memory[], int mem_size, struct File files[], int n)
{
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (start + files[i].len <= mem_size)
        {
            files[i].start = start;
            int j;
            for (j = start; j < start + files[i].len; j++)
                memory[j] = i + 1;
            start = j;
        }
        else
        {
            files[i].start = -1;
        }
    }
}

void display_memory(int memory[], int mem_size)
{
    for (int i = 0; i < mem_size; i++)
    {
        printf("%d\t", memory[i]);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
}

int main()
{
    int mem_size, n;
    printf("\nEnter size of memory\n");
    scanf("%d", &mem_size);
    int memory[mem_size];
    for (int i = 0; i < mem_size; i++)
        memory[i] = 0;
    printf("\nEnter the number of files to be allocated\n");
    scanf("%d", &n);
    struct File files[n];
    printf("\nEnter the name and length of each file\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &files[i].name);
        scanf("%d", &files[i].len);
    }
    sequential(memory, mem_size, files, n);
    printf("\nAllocation status\n");
    printf("\nFilename\tAllocated\tStarting\tLength\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t", files[i].name);
        if (files[i].start != -1)
            printf("Yes\t\t");
        else
            printf("No\t\t");
        printf("%d\t\t%d\n", files[i].start, files[i].len);
    }
    printf("\n\nMemory\n");
    display_memory(memory, mem_size);
    return 0;
}