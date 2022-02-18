// Shortest Remaining Time First
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

class process {
public:
  string name;
  int arrival;
  int burst;
  int completion = 0;
  int turnaround = 0;
  int waiting = 0;

  process(const string &name) {
    int burst_time;
    this->name = name;
    cout << "Enter arrival time : ";
    cin >> this->arrival;
    cout << "Enter burst time : ";
    cin >> this->burst;
  }

  process(const string &name, int arrival, int burst_time) {
    this->name = name;
    this->arrival = arrival;
    this->burst = burst_time;
  }

  void print() {
    cout << name << "\n => Arrival Time : " << arrival
         << "\n => Burst Time : " << burst;
  }

  void printCompletion() { cout << "\n => Completion Time : " << completion; }

  void printTurnaround() { cout << "\n => Turnaround Time : " << turnaround; }

  void printWaiting() { cout << "\n => Waiting Time : " << waiting; }

  /* Comparator used for sort according to arrival */
  bool static arrivalSortComparator(process p1, process p2) {
    return (p1.arrival != p2.arrival) ? p1.arrival < p2.arrival
                                      : p1.burst < p2.burst;
  }

  /* Sort according to Arrival */
  void static sortArrival(vector<process> &ps) {
    sort(ps.begin(), ps.end(), process::arrivalSortComparator);
  }
};

int generateRandomInt(int min, int max) {
  return min + (rand() % static_cast<int>(max - min + 1));
}

/* Auto generate Processes */
vector<process> sampleProcesses(int len) {
  srand(time(0));
  vector<process> v;

  for (int i = 0; i < len; i++)
    v.push_back(process("P" + to_string(i), generateRandomInt(0, 5),
                        generateRandomInt(5, 15)));

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
  for (auto ele : v) {
    ele.print();
    cout << "\n";
  }
  cout << endl;
}

/* Print all details of processes */
void printProcessesWithDetails(vector<process> v) {
  for (auto ele : v) {
    ele.print();
    ele.printCompletion();
    ele.printWaiting();
    ele.printTurnaround();
    cout << "\n";
  }
  cout << endl;
}

double averageWaitingTime(vector<process> ps) {
  double sum = 0;
  for (process p : ps)
    sum += p.waiting;
  return sum / ps.size();
}

double averageTurnaroundTime(vector<process> ps) {
  double sum = 0;
  for (process p : ps)
    sum += p.turnaround;
  return sum / ps.size();
}

void sjf(vector<process> ps) {
  int pindex;
  int current = 0;
  /* vector<process> compelete; */

  /* Sort processes by arrival */
  process::sortArrival(ps);

  /* Calcaulte Completion, Turnaround and Waiting Time for first process */
  ps[0].completion = ps[0].arrival + ps[0].burst;
  ps[0].turnaround = ps[0].completion - ps[0].arrival;
  ps[0].waiting = 0;

  /* Calcaulte Completion, Turnaround and Waiting Time for remaining processes
   */
  for (int i = 1; i < ps.size(); i++) {
    ps[i].completion = ps[i].burst + ps[i - 1].completion;
    ps[i].turnaround = ps[i].completion - ps[i].arrival;
    ps[i].waiting = ps[i].turnaround - ps[i].burst;
  }

  cout << "=== Result ===" << endl;
  printProcessesWithDetails(ps);

  cout << "=== Stats ===" << endl;
  cout << "Average Waiting Time = " << averageWaitingTime(ps) << endl;
  cout << "Average Turnaround Time = " << averageTurnaroundTime(ps) << endl;
}

int main() {
  // vector<process> processes = sampleProcesses(5);
  vector<process> processes =
      sampleProcesses(new int[]{2, 0, 1, 3, 4}, new int[]{4, 2, 6, 9, 12}, 5);
  /* vector<process> processes = getProcesses(); */

  /* Print Processes */
  // printProcesses(processes);

  sjf(processes);

  return 0;
}
