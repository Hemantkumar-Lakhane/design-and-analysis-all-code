// Q16. Implement TSP with DP and compare complexity with brute force for small inputs.
#include <bits/stdc++.h>
using namespace std;
long long brute(const vector<vector<int>> &d, vector<int> &p, int pos, long long cost, long long &best)
{
    int n = d.size();
    if (pos == n)
    {
        best = min(best, cost + d[p[pos - 1]][0]);
        return best;
    }
    for (int i = 1; i < n; i++)
        if (find(p.begin(), p.begin() + pos, i) == p.begin() + pos)
        {
            p[pos] = i;
            brute(d, p, pos + 1, cost + d[p[pos - 1]][i], best);
        }
    return best;
}
long long dpTSP(const vector<vector<int>> &d)
{
    int n = d.size(), N = 1 << n;
    const long long I = LLONG_MAX / 4;
    vector<vector<long long>> dp(N, vector<long long>(n, I));
    dp[1][0] = 0;
    for (int m = 1; m < N; m++)
        if (m & 1)
            for (int u = 0; u < n; u++)
                if (dp[m][u] < I)
                    for (int v = 1; v < n; v++)
                        if (!(m >> v & 1))
                            dp[m | 1 << v][v] = min(dp[m | 1 << v][v], dp[m][u] + d[u][v]);
    long long ans = I;
    for (int u = 0; u < n; u++)
        ans = min(ans, dp[N - 1][u] + d[u][0]);
    return ans;
}
int main()
{
    int n;
    cout << "Enter cities (1 to 10 recommended): ";
    cin >> n;
    if (n < 1 || n > 15)
        return 0;
    vector<vector<int>> d(n, vector<int>(n));
    cout << "Enter cost matrix:\n";
    for (auto &r : d)
        for (int &x : r)
            cin >> x;
    auto s = chrono::steady_clock::now();
    long long a = dpTSP(d);
    auto m = chrono::steady_clock::now();
    long long b = 0;
    if (n <= 10)
    {
        vector<int> p(n);
        p[0] = 0;
        b = LLONG_MAX;
        brute(d, p, 1, 0, b);
    }
    auto e = chrono::steady_clock::now();
    cout << "DP cost: " << a << " time(us): " << chrono::duration_cast<chrono::microseconds>(m - s).count() << "\n";
    if (n <= 10)
        cout << "Brute force cost: " << b << " time(us): " << chrono::duration_cast<chrono::microseconds>(e - m).count() << "\n";
    else
        cout << "Brute force skipped for n > 10.\n";
    cout << "DP O(n^2*2^n); brute force O(n!).\n";
}
