#include<stdlib.h>
#include<stdio.h>
int main()
{
        int start,length,*f,i,j;
        char ch;
         for(i=0;i<50;i++)
                f[i] = 0;
        
        do
        {
                printf("Enter the starting block :\n");
                scanf("%d",&start);
                printf("Enter the length : \n");
                scanf("%d",&length);
                for(i= start;i<(start+length);i++)
                {
                        if(f[i] == 0)
                        {
                                f[i] = 1;
                                printf("%d -> %d\n",i,f[i]);
                        }
                        else
                        {
                                printf("File has already allocated\n");
                               
                        }
                }
                
                        printf("\nFile has been allocated (do you want to allocate once more (y/n) \n");
                        scanf(" %c",&ch);
   
        }while(ch == 'Y' || ch == 'y');
        
}

/*
OUTPUT:
aromal@Aromal-Nitro-5:~/labdemo$ ./a.out
Enter the starting block :
4
Enter the length : 
10
4 -> 1
5 -> 1
6 -> 1
7 -> 1
8 -> 1
9 -> 1
10 -> 1
11 -> 1
12 -> 1
13 -> 1

File has been allocated (do you want to allocate once more (y/n) 
*/
