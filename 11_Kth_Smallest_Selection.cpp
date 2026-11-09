// Q11. Find kth smallest element using Divide and Conquer (Quickselect).
#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &a, int l, int r)
{
    int p = a[r], i = l;
    for (int j = l; j < r; j++)
        if (a[j] <= p)
            swap(a[i++], a[j]);
    swap(a[i], a[r]);
    return i;
}
int quickselect(vector<int> &a, int l, int r, int k)
{
    while (l <= r)
    {
        int p = partition(a, l, r);
        if (p == k)
            return a[p];
        if (p < k)
            l = p + 1;
        else
            r = p - 1;
    }
    return -1;
}
int main()
{
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0)
        return 0;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;
    cout << "Enter k (1 to n): ";
    cin >> k;
    if (k < 1 || k > n)
    {
        cout << "Invalid k.\n";
        return 0;
    }
    cout << k << "th smallest element: " << quickselect(a, 0, n - 1, k - 1) << "\nAverage time O(n), worst O(n^2), auxiliary space O(1) iterative.\n";
}
