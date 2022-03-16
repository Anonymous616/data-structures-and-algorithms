/* Problem Statement: https://www.codechef.com/problems/CNOTE */

#include <iostream>
#include <vector>

using namespace std;

string chef_notebooks(int poetry_pages, int nb_pages, int kubles, vector<vector<int>> book_options) {
    int pages_req = poetry_pages - nb_pages;
    for (auto book : book_options) {
        if (book[0] >= pages_req && book[1] <= kubles)
            return "LuckyChef";
    }
    
    return "UnluckyChef";
}

int main() {

    int test_cases,
        poetry_pages,
        nb_pages_left,
        kubles_left,
        no_book_options,
        pages,
        price;
    vector<vector<int>> book_options;

    cin >> test_cases; // Get test cases

    for (int i = 0; i < test_cases; i++) {
        cin >> poetry_pages; // Get poetry pages to write
        cin >> nb_pages_left; // Get pages left in the notebook
        cin >> kubles_left; // Get kubles left
        cin >> no_book_options; // Get number of books that can be chosen

        // Get pages and price of books that can be bought
        for (int j = 0; j < no_book_options; j++) {
            cin >> pages >> price;
            book_options.push_back(*new vector<int>({pages, price}));
        }

        // Calculate answer
        cout << chef_notebooks(poetry_pages, nb_pages_left, kubles_left, book_options) << endl;

        // Remove all elements of the vector
        book_options.clear();
    }

    return 0;
}
