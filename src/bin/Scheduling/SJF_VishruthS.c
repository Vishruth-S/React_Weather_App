// Program to simulate Shortest Job First (SJF) Scheduling ALgorithm.
// Vishruth S, 61, CS4A

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process
{
    int pId, AT, BT, CT, TAT, WT, isComplete;
};

void sortProcesses(struct Process[], int);

// Shortest Job First Scheduling
void SJF(struct Process processes[], int n)
{
    int currTime = 0, sumTAT = 0, sumWT = 0, completed = 0;

    while (completed < n) // repeat until all processes are complete
    {
        int selectedP = -1, minBT = INT_MAX;
        for (int i = 0; i < n; i++) //
        {
            if (!processes[i].isComplete && processes[i].AT <= currTime) // if process is ready at the current time
            {
                if (processes[i].BT < minBT) // find process with minimum burst time
                {
                    selectedP = i;
                    minBT = processes[i].BT;
                }
                if (processes[i].BT == minBT && processes[i].AT < processes[selectedP].AT) // if burst time is same, then select one with lower arrival time
                    selectedP = i;
            }
        }
        if (selectedP == -1)
        {
            currTime++;
            continue;
        }
        processes[selectedP].isComplete = 1; // mark selected process it as complete

        processes[selectedP].CT = currTime + processes[selectedP].BT;                 // CT = currTime + BT
        processes[selectedP].TAT = processes[selectedP].CT - processes[selectedP].AT; // TAT = CT - AT
        processes[selectedP].WT = processes[selectedP].TAT - processes[selectedP].BT; // WT = TAT - BT
        sumTAT += processes[selectedP].TAT;
        sumWT += processes[selectedP].WT;

        currTime = processes[selectedP].CT; // update the current time
        completed++;
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
        processes[i].isComplete = 0;
    }

    sortProcesses(processes, n); // sort processes based on Arrival Time
    SJF(processes, n);           // Simulate SJF
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