// Program to simulate non-preemptive priority Scheduling ALgorithm.
// Vishruth S, 61, CS4A

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process
{
    int pId, AT, BT, CT, TAT, WT, isComplete, priority;
};

void sortProcesses(struct Process[], int);

// Non pre-emptive priority schdeuling
void priorityScheduling(struct Process processes[], int n)
{
    int currTime = 0, sumTAT = 0, sumWT = 0, completed = 0;

    while (completed < n) // repeat until all processes are complete
    {
        int selectedP = -1, maxPriority = INT_MIN;
        for (int i = 0; i < n; i++) // find process with maximum priority
        {
            if (!processes[i].isComplete && processes[i].AT <= currTime) // if process is ready at the current time
            {
                if (processes[i].priority > maxPriority) // check if it has higher priority
                {
                    selectedP = i;
                    maxPriority = processes[i].priority;
                }
                if (processes[i].priority == maxPriority && processes[i].AT < processes[selectedP].AT) // if priority same, check for earlier arrival time
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

    printf("Process\t Priority\t Arrival Time\t  Burst Time\t  Completion Time\t  Turnaround Time\t  Waiting Time");
    for (int i = 0; i < n; i++)
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", processes[i].pId, processes[i].priority, processes[i].AT, processes[i].BT, processes[i].CT, processes[i].TAT, processes[i].WT);
    printf("\n\nAverage Turn Around Time: %f", avgTAT);
    printf("\nAverage Waiting Time: %f\n", avgWT);
}

int main()
{
    struct Process processes[20];
    int n;
    printf("\nEnter the number of processes ");
    scanf("%d", &n);
    printf("\nEnter the Arrival Time, Burst Time and priority of each process, space seperated (Larger the value, higher the priority)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &processes[i].AT, &processes[i].BT, &processes[i].priority);
        processes[i].pId = i + 1;
        processes[i].isComplete = 0;
    }

    sortProcesses(processes, n);      // sort processes based on Arrival Time
    priorityScheduling(processes, n); // Simulate priority Scheduling
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