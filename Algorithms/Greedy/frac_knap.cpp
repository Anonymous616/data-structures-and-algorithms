#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Knap {
    public:
    string item;
    int profit;
    int weight;
    float ratio;

    Knap(string item, int profit, int weight) {
        this->item = item;
        this->profit = profit;
        this->weight = weight;
        this->ratio = (float) profit / weight;
        this->print();
    }

    void print() {
        cout << item << "\t" << profit << "\t" << weight << "\t" << ratio << "\t" << endl;
    }

    static void sortByRatios(vector<Knap> &sack) {
        sort(sack.begin(), sack.end(), Knap::sortRatioComparator);
        /* for (auto a : sack) { cout << a.item; } */
    }

    static bool sortRatioComparator(Knap a, Knap b) {
        return a.ratio > b.ratio;
    }

    static float findMaxProfit(vector<Knap> &sack, int maxW) {
        int weight = 0;
        float profit = 0;
        vector<string> items;


        for (auto s : sack) {
            if (weight + s.weight > maxW)
                break;

            weight += s.weight;
            profit += s.profit;
            items.push_back(s.item);
        }

        int diffW = maxW - weight;

        if (diffW != 0 && items.size() != sack.size()) {
            int noOfItems = (int) items.size(); // No of items in sack
            Knap nextItem = sack[noOfItems]; // Index of next item

            items.push_back(nextItem.item);
            weight += diffW;
            profit += diffW * nextItem.ratio;
        }

        cout << "\n============================" << endl;
        cout << "\tResult" << endl;
        cout << "============================" << endl;

        cout << " => Items in Knapsack : \n\t";
        for (auto item : items) cout << item << " ";
        cout << "\n => Weight of Knapsack : " << weight << endl;
        cout << " => Max Profit : " << profit << endl;

        return profit;
    }

};

float fractionalKnapsack(vector<string> items, vector<int> profits, vector<int> weights, int maxW) {
    vector<Knap> sack;

    cout << "===============================" << endl;
    cout << "\tInitial Sack" << endl;
    cout << "===============================" << endl;

    cout << "Item\tProfit\tWeight\tRatio" << endl;
    cout << "----\t------\t------\t-----" << endl;

    for (int i = 0; i < items.size(); i++)
        sack.push_back(Knap(items[i], profits[i], weights[i]));

    Knap::sortByRatios(sack);

    cout << "===============================" << endl;
    cout << "\tSorted Sack" << endl;
    cout << "===============================" << endl;
    cout << "Item\tProfit\tWeight\tRatio" << endl;
    cout << "----\t------\t------\t-----" << endl;
    for (auto item : sack)
        item.print();

    return Knap::findMaxProfit(sack, maxW);
}

int main() {

    /* vector<string> items = {"A", "B", "C", "D"}; */
    /* vector<int> profits = {280, 100, 120, 120}; */
    /* vector<int> weights = {40, 10, 20, 24}; */
    vector<string> items = {"A", "B", "C", "D", "E", "F", "G"};
    vector<int> profits = {5, 10, 15, 7, 8, 9, 4};
    vector<int> weights = {1, 3, 5, 4, 1, 3, 2};
    float maxW = 15;

    float result = fractionalKnapsack(items, profits, weights, maxW);

    return 0;
}
