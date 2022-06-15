#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> data) {
  for (auto e : data)
    cout << e << "\n";
  cout << endl;
}

// Min Max
map<string, int> minmax(vector<int> &data, int low, int high) {
  map<string, int> m;

  if (low == high) {
    m["Min"] = data[low];
    m["Max"] = data[low];
    return m;
  }

  int mid = (low + high) / 2;

  map<string, int> m1 = minmax(data, low, mid);
  map<string, int> m2 = minmax(data, mid + 1, high);

  m["Min"] = (m1["Min"] < m2["Min"]) ? m1["Min"] : m2["Min"];
  m["Max"] = (m1["Max"] > m2["Max"]) ? m1["Max"] : m2["Max"];

  return m;
}

map<string, int> minmax(vector<int> data) {
  map<string, int> m;

  if (data.size() <= 0) {
    m["Min"] = -1;
    m["Max"] = -1;
    cout << "Inside if" << endl;
    return m;
  }

  return minmax(data, 0, (int)data.size() - 1);
}

int main() {
  vector<int> data = generateRandomIntVector(10);

  cout << "Data: \n";
  print(data);

  cout << "\n==== Min Max =====\n";

  map<string, int> result = minmax(data);

  for (auto r : result)
    cout << " => " << r.first << " : " << r.second << endl;
}
