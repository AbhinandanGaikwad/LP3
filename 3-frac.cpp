#include <bits/stdc++.h>
using namespace std;

struct Item {
    double value;
    double weight;
};

// Comparator function to sort by value/weight ratio (descending)
bool cmp(struct Item a, struct Item b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2; // Higher ratio first
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by decreasing value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0; // Maximum value we can carry
    int currentWeight = 0;

    for (auto& it : items) {
        if (currentWeight + it.weight <= W) {
            // Take the whole item
            currentWeight += it.weight;
            totalValue += it.value;
        } else {
            // Take fraction of the remaining capacity
            int remain = W - currentWeight;
            totalValue += it.value * ((double)remain / it.weight);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n; // Number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int W; // Knapsack capacity
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    double maxVal = fractionalKnapsack(W, items);

    cout << fixed << setprecision(2);
    cout << "\nMaximum value in knapsack = " << maxVal << endl;

    return 0;
}
