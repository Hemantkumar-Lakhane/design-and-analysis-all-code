// Q13. Solve 0/1 Knapsack using DP and display selected items.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, W;
    cout << "Enter number of items and capacity: ";
    cin >> n >> W;
    if (n < 0 || W < 0)
        return 0;
    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for (int &x : wt)
        cin >> x;
    cout << "Enter values: ";
    for (int &x : val)
        cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++)
        {
            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    cout << "Maximum value: " << dp[n][W] << "\nSelected item numbers: ";
    int w = W;
    for (int i = n; i >= 1; i--)
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << i << " ";
            w -= wt[i - 1];
        }
    cout << "\nTime: O(nW), space: O(nW).\n";
}
