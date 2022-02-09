// Shortest Remaining Time First
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include "generateRandom.cpp"

using namespace std;

class process {
public:
    string name;
    int arrival;
    int og_burst;
    int burst;
    int completion = 0;
    int turnaround = 0;
    int waiting = 0;

    process(const string& name) {
        this->name = name;
        cout << "Enter arrival time : ";
        cin >> this->arrival;
        cout << "Enter burst time : ";
        cin >> this->burst;
    }

    process(const string& name, int arrival, int burst) {
        this->name = name;
        this->arrival = arrival;
        this->burst = burst;
        this->og_burst = burst;
    }

    void print() {
        cout << name << "\n => Arrival Time : " << arrival << "\n => Burst Time : " << og_burst;
    }

    void printCompletion() {
        cout << "\n => Completion Time : " << completion;
    }

    void printTurnaround() {
        cout << "\n => Turnaround Time : " << turnaround;
    }

    void printWaiting() {
        cout << "\n => Waiting Time : " << waiting;
    }

    /* Comparator used for sort according to arrival algorithm */
    bool static arrivalSortComparator(process p1, process p2) {
        return (p1.arrival != p2.arrival) ? p1.arrival < p2.arrival : p1.burst < p2.burst;
    }

    /* Comparator used for sort according to burst algorithm */
    bool static burstSortComparator(process p1, process p2) {
        return (p1.burst != p2.burst) ? p1.burst < p2.burst : p1.arrival < p2.arrival;
    }

    /* Sort according to Arrival */
    void static sortArrival(vector<process>& ps) {
        sort(ps.begin(), ps.end(), process::arrivalSortComparator);
    }

    /* Sort according to Arrival */
    void static sortArrival(vector<process>& ps, int start, int end) {
        sort(ps.begin() + start, ps.end() - end, process::arrivalSortComparator);
    }

    /* Sort according to Burst */
    void static sortBurst(vector<process>& ps) {
        sort(ps.begin(), ps.end(), process::burstSortComparator);
    }

    /* Sort according to Burst */
    void static sortBurst(vector<process>& ps, int start, int end) {
        /* cout << endl << start << " " << end; */
        sort(ps.begin() + start, ps.end() - end, process::burstSortComparator);
    }
};

/* Auto generate Processes */
vector<process> sampleProcesses(int len) {
    srand(time(0));
    vector<process> v;

    for (int i = 0; i < len; i++)
       v.push_back(process("P" + to_string(i), generateRandomInt(0, 5), generateRandomInt(5, 15)));

    return v;
}

/* Pass arrival and Burst */
vector<process> sampleProcesses(int arrival[], int burst[], int len) {
    vector<process> v;

    for (int i = 0; i < len; i++)
       v.push_back(process("P" + to_string(i), arrival[i], burst[i]));

    return v;
}

/* Get Processes from User */
vector<process> getProcesses() {
    int n;
    string p_name;
    vector<process> processes;

    cout << "Enter no. of processes : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        p_name = "P" + to_string(i);
        cout << "==== " << p_name << " ====\n";
        processes.push_back(process(p_name));
    }
    return processes;
}

/* Print Processes */
void printProcesses(vector<process> v) {
    for (auto ele: v) {
        ele.print();
        cout << "\n";
    }
    cout << endl;
}

/* Print all details of processes */
void printProcessesWithDetails(vector<process> v) {
    for (auto ele: v) {
        ele.print();
        ele.printCompletion();
        ele.printWaiting();
        ele.printTurnaround();
        cout << "\n";
    }
    cout << endl;
}

void srtf(vector<process> ps) {
    int pindex;
    int current = 0;
    /* vector<process> compelete; */

    /* Sort processes by arrival */
    process::sortArrival(ps);


    for (int clock = 0; ps.size() > 0 && clock < 100; clock++) {
        /* cout << clock << "\n"; */
        pindex = 0;

        while (clock <= ps[pindex].arrival && pindex < ps.size()) {
            /* cout << pindex; */
            pindex++;
        }

        /* Sort ready processes according to burst */
        process::sortBurst(ps, current, pindex);

        if (ps[current].burst == 0) {
            ps[current].completion = clock; // Completion Time
            ps[current].turnaround = ps[current].completion - ps[current].arrival; // Turnaround Time
            ps[current].waiting = ps[current].turnaround - ps[current].og_burst; // Waiting Time
            current++;
        } else {
            ps[current].burst--;
        }

        if (ps[current].burst == 0 && pindex >= ps.size()) break;

    }

    cout << "=== Result ===" << endl;
    printProcessesWithDetails(ps);
}

int main() {

    vector<process> processes = sampleProcesses(5);
    /* vector<process> processes = sampleProcesses(new int[]{0,1,2,3}, new int[]{8,4,9,5}, 4); */
    /* vector<process> processes = getProcesses(); */

    /* Print Processes */
    printProcesses(processes);

    srtf(processes);

    return 0;
}
