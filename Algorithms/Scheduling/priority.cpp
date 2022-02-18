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
  int remaining;
  int priority = 0;
  int completion = 0;
  int turnaround = 0;
  int waiting = 0;

  process(const string &name) {
    int burst_time;
    this->name = name;

    cout << "Enter arrival time : ";
    cin >> this->arrival;

    cout << "Enter burst time : ";
    cin >> burst_time;
    this->remaining = burst_time;
    this->burst = burst_time;

    cout << "Enter priority : ";
    cin >> this->priority;
  }

  process(const string &name, int arrival, int burst_time) {
    this->name = name;
    this->arrival = arrival;
    this->remaining = burst_time;
    this->burst = burst_time;
  }

  process(const string &name, int arrival, int burst_time, int priority) {
    this->name = name;
    this->arrival = arrival;
    this->remaining = burst_time;
    this->burst = burst_time;
    this->priority = priority;
  }

  void print() {
    cout << name << "\n => Arrival Time : " << arrival
         << "\n => Priority : " << priority << "\n => Burst Time : " << burst;
  }

  void printCompletion() { cout << "\n => Completion Time : " << completion; }

  void printTurnaround() { cout << "\n => Turnaround Time : " << turnaround; }

  void printWaiting() { cout << "\n => Waiting Time : " << waiting; }

  /* Comparator used for sort according to arrival */
  bool static arrivalSortComparator(process p1, process p2) {
    return (p1.arrival != p2.arrival) ? p1.arrival < p2.arrival
                                      : p1.priority < p2.priority;
  }

  /* Comparator used for sort according to remaining */
  bool static remainingTimeSortComparator(process p1, process p2) {
    return (p1.remaining != p2.remaining) ? p1.remaining < p2.remaining
                                          : p1.arrival < p2.arrival;
  }

  /* Comparator used for sort according to priority */
  bool static prioritySortComparator(process p1, process p2) {
    return (p1.arrival != p2.arrival) ? p1.priority < p2.priority
                                      : p1.arrival < p2.arrival;
  }

  /* Sort according to Arrival */
  void static sortArrival(vector<process> &ps) {
    sort(ps.begin(), ps.end(), process::arrivalSortComparator);
  }

  /* Sort according to Arrival */
  void static sortArrival(vector<process> &ps, int start, int end) {
    sort(ps.begin() + start, ps.end() - end, process::arrivalSortComparator);
  }

  /* Sort according to Remaining Time */
  void static sortBurst(vector<process> &ps) {
    sort(ps.begin(), ps.end(), process::remainingTimeSortComparator);
  }

  /* Sort according to Remaining Time */
  void static sortBurst(vector<process> &ps, int start, int end) {
    /* cout << endl << start << " " << end; */
    sort(ps.begin() + start, ps.end() - end,
         process::remainingTimeSortComparator);
  }

  /* Sort according to Remaining Time */
  void static sortPriority(vector<process> &ps) {
    sort(ps.begin(), ps.end(), process::prioritySortComparator);
  }

  /* Sort according to Remaining Time */
  void static sortPriority(vector<process> &ps, int start, int end) {
    /* cout << endl << start << " " << end; */
    sort(ps.begin() + start, ps.end() - end, process::prioritySortComparator);
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
                        generateRandomInt(5, 15), generateRandomInt(0, 5)));

  return v;
}

/* Pass arrival and Burst */
vector<process> sampleProcesses(int arrival[], int remaining[], int priority[],
                                int len) {
  vector<process> v;

  for (int i = 0; i < len; i++)
    v.push_back(
        process("P" + to_string(i), arrival[i], remaining[i], priority[i]));

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

void priorityScheduling(vector<process> ps) {
  int pindex;
  int current = 0;

  /* Sort processes by arrival */
  process::sortArrival(ps);

  for (int clock = 0; clock < 100000; clock++) {
    /* cout << clock << "\n"; */
    pindex = 0;

    /* Get avaialable processes according to clock and arrival time */
    while (clock <= ps[pindex].arrival && pindex < ps.size()) {
      /* cout << pindex; */
      pindex++;
    }

    /* Sort ready processes according to priority */
    process::sortPriority(ps, current, pindex);

    if (ps[current].remaining == 0) {
      ps[current].completion = clock; // Completion Time
      ps[current].turnaround =
          abs(ps[current].completion - ps[current].arrival); // Turnaround Time
      ps[current].waiting =
          abs(ps[current].turnaround - ps[current].burst); // Waiting Time
      current++;
    }

    ps[current].remaining--;

    if (ps[current].remaining == 0 && pindex >= ps.size())
      break;
  }

  cout << "=== Result ===" << endl;
  printProcessesWithDetails(ps);

  cout << "=== Stats ===" << endl;
  cout << "Average Waiting Time = " << averageWaitingTime(ps) << endl;
  cout << "Average Turnaround Time = " << averageTurnaroundTime(ps) << endl;
}

int main() {

  vector<process> processes = sampleProcesses(5);
  /* vector<process> processes =
        sampleProcesses(new int[]{0, 2, 4, 4, 7}, new int[]{21, 3, 6, 2},
                        new int[]{2, 1, 4, 3}, 4); */
  /* vector<process> processes = getProcesses(); */

  /* Print Processes */
  printProcesses(processes);

  priorityScheduling(processes);

  return 0;
}