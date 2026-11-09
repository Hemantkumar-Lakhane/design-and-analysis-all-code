// Q7. Implement Quick Sort with first, last, middle and random pivot strategies.
#include <bits/stdc++.h>
using namespace std;
long long comps;
int partitionAt(vector<int> &a, int l, int r, int p)
{
    swap(a[p], a[r]);
    int pivot = a[r], i = l - 1;
    for (int j = l; j < r; j++)
    {
        ++comps;
        if (a[j] <= pivot)
            swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
void qs(vector<int> &a, int l, int r, int mode, mt19937 &gen)
{
    if (l >= r)
        return;
    int p = l;
    if (mode == 1)
        p = r;
    else if (mode == 2)
        p = l + (r - l) / 2;
    else if (mode == 3)
        p = uniform_int_distribution<int>(l, r)(gen);
    int q = partitionAt(a, l, r, p);
    qs(a, l, q - 1, mode, gen);
    qs(a, q + 1, r, mode, gen);
}
int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    if (n < 0)
        return 0;
    vector<int> orig(n);
    cout << "Enter elements: ";
    for (int &x : orig)
        cin >> x;
    mt19937 gen((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    string names[] = {"First", "Last", "Middle", "Random"};
    for (int mode = 0; mode < 4; mode++)
    {
        vector<int> a = orig;
        comps = 0;
        qs(a, 0, n - 1, mode, gen);
        cout << names[mode] << " pivot comparisons: " << comps << "\n";
    }
    cout << "Expected/average: O(n log n); worst: O(n^2). Results depend on input and pivot choices.\n";
}
