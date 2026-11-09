// Q17. Solve Fractional Knapsack using Greedy and compare conceptually with 0/1 Knapsack.
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    double w, v;
};
int main()
{
    int n;
    double W;
    cout << "Enter item count and capacity: ";
    cin >> n >> W;
    if (n < 0 || W < 0)
        return 0;
    vector<Item> a(n);
    cout << "Enter weight and value for each item:\n";
    for (auto &x : a)
        cin >> x.w >> x.v;
    sort(a.begin(), a.end(), [](auto x, auto y)
         { return x.v / x.w > y.v / y.w; });
    double total = 0;
    cout << "Fractions selected:\n";
    for (int i = 0; i < n && W > 0; i++)
    {
        if (a[i].w <= 0)
            continue;
        double take = min(1.0, W / a[i].w);
        total += take * a[i].v;
        W -= take * a[i].w;
        cout << take << " of item with weight " << a[i].w << " and value " << a[i].v << "\n";
    }
    cout << "Maximum fractional value: " << total << "\nFractional greedy: O(n log n); 0/1 knapsack does not generally use this greedy rule and is commonly solved by DP O(nW).\n";
}
