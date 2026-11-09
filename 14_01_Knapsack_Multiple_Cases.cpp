// Q14. Solve 0/1 Knapsack for multiple test cases and compare capacities.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    if (n < 0)
        return 0;
    vector<int> w(n), v(n);
    cout << "Enter weights: ";
    for (int &x : w)
        cin >> x;
    cout << "Enter values: ";
    for (int &x : v)
        cin >> x;
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    while (t--)
    {
        int W;
        cout << "Capacity: ";
        cin >> W;
        if (W < 0)
            continue;
        vector<int> dp(W + 1);
        for (int i = 0; i < n; i++)
            for (int c = W; c >= w[i]; c--)
                dp[c] = max(dp[c], v[i] + dp[c - w[i]]);
        cout << "Maximum value for capacity " << W << ": " << dp[W] << "\n";
    }
    cout << "Each test case: O(nW) time and O(W) space.\n";
}
