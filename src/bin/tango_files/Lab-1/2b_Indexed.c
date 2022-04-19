#include<stdio.h>
#include<stdlib.h>

int f[50],i,k,j,inde[50],n,c,count=0,p;
int main()
{
    for(i=0;i<50;i++)
        f[i]=0;
    x:

    printf("enter index block\t");
    scanf("%d",&p);

    if(f[p]==0)
    {
        f[p]=1;
        printf("enter no of files on index\t");
        scanf("%d",&n);
    }
    else
    {
        printf("Block already allocated\n");
        goto x;
    }

    y:
    printf("\nEnter the file blocks to be indexed :");
    for(i=0;i<n;i++)
        scanf("%d",&inde[i]);
    for(i=0;i<n;i++)
    {
        if(f[inde[i]]==1)
        {
            printf("Block already allocated");
            goto y;
        }
    }
    for(j=0;j<n;j++)
        f[inde[j]]=1;

    printf("\n allocated");
    printf("\n file indexed");

    for(k=0;k<n;k++)
        printf("\n %d-  >%d:%d",p,inde[k],f[inde[k]]);
        
    printf("\nEnter 1 to enter more files and 0 to exit\t");
    scanf("%d",&c);
    if(c==1)
        goto x;
    else
        exit(0);
    
}


/*
OUTPUT:
Enter index block 9
Enter no of files on index 3
1 2 3
Allocated
File indexed
9-> 1:1
9-> 2:1
9->3:1
Enter 1 to enter more files and 0 to exit
*/

