/* Problem Statement: https://www.codechef.com/problems/SALARY */

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int min_moves(vector<int> salaries) {
  int sum = 0, min = salaries[0];

  // Get sum and find min
  for (int salary : salaries) {
    sum += salary;
    min = (min < salary) ? min : salary;
  }

  return sum - salaries.size() * min;
}

int main() {

  int test_cases, no_employees, salary;
  vector<int> salaries;

  cin >> test_cases; // Get test cases

  for (int i = 0; i < test_cases; i++) {
    cin >> no_employees; // Get no of employees

    // Get employee salaries
    for (int j = 0; j < no_employees; j++) {
      cin >> salary;
      salaries.push_back(salary);
    }

    // Calculate answer
    cout << min_moves(salaries) << endl;

    // Remove all elements of the vector
    salaries.clear();
  }

  return 0;
}
