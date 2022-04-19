#include<stdio.h>
#include<stdlib.h>

void scan(int Ar[20], int n, int start);
void sort(int Ar[20], int n);


int range, lastLocation;
int main() {
    int diskQueue[20], n, start, i;
    printf("Enter the range :");
    scanf("%d", &range);
    
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for(i=1;i<=n;i++) {                                     /* head element to be read */ 
        scanf("%d",&diskQueue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &start);                                
    diskQueue[0] = start;                                    /* injecting to the first position */
    ++n;
    sort(diskQueue, n);                                     /* total of n+1 elements */    
    scan(diskQueue, n, start);

    return 0;
}

void scan(int Ar[20], int n, int start) {
    int i, pos, diff, seekTime=0, current;
    // position of the disk to start seeking 
    for(i=0;i<n;i++) {                                      
        if(Ar[i]==start) {
            pos=i;
            break;
        }
    }
    // start seeking to the right
    printf("\nMovement of Cylinders\n");
    for(i=pos;i<n-1;i++) {
        diff = abs(Ar[i+1] - Ar[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", Ar[i], Ar[i+1], diff);
    }
    current=i;               /* last element position */                  
    //moving to end location
    lastLocation = range -1;
    printf("Move from %d to %d with seek time %d\n", Ar[i], lastLocation,(lastLocation-Ar[i]));
    seekTime+=lastLocation-Ar[i];
    Ar[i]= lastLocation;
    // start seeking to the left
    for(i=pos-1;i>=0;i--) {
        diff = abs(Ar[current] - Ar[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", Ar[current], Ar[i], diff);
        current=i;
    }
    printf("\nTotal Seek Time: %d", seekTime);
    // average of entered elements(n-1) excluding head
    printf("\n");
}

void sort(int Ar[20], int n) {
    int i, j, tmp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1-i;j++) {
            if(Ar[j]>Ar[j+1]) {
                tmp = Ar[j];
                Ar[j] = Ar[j+1];
                Ar[j+1] = tmp;
            }
        }
    }
}

/* OUTPUT

Enter the range :200
Enter the size of Queue: 8
Enter the Queue: 
98 183 41 122 14 124 65 67
Enter the initial head position: 53

Movement of Cylinders
Move from 53 to 65 with seek time 12
Move from 65 to 67 with seek time 2
Move from 67 to 98 with seek time 31
Move from 98 to 122 with seek time 24
Move from 122 to 124 with seek time 2
Move from 124 to 183 with seek time 59
Move from 183 to 199 with seek time 16
Move from 199 to 41 with seek time 158
Move from 41 to 14 with seek time 27

Total Seek Time: 331
    
*/
