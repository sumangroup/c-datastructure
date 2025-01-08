#include <stdio.h>

typedef struct {
    char name[10];
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void find_fcfs_scheduling(Process processes[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        // Update current time if it's less than the arrival time of the next process
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        // Calculate times
        processes[i].start_time = current_time;
        processes[i].completion_time = processes[i].start_time + processes[i].burst_time;
        processes[i].waiting_time = processes[i].start_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        // Update current time to the completion time of the current process
        current_time = processes[i].completion_time;
    }
}

void print_process_info(Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time,
               processes[i].start_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[] = {
        {"P1", 0, 4},
        {"P2", 1, 3},
        {"P3", 2, 1},
        {"P4", 3, 2}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    find_fcfs_scheduling(processes, n);
    print_process_info(processes, n);

    return 0;
}
