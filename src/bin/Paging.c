#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mem_size, page_size;
    printf("Enter memory_size\n");
    scanf("%d", &mem_size);
    printf("Enter page size\n");
    scanf("%d", &page_size);
    // check if page < mem
    int no_of_frames = mem_size / page_size;
    printf("\nNumber of possible frames: %d", no_of_frames);
    int no_of_pages;
    printf("\nEnter no. of pages\n");
    scanf("%d", &no_of_pages);
    // check if page < mem
    // calculating page table;
    int pageTable[no_of_pages], frames[no_of_frames];
    srand(time(0));
    for (int i = 0; i < no_of_frames; i++)
        frames[i] = -1;
    for (int i = 0; i < no_of_pages; i++)
    {
        int frame_no = rand() % no_of_frames;
        while (frames[frame_no] != -1)
            frame_no = rand() % no_of_frames;
        pageTable[i] = frame_no;
        frames[frame_no] = i;
    }
    printf("\n\nPage Table\n");
    printf("Page number\tFrame number\n");
    for (int i = 0; i < no_of_pages; i++)
    {
        printf("%d\t\t%d\n", i, pageTable[i]);
    }
    int log_address, page_no, offset;
    printf("\nEnter logical Address\n");
    scanf("%d", &log_address);
    // check errors
    page_no = log_address / page_size;
    offset = log_address % page_size;
    printf("\nPage no:%d\tOffset: %d", page_no, offset);
    int phy_address;
    phy_address = pageTable[page_no] * page_size + offset;
    printf("\nPhysical Address: %d", phy_address);
    return 0;
}