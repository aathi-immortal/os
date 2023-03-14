#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
};

int main() {
    int n, i,j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    struct process p[10], temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i+1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i+1;
    }
    // sort the processes by arrival time
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if (p[j].arrival_time > p[j+1].arrival_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }
        // process is executing
        current_time += p[i].burst_time;
        // calculate waiting time and turnaround time
        avg_waiting_time += current_time - p[i].arrival_time - p[i].burst_time;
        avg_turnaround_time += current_time - p[i].arrival_time;
    }
    // calculate the average waiting time and turnaround time
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    current_time = 0;
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
    }
        // process is executing
        current_time += p[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, current_time - p[i].arrival_time - p[i].burst_time, current_time - p[i].arrival_time);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    return 0;
}

