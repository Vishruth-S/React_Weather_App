#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process
{
    int pid, at, bt, ct, wt, tat;
};

void sort(struct Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (processes[j].at > processes[j + 1].at)
            {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void fcfs(struct Process processes[], int n)
{
    int curr_time = 0, sum_tat = 0, sum_wt = 0;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].at > curr_time)
            curr_time = processes[i].at;

        curr_time += processes[i].bt;
        processes[i].ct = curr_time;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        sum_tat += processes[i].tat;
        sum_wt += processes[i].wt;
    }
    float avgTat = sum_tat / n, avgWt = sum_wt / n;
    printf("Process\t  Arrival Time\t  Burst Time\t  Completion Time\t  Turnaround Time\t  Waiting Time");
    for (int i = 0; i < n; i++)
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", processes[i].pid, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    printf("\n\nAverage Turn Around Time: %f", avgTat);
    printf("\nAverage Waiting Time: %f\n", avgWt);
}

void sjf(struct Process processes[], int n)
{
    int currTime = 0, sumTAT = 0, sumWT = 0, completed = 0;
    int flags[n];
    for (int i = 0; i < n; i++)
        flags[i] = 0;

    while (completed < n) // repeat until all processes are complete
    {
        int selectedP = -1, minBT = INT_MAX;
        for (int i = 0; i < n; i++) //
        {
            if (!flags[i] && processes[i].at <= currTime) // if process is ready at the current time
            {
                if (processes[i].bt < minBT) // find process with minimum burst time
                {
                    selectedP = i;
                    minBT = processes[i].bt;
                }
                if (processes[i].bt == minBT && processes[i].at < processes[selectedP].at) // if burst time is same, then select one with lower arrival time
                    selectedP = i;
            }
        }
        if (selectedP == -1)
        {
            currTime++;
            continue;
        }
        flags[selectedP] = 1; // mark selected process it as complete

        processes[selectedP].ct = currTime + processes[selectedP].bt;                 // CT = currTime + BT
        processes[selectedP].tat = processes[selectedP].ct - processes[selectedP].at; // TAT = CT - AT
        processes[selectedP].wt = processes[selectedP].tat - processes[selectedP].bt; // WT = TAT - BT
        sumTAT += processes[selectedP].tat;
        sumWT += processes[selectedP].wt;

        currTime = processes[selectedP].ct; // update the current time
        completed++;
    }
    float avgTAT = (float)sumTAT / (float)n;
    float avgWT = (float)sumWT / (float)n;

    printf("Process\t  Arrival Time\t  Burst Time\t  Completion Time\t  Turnaround Time\t  Waiting Time");
    for (int i = 0; i < n; i++)
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", processes[i].pid, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    printf("\n\nAverage Turn Around Time: %f", avgTAT);
    printf("\nAverage Waiting Time: %f\n", avgWT);
}

void prio(struct Process processes[], int n, int priority[])
{
    int currTime = 0, sumTAT = 0, sumWT = 0, completed = 0;
    int flags[n];
    for (int i = 0; i < n; i++)
        flags[i] = 0;

    while (completed < n) // repeat until all processes are complete
    {
        int selectedP = -1, maxPrio = INT_MIN;
        for (int i = 0; i < n; i++) //
        {
            if (!flags[i] && processes[i].at <= currTime) // if process is ready at the current time
            {
                if (priority[i] > maxPrio) // find process with minimum burst time
                {
                    selectedP = i;
                    maxPrio = priority[i];
                }
                if (priority[i] == maxPrio && processes[i].at < processes[selectedP].at) // if burst time is same, then select one with lower arrival time
                    selectedP = i;
            }
        }
        if (selectedP == -1)
        {
            currTime++;
            continue;
        }
        flags[selectedP] = 1; // mark selected process it as complete

        processes[selectedP].ct = currTime + processes[selectedP].bt;                 // CT = currTime + BT
        processes[selectedP].tat = processes[selectedP].ct - processes[selectedP].at; // TAT = CT - AT
        processes[selectedP].wt = processes[selectedP].tat - processes[selectedP].bt; // WT = TAT - BT
        sumTAT += processes[selectedP].tat;
        sumWT += processes[selectedP].wt;

        currTime = processes[selectedP].ct; // update the current time
        completed++;
    }
    float avgTAT = (float)sumTAT / (float)n;
    float avgWT = (float)sumWT / (float)n;

    printf("Process\t  Arrival Time\t  Burst Time\t  Completion Time\t  Turnaround Time\t  Waiting Time");
    for (int i = 0; i < n; i++)
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", processes[i].pid, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    printf("\n\nAverage Turn Around Time: %f", avgTAT);
    printf("\nAverage Waiting Time: %f\n", avgWT);
}

void roundrobin(struct Process processes[], int n, int tq)
{
    int flags[n], remTime[n];
    for (int i = 0; i < n; i++)
    {
        flags[i] = 0;
        remTime[i] = processes[i].bt;
    }

    int curr_time = 0, i = 0, completed = 0;
    int sum_tat = 0, sum_wt = 0;
    while (completed < n)
    {
        if (!flags[i] && processes[i].at <= curr_time)
        {
            curr_time += (tq < remTime[i] ? tq : remTime[i]);
            remTime[i] -= tq;
        }
        if (!flags[i] && remTime[i] <= 0)
        {
            flags[i] = 1;
            completed++;
            processes[i].ct = curr_time;
            processes[i].tat = processes[i].ct - processes[i].at;
            processes[i].wt = processes[i].tat - processes[i].bt;
            sum_tat += processes[i].tat;
            sum_wt += processes[i].wt;
        }
        i = (i + 1) % n;
    }
    float avgTat = (float)sum_tat / (float)n;
    float avgWt = (float)sum_wt / (float)n;
    printf("Process\t  Arrival Time\t  Burst Time\t  Completion Time\t  Turnaround Time\t  Waiting Time");
    for (int i = 0; i < n; i++)
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", processes[i].pid, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    printf("\n\nAverage Turn Around Time: %f", avgTat);
    printf("\nAverage Waiting Time: %f\n", avgWt);
}

int main()
{
    int n;
    printf("\nEnter number of processes\n");
    scanf("%d", &n);
    struct Process processes[n];
    // printf("\nEnter the Arrival time and Burst time of each process, space seperated\n");
    // for (int i = 0; i < n; i++)
    // {
    //     processes[i].pid = i + 1;
    //     scanf("%d", &processes[i].at);
    //     scanf("%d", &processes[i].bt);
    // }
    // int tq;
    // printf("\nEnter time quantum\n");
    // scanf("%d", &tq);

    int priority[n];
    printf("\nEnter the Arrival time, Burst time, Priority of each process, space seperated\n");
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        scanf("%d", &processes[i].at);
        scanf("%d", &processes[i].bt);
        scanf("%d", &priority[i]);
    }
    sort(processes, n);
    // fcfs(processes, n);
    // sjf(processes, n);
    // roundrobin(processes, n, tq);
    prio(processes, n, priority);

    return 0;
}