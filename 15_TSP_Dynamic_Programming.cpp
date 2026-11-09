// Q15. Solve Travelling Salesman Problem using Dynamic Programming and print minimum-cost tour.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of cities (1 to 15): ";
    cin >> n;
    if (n < 1 || n > 15)
        return 0;
    vector<vector<int>> d(n, vector<int>(n));
    cout << "Enter cost matrix (use 0 on diagonal):\n";
    for (auto &r : d)
        for (int &x : r)
            cin >> x;
    const long long INF = LLONG_MAX / 4;
    int N = 1 << n;
    vector<vector<long long>> dp(N, vector<long long>(n, INF));
    vector<vector<int>> par(N, vector<int>(n, -1));
    dp[1][0] = 0;
    for (int mask = 1; mask < N; mask++)
        if (mask & 1)
            for (int u = 0; u < n; u++)
                if (dp[mask][u] < INF)
                    for (int v = 0; v < n; v++)
                        if (!(mask >> v & 1))
                        {
                            int nm = mask | 1 << v;
                            long long z = dp[mask][u] + d[u][v];
                            if (z < dp[nm][v])
                                dp[nm][v] = z, par[nm][v] = u;
                        }
    long long best = INF;
    int last = -1;
    for (int u = 0; u < n; u++)
        if (dp[N - 1][u] < INF && dp[N - 1][u] + d[u][0] < best)
            best = dp[N - 1][u] + d[u][0], last = u;
    if (last == -1)
    {
        cout << "No tour found.\n";
        return 0;
    }
    vector<int> path;
    int mask = N - 1, cur = last;
    while (cur != -1)
    {
        path.push_back(cur);
        int p = par[mask][cur];
        mask ^= 1 << cur;
        cur = p;
    }
    reverse(path.begin(), path.end());
    path.push_back(0);
    cout << "Minimum tour cost: " << best << "\nTour: ";
    for (int x : path)
        cout << x + 1 << " ";
    cout << "\nTime: O(n^2*2^n), space: O(n*2^n).\n";
}
