#include <iostream>
#include <vector>
using namespace std;

// Function to determine if there's a subset with the given sum
bool isSubsetSum(const vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Initialize the DP array
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // There is always a subset with sum 0 (empty subset)
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The answer will be in the bottom-right corner of the table
    return dp[n][sum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum)) {
        cout << "Subset with given sum found." << endl;
    } else {
        cout << "No subset with given sum exists." << endl;
    }

    return 0;
}
