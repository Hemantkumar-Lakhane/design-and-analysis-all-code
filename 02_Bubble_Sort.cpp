// Q2. Implement Bubble Sort and analyze time and space complexity for different input sizes.
#include <bits/stdc++.h>
using namespace std;
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
    long long comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        bool changed = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            ++comparisons;
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ++swaps;
                changed = true;
            }
        }
        if (!changed)
            break;
    }
    cout << "Sorted array: ";
    for (int x : a)
        cout << x << " ";
    cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps;
    cout << "\nBest: O(n), Average/Worst: O(n^2), Auxiliary space: O(1)\n";
}
