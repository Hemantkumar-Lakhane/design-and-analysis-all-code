// Q27. Solve Rod Cutting using Dynamic Programming to obtain maximum revenue.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter rod length: ";
    cin >> n;
    if (n < 0)
        return 0;
    vector<int> price(n + 1);
    cout << "Enter prices for lengths 1 to " << n << ": ";
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    vector<int> dp(n + 1, 0), first(n + 1, 0);
    for (int len = 1; len <= n; len++)
        for (int cut = 1; cut <= len; cut++)
            if (price[cut] + dp[len - cut] > dp[len])
                dp[len] = price[cut] + dp[len - cut], first[len] = cut;
    cout << "Maximum revenue: " << dp[n] << "\nCuts: ";
    while (n > 0 && first[n] > 0)
    {
        cout << first[n] << " ";
        n -= first[n];
    }
    cout << "\nTime: O(n^2), space: O(n).\n";
}
