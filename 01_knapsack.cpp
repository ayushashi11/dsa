#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int stepCount = 0;

struct Item {
    int weight;
    int value;
};

bool cmp(Item a, Item b) {
    return (double) a.value / a.weight > (double) b.value / b.weight;
}

int knapsack(int capacity, vector<Item> items) {
    sort(items.begin(), items.end(), cmp); // sort items in decreasing order of value-to-weight ratio
    int n = items.size();
    int totalValue = 0;
    stepCount += n*floor(log2(n));
    for (int i = 0; i < n && capacity > 0; i++) {
        int w = min(capacity, items[i].weight); // choose the maximum weight that can be added
        totalValue += w * items[i].value / items[i].weight; // add the proportional value of the chosen weight
        capacity -= w; // reduce the capacity of knapsack
        stepCount++;
    }
    return totalValue;
}

int main() {
    int n, c; // number of items and capacity of knapsack
    cin >> n >> c;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    int maxTotalValue = knapsack(c, items);
    cout << "Maximum total value: " << maxTotalValue << endl;

    return 0;
}
