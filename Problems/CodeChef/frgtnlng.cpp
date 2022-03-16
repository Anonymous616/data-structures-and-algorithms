/* Problem Statement: https://www.codechef.com/problems/FRGTNLNG */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

string frgtnlng(vector<string> words, set<string> phrases) {

    string result = "";

    for (int i = 0; i < words.size(); i++) {
    	// Search for phrase
        if (phrases.find(words[i]) != phrases.end())
            result += "YES ";
        else
            result += "NO ";
    }

    return result;
}

int main() {

  int test_cases, no_words, no_mphrases, n;
  string word;
  vector<string> words;
  set<string> phrases;

  cin >> test_cases; // Get test cases

  for (int i = 0; i < test_cases; i++) {
    cin >> no_words >> no_mphrases; // Get no of words and modern phrases

    // Get words from the forgotten language
    for (int i = 0; i < no_words; i++) {
      cin >> word;
      words.push_back(word);
    }

    // Storing all phrases
    for (int i = 0; i < no_mphrases; i++) {
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> word;
            phrases.insert(word);
        }
    }

    // Calculate answer
    cout << frgtnlng(words, phrases) << endl;

    // Remove all elements of the vector
    words.clear(); phrases.clear();
  }

  return 0;
}
