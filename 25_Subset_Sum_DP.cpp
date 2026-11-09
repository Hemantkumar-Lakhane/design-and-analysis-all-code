// Q25. Solve Subset Sum using Dynamic Programming.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, target;
    cout << "Enter number of elements and target sum: ";
    cin >> n >> target;
    if (n < 0 || target < 0)
        return 0;
    vector<int> a(n);
    cout << "Enter non-negative elements: ";
    for (int &x : a)
    {
        cin >> x;
        if (x < 0)
        {
            cout << "Only non-negative values supported.\n";
            return 0;
        }
    }
    vector<vector<char>> dp(n + 1, vector<char>(target + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
        for (int s = 0; s <= target; s++)
        {
            dp[i][s] = dp[i - 1][s];
            if (s >= a[i - 1])
                dp[i][s] = dp[i][s] || dp[i - 1][s - a[i - 1]];
        }
    if (!dp[n][target])
    {
        cout << "No subset with the given sum.\n";
        return 0;
    }
    cout << "Subset exists. One subset: ";
    int s = target;
    for (int i = n; i > 0 && s > 0; i--)
        if (!dp[i - 1][s])
        {
            cout << a[i - 1] << " ";
            s -= a[i - 1];
        }
    cout << "\nTime: O(n*target), space: O(n*target).\n";
}
