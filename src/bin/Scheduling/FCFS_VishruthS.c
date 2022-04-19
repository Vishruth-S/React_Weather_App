// Program to simulate First Come First Serve (FCFS) Scheduling ALgorithm.
// Vishruth S, 61, CS4A

#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pId, AT, BT, CT, TAT, WT;
};

void sortProcesses(struct Process[], int);

// First Come First Serve Scheduling
void FCFS(struct Process processes[], int n)
{
    int currTime = 0, sumTAT = 0, sumWT = 0;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].AT <= currTime)
            processes[i].CT = currTime + processes[i].BT;
        else
            processes[i].CT = processes[i].AT + processes[i].BT;

        processes[i].TAT = processes[i].CT - processes[i].AT; // TAT = CT - AT
        processes[i].WT = processes[i].TAT - processes[i].BT; // WT = TAT - BT
        sumTAT += processes[i].TAT;
        sumWT += processes[i].WT;

        currTime = processes[i].CT;
    }

    float avgTAT = (float)sumTAT / (float)n;
    float avgWT = (float)sumWT / (float)n;

    printf("Process\t  Arrival Time\t  Burst Time\t  Completion Time\t  Turnaround Time\t  Waiting Time");
    for (int i = 0; i < n; i++)
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", processes[i].pId, processes[i].AT, processes[i].BT, processes[i].CT, processes[i].TAT, processes[i].WT);
    printf("\n\nAverage Turn Around Time: %f", avgTAT);
    printf("\nAverage Waiting Time: %f\n", avgWT);
}

int main()
{
    struct Process processes[20];
    int n;
    printf("\nEnter the number of processes ");
    scanf("%d", &n);
    printf("\nEnter the Arrival Time and Burst Time of each process, space seperated\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &processes[i].AT, &processes[i].BT);
        processes[i].pId = i + 1;
    }
    sortProcesses(processes, n); // sort processes based on Arrival Time
    FCFS(processes, n);          // Simulate FCFS
    return 0;
}

void sortProcesses(struct Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (processes[j].AT > processes[j + 1].AT)
            {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
}