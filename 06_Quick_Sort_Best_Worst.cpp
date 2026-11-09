// Q6. Implement Quick Sort and analyze best and worst cases for different arrangements.
#include <bits/stdc++.h>
using namespace std;
long long comparisons = 0;
int partitionLast(vector<int> &a, int l, int r)
{
    int pivot = a[r], i = l - 1;
    for (int j = l; j < r; j++)
    {
        ++comparisons;
        if (a[j] <= pivot)
            swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
void quickSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int p = partitionLast(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
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
    quickSort(a, 0, n - 1);
    cout << "Sorted: ";
    for (int x : a)
        cout << x << " ";
    cout << "\nPartition comparisons: " << comparisons << "\nBest/Average: O(n log n), worst: O(n^2), recursion stack worst O(n).\n";
}
