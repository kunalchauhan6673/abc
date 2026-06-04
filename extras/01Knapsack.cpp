#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int W, int wt[], int val[]) {

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (wt[i - 1] > w)
                dp[i][w] = dp[i - 1][w];

            else
                dp[i][w] = max(
                    dp[i - 1][w],
                    dp[i - 1][w - wt[i - 1]] + val[i - 1]
                );
        }
    }

    int w = W, totalWeight = 0;

    cout << "\nSelected items (1-based): ";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            totalWeight += wt[i - 1];
            w -= wt[i - 1];
        }
    }

    cout << "\nWeight used: " << totalWeight;
    cout << "\nRemaining capacity: " << W - totalWeight;

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], val[n];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    int result = knapsack(n, W, wt, val);

    cout << "\nMaximum Profit: " << result;

    return 0;
}
