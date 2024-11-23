#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int id;
    int burst_time;
    int starting_time;
    int ending_time;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID for process " << i + 1 << ": ";
        cin >> processes[i].id;
        cout << "Enter Burst Time for process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
    }

    int current_time = 0;
    int total_waiting_time = 0;

    for (int i = 0; i < n; i++) {
        processes[i].starting_time = current_time;
        processes[i].ending_time = processes[i].starting_time + processes[i].burst_time;

        int waiting_time = processes[i].starting_time;
        total_waiting_time += waiting_time;

        current_time = processes[i].ending_time;

        cout << "\nProcess " << processes[i].id << " starts at time " 
             << processes[i].starting_time << " and ends at time " 
             << processes[i].ending_time << ".\n";
        cout << "Waiting Time: " << waiting_time << "\n";
    }

    double average_waiting_time = (double)total_waiting_time / n;

    cout << "\nTotal Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << average_waiting_time << endl;

    return 0;
}
