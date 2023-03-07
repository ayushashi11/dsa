#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 100;

int n; // number of items
int c; // capacity of container
int w[MAX_N]; // weight of each item
int stepCount=0;

void packItems() {
    vector<pair<double, int>> items(n);
    stepCount+=2;
    for (int i = 0; i < n; i++) {
        stepCount++;
        items[i] = make_pair((double) w[i] / c, i);
    }
    stepCount += items.size()*floor(log2(items.size()));
    sort(items.rbegin(), items.rend()); // sort items in descending order of efficiency
    double currWeight = 0.0;
    for (int i = 0; i < n; i++) {
        stepCount+=2;
        if (currWeight + w[items[i].second] <= c) { // if item fits in container
            cout << "Item " << items[i].second+1 << " is packed into the container" << endl;
            currWeight += w[items[i].second];
            stepCount+=2;
        }
    }
}

int main() {
    cin >> n >> c; // read in number of items and capacity of container
    for (int i = 0; i < n; i++) {
        cin >> w[i]; // read in weight of each item
    }

    packItems(); // call the function to pack the items
    cout<<"step count: "<<stepCount<<endl;
    return 0;
}
