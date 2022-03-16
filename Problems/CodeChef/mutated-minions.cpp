/* Problem Statement: https://www.codechef.com/problems/CHN15A */

#include <iostream>
#include <vector>

using namespace std;

int mutated_minions(int base, vector<int> minions) {
  int count = 0;

  // Get new characteristic and check if wolverine-like
  for (int minion : minions)
    if ((base + minion) % 7 == 0)
      count++;

  return count;
}

int main() {

  int test_cases, no_characteristics, base_characteristic, characteristic;
  vector<int> minions;

  cin >> test_cases; // Get test cases

  for (int i = 0; i < test_cases; i++) {
    cin >> no_characteristics;  // Get no of minions
    cin >> base_characteristic; // Get base characteristic

    // Get characteristics of minions
    for (int j = 0; j < no_characteristics; j++) {
      cin >> characteristic;
      minions.push_back(characteristic);
    }

    // Calculate answer
    cout << mutated_minions(base_characteristic, minions) << endl;

    // Remove all elements of the vector
    minions.clear();
  }

  return 0;
}
