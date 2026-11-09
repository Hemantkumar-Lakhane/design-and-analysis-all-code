// Q9. Find majority element using Divide and Conquer and compare with counting.
#include <bits/stdc++.h>
using namespace std;
int candidate(const vector<int> &a, int l, int r)
{
    if (l == r)
        return a[l];
    int m = l + (r - l) / 2, x = candidate(a, l, m), y = candidate(a, m + 1, r);
    if (x == y)
        return x;
    int cx = 0, cy = 0;
    for (int i = l; i <= r; i++)
    {
        cx += (a[i] == x);
        cy += (a[i] == y);
    }
    return cx > cy ? x : y;
}
int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Empty array.\n";
        return 0;
    }
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;
    int cand = candidate(a, 0, n - 1), count = 0;
    for (int x : a)
        count += (x == cand);
    if (count > n / 2)
        cout << "Majority element (D&C): " << cand << "\n";
    else
        cout << "No majority element.\n";
    unordered_map<int, int> freq;
    for (int x : a)
        freq[x]++;
    cout << "Counting approach: ";
    bool found = false;
    for (auto const &pair : freq)
    {
        int v = pair.first;  // element
        int c = pair.second; // count/frequency
        if (c > n / 2)
        {
            cout << v;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "No majority element";
    cout << "\nD&C time O(n log n) in this implementation; counting average O(n), extra space O(n).\n";
}
