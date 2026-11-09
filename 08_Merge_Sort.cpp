// Q8. Implement Merge Sort and experimentally verify O(n log n).
#include <bits/stdc++.h>
using namespace std;
long long comparisons = 0;
void mergeParts(vector<int> &a, int l, int m, int r)
{
    vector<int> L(a.begin() + l, a.begin() + m + 1), R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)L.size() && j < (int)R.size())
    {
        ++comparisons;
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < (int)L.size())
        a[k++] = L[i++];
    while (j < (int)R.size())
        a[k++] = R[j++];
}
void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeParts(a, l, m, r);
    }
}
int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    if (n < 0)
        return 0;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(a, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();
    cout << "Sorted: ";
    for (int x : a)
        cout << x << " ";
    cout << "\nComparisons: " << comparisons << "\nTime (microseconds): " << chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << "\nTime: O(n log n), auxiliary space: O(n).\n";
}
