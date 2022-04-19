// use 'gcc 3_Paging.c -lm' to compile

#include<stdio.h>
#include<math.h>
int frametable[50],pt = 0,frame_no;

void paging(int page_no)
{
	int i;
	if(pt + page_no > frame_no)
	{
		printf("Cannot store the program as the frame table is full \n");
		return;
	}
	printf("Storing the program in frames of frame table\n");
	for(i = pt;i<pt + page_no;i++)
	{
		frametable[i] = 1;
		printf("%d -> %p \n",i,&frametable[i]);
	}
	pt = i;
	printf("\n");
}
void main()
{
	int fs,pts,fts,page_no,status;
	for(int j = 0;j<50;j++)
	{
		frametable[j] = 0;
	}
	printf("Enter the size of frame table in bytes\n");
	scanf("%d",&fts);
	printf("Enter the size of a frame in bytes \n");
	scanf("%d",&fs);
	frame_no = ceil(fts/fs);
	printf("Total possible frames = %d \n",frame_no);
	while(1)
	{
		printf("Enter 1 to store a program in the memory\nEnter 2 to exit\n");
		scanf("%d",&status);
		if(status == 1)
		{
			printf("Enter size of program in bytes\n");
			scanf("%d",&pts);
			page_no = ceil(pts/fs);
			paging(page_no);
		}
		else
			break;
	}
}




/*
OUTPUT

s5d_19_15@ceclab2-System-Product-Name:~/Aromal_S/git/System-Software-Lab-S5/Lab-1$ cc 3_Paging.c -lm
s5d_19_15@ceclab2-System-Product-Name:~/Aromal_S/git/System-Software-Lab-S5/Lab-1$ ./a.out
Enter the size of frame table in bytes
36
Enter the size of a frame in bytes 
4
Total possible frames = 9 
Enter 1 to store a program in the memory
Enter 2 to exit
1
Enter size of program in bytes
8
Storing the program in frames of frame table
0 -> 0x6010a0 
1 -> 0x6010a4 

Enter 1 to store a program in the memory
Enter 2 to exit
1
Enter size of program in bytes
8
Storing the program in frames of frame table
2 -> 0x6010a8 
3 -> 0x6010ac 

Enter 1 to store a program in the memory
Enter 2 to exit
2

*/