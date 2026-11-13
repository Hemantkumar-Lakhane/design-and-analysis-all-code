// Q2. Implement Bubble Sort and analyze time and space complexity for different input sizes.
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr, int &comparison, int &shifts) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            comparison++;
            if (arr[j] > arr[j + 1]) {
                shifts++;
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    if (n < 0) return 0;

    cout << "Enter elements: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int comparison = 0;
    int shifts = 0;
    bubbleSort(arr, comparison, shifts);

    cout << "Sorted array: ";
    for (int el : arr) {
        cout << el << " ";
    }
    
    cout << "\nComparisons: " << comparison;
    cout << "\nSwaps: " << shifts;
    cout << "\nBest: O(n), Average/Worst: O(n^2), Auxiliary space: O(1)\n";
    
    return 0;
}
