// Q1. Implement Insertion Sort and count comparisons and shifts for best, average and worst cases.
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr, int &comparison, int &shifts) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparison++;
            if (arr[j] > key) {
                shifts++;
                arr[j + 1] = arr[j];
            } else {
                break;
            }
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    cout << "Enter size of array : ";
    int n;
    cin >> n;
    
    if (n <= 0) return 0;

    cout << "Enter Array Elements : ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparison = 0;
    int shifts = 0;
    insertionSort(arr, comparison, shifts);

    cout << "Sorted array: ";
    for (int el : arr) {
        cout << el << " ";
    }
    
    cout << "\nKey comparisons: " << comparison;
    cout << "\nShifts: " << shifts << "\n";
    cout << "Best case: O(n), Average/Worst: O(n^2), Auxiliary space: O(1)\n";
    
    return 0;
}
