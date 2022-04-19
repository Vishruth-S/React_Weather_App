#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct File
{
    char name[100];
    int start, len;
};

struct Memory
{
    int data, next;
};

void linked(struct Memory memory[], int mem_size, struct File files[], int n)
{
    srand(time(0));
    int remaining_memory = mem_size;
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        prev = -1;
        if (files[i].len <= remaining_memory)
        {
            for (int j = 0; j < files[i].len; j++)
            {
                int rand_location = rand() % mem_size;
                while (memory[rand_location].data != 0)
                {
                    rand_location = rand() % mem_size;
                }
                memory[rand_location].data = i + 1;
                if (prev == -1)
                    files[i].start = rand_location;
                else
                    memory[prev].next = rand_location;
                prev = rand_location;
            }
            remaining_memory -= files[i].len;
        }
    }
}

void display_memory(struct Memory memory[], int mem_size)
{
    for (int i = 0; i < mem_size; i++)
    {
        printf("%d\t", memory[i].data);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
}

int main()
{
    int mem_size, n;
    printf("\nEnter size of memory\n");
    scanf("%d", &mem_size);
    struct Memory memory[mem_size];
    for (int i = 0; i < mem_size; i++)
    {
        memory[i].data = 0;
        memory[i].next = -1;
    }
    printf("\nEnter the number of files to be allocated\n");
    scanf("%d", &n);
    struct File files[n];
    printf("\nEnter the name and length of each file\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &files[i].name);
        scanf("%d", &files[i].len);
    }
    linked(memory, mem_size, files, n);
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