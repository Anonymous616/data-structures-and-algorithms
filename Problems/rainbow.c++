/* Problem Statement: https://www.codechef.com/problems/RAINBOWA */

#include <iostream>
#include <vector>

using namespace std;

string rainbow(vector<int> values) {
  int n = values.size();
  int ptr1 = 0, ptr2 = n - 1;

  // Check for numbers 1 to 5
  for (int i = 1; i < 7; i++) {
    cout << "Break 1" << endl << values[ptr1] << " " << values[ptr2];
    if (values[ptr1] != i || values[ptr2] != i)
      return "no";

    // Count repeating occurences of number (i)
    int occur1 = 0, occur2 = 0;
    while (ptr1 < n && values[ptr1] == i)
      ++occur1, ++ptr1;
    while (ptr2 >= 0 && values[ptr2] == i)
      ++occur2, ++ptr2;

    cout << "Break 2" << endl;
    if (occur1 != occur2)
      return "no";
  }

  return "yes";
}

int main() {

  int test_cases, no_characteristics, num;
  vector<int> values;

  cin >> test_cases; // Get test cases

  for (int i = 0; i < test_cases; i++) {
    cin >> no_characteristics; // Get no of values

    // Get characteristics of values
    for (int j = 0; j < no_characteristics; j++) {
      cin >> num;
      values.push_back(num);
    }

    // Calculate answer
    cout << rainbow(values) << endl;

    // Remove all elements of the vector
    values.clear();
  }

  return 0;
}
