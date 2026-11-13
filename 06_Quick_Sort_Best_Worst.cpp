// Q6. Implement Quick Sort and analyze best and worst cases for different arrangements.
#include <iostream>
#include <vector>
using namespace std;

int comparisons = 0;

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end]; // last element as pivot
    int i = start - 1;

    for (int j = start; j < end; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quicksort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    if (n < 0) return 0;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nPartition comparisons: " << comparisons;
    cout << "\nBest/Average: O(n log n), worst: O(n^2), recursion stack worst O(n).\n";

    return 0;
}
