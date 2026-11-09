// Q10. Find maximum and minimum simultaneously using Divide and Conquer.
#include <bits/stdc++.h>
using namespace std;
struct Ans
{
    int mn, mx;
    long long comparisons;
};
Ans solve(const vector<int> &a, int l, int r)
{
    if (l == r)
        return {a[l], a[l], 0};
    if (r == l + 1)
    {
        if (a[l] < a[r])
            return {a[l], a[r], 1};
        return {a[r], a[l], 1};
    }
    int m = l + (r - l) / 2;
    Ans x = solve(a, l, m), y = solve(a, m + 1, r);
    return {min(x.mn, y.mn), max(x.mx, y.mx), x.comparisons + y.comparisons + 2};
}
int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    if (n <= 0)
        return 0;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;
    Ans z = solve(a, 0, n - 1);
    cout << "Minimum: " << z.mn << "\nMaximum: " << z.mx << "\nComparisons: " << z.comparisons << "\nTime: O(n), auxiliary recursion space: O(log n).\n";
}
