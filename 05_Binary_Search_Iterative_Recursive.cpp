// Q5. Implement iterative and recursive Binary Search and compare their performance.
#include <bits/stdc++.h>
using namespace std;
int iterativeSearch(const vector<int> &a, int key, long long &cmp)
{
    int l = 0, r = (int)a.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        ++cmp;
        if (a[m] == key)
            return m;
        if (a[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int recursiveSearch(const vector<int> &a, int l, int r, int key, long long &cmp)
{
    if (l > r)
        return -1;
    int m = l + (r - l) / 2;
    ++cmp;
    if (a[m] == key)
        return m;
    return a[m] < key ? recursiveSearch(a, m + 1, r, key, cmp) : recursiveSearch(a, l, m - 1, key, cmp);
}
int main()
{
    int n, key;
    cout << "Enter size: ";
    cin >> n;
    if (n < 0)
        return 0;
    vector<int> a(n);
    cout << "Enter sorted elements: ";
    for (int &x : a)
        cin >> x;
    cout << "Enter key: ";
    cin >> key;
    long long c1 = 0, c2 = 0;
    cout << "Iterative index: " << iterativeSearch(a, key, c1) << " comparisons: " << c1 << "\n";
    cout << "Recursive index: " << recursiveSearch(a, 0, n - 1, key, c2) << " comparisons: " << c2 << "\n";
    cout << "Time: O(log n); iterative space O(1), recursive stack O(log n).\n";
}
