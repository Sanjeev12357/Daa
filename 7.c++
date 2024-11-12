#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Memoization table
int memo[1001][1001]; // Assumes max items <= 1000 and max weight <= 1000

// Function to implement 0/1 Knapsack using memoization
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Base case: no items left or no capacity left in the knapsack
    if (n == 0 || W == 0) {
        return 0;
    }

    // Check if value is already computed
    if (memo[n][W] != -1) {
        return memo[n][W];
    }

    // If the weight of the nth item is more than the knapsack capacity W, skip it
    if (weights[n - 1] > W) {
        memo[n][W] = knapsack(W, weights, values, n - 1);
    } else {
        // Maximize value by either including or excluding the nth item
        int include = values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1);
        int exclude = knapsack(W, weights, values, n - 1);
        memo[n][W] = max(include, exclude);
    }

    return memo[n][W];
}

int main() {
    int n = 4;                        // Number of items
    vector<int> values = {60, 100, 120, 50};   // Values of items
    vector<int> weights = {10, 20, 30, 5};     // Weights of items
    int W = 50;                       // Maximum capacity of knapsack

    // Initialize memoization table with -1 (indicating uncomputed values)
    memset(memo, -1, sizeof(memo));

    int maxProfit = knapsack(W, weights, values, n);
    cout << "Maximum value in knapsack: " << maxProfit << endl;

    return 0;
}

