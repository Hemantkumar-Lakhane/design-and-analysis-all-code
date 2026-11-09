// Q1. Implement Insertion Sort and count comparisons and shifts for best, average and worst cases.
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &a, long long &comparisons, long long &shifts)
{
    comparisons = shifts = 0;
    for (int i = 1; i < (int)a.size(); ++i)
    {
        int key = a[i], j = i - 1;
        while (j >= 0)
        {
            ++comparisons;
            if (a[j] > key)
            {
                a[j + 1] = a[j];
                ++shifts;
                --j;
            }
            else
                break;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n < 0)
        return 0;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;
    long long c, s;
    insertionSort(a, c, s);
    cout << "Sorted array: ";
    for (int x : a)
        cout << x << " ";
    cout << "\nKey comparisons: " << c << "\nShifts: " << s << "\n";
    cout << "Best case: O(n), Average/Worst: O(n^2), Auxiliary space: O(1)\n";
}
