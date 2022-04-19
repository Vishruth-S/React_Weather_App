// Program to simulate Round Robin Scheduling ALgorithm.
// Vishruth S, 61, CS4A

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process
{
    int pId, AT, BT, CT, TAT, WT, isComplete, RT;
};

void sortProcesses(struct Process[], int);

// Round Robin Scheduling
void RoundRobin(struct Process processes[], int n, int timeQuantum)
{
    int currTime = 0, sumTAT = 0, sumWT = 0, completed = 0, i = 0;

    while (completed < n) // repeat until all processes are complete
    {
        if (processes[i].RT <= timeQuantum && processes[i].RT > 0) //If the remaining time for the process is less than or equal to 1 time quantum
        {
            currTime += processes[i].RT;
            processes[i].RT = 0;
        }
        else if (processes[i].RT > 0) //If the remaining time is greater than 1 quantum
        {
            currTime += timeQuantum;
            processes[i].RT -= timeQuantum;
        }
        if (!processes[i].isComplete && (processes[i].RT == 0))
        {
            processes[i].CT = currTime;                           //Calculating the completion time
            processes[i].TAT = processes[i].CT - processes[i].AT; //Calculating the turnaround time : turnaround time = completion time – arrival time
            processes[i].WT = processes[i].TAT - processes[i].BT; //Calculating the waiting time : waiting time = turnaround time – burst time
            sumTAT += processes[i].TAT;                           //Calculating total turnaround Time
            sumWT += processes[i].WT;                             //Calculating total waiting Time
            processes[i].isComplete = 1;
            completed++;
        }
        if (i == n - 1)
            i = 0;
        else if (processes[i + 1].AT <= currTime)
            i++;
        else
            i = 0;
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
    int n, timeQ;
    printf("\nEnter the number of processes ");
    scanf("%d", &n);
    printf("\nEnter the Arrival Time and Burst Time of each process, space seperated\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &processes[i].AT, &processes[i].BT);
        processes[i].pId = i + 1;
        processes[i].isComplete = 0;
        processes[i].RT = processes[i].BT;
    }
    printf("\nEnter the Time Quantum\n");
    scanf("%d", &timeQ);
    sortProcesses(processes, n);     // sort processes based on Arrival Time
    RoundRobin(processes, n, timeQ); // Simulate Round Robin
    return 0;
}

void sortProcesses(struct Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (processes[j].AT > processes[j + 1].AT)
            {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
}