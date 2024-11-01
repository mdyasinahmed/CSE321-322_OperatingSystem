#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int id;       // Process ID
    int bt;       // Burst Time
    int at;       // Arrival Time
    int st;       // Starting Time
    int et;       // Ending Time
    int wt;       // Waiting Time
};

int main() {
    int n;  // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Take input for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID for process " << i + 1 << ": ";
        cin >> processes[i].id;
        cout << "Enter Arrival Time for process " << i + 1 << ": ";
        cin >> processes[i].at;
        cout << "Enter Burst Time for process " << i + 1 << ": ";
        cin >> processes[i].bt;
    }

    int current_time = 0; // Keeps track of current time in the system
    int total_waiting_time = 0; // Total waiting time

    // FCFS Scheduling
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].at) {
            current_time = processes[i].at; // If the CPU is idle, wait until the process arrives
        }

        // Calculate start time
        processes[i].st = current_time;

        // Calculate end time
        processes[i].et = processes[i].st + processes[i].bt;

        // Calculate waiting time
        processes[i].wt = processes[i].st - processes[i].at;
        total_waiting_time += processes[i].wt;

        // Update current time after this process ends
        current_time = processes[i].et;

        // Output process details
        cout << "\nProcess " << processes[i].id << " starts at time " 
             << processes[i].st << " and ends at time " 
             << processes[i].et << ".\n";
        cout << "Waiting Time: " << processes[i].wt << "\n";
    }

    // Calculate average waiting time
    double average_waiting_time = (double)total_waiting_time / n;

    cout << "\nTotal Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << average_waiting_time << endl;

    return 0;
}
