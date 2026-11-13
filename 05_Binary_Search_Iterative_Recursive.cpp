// Q5. Implement iterative and recursive Binary Search and compare their performance.
#include <iostream>
#include <vector>
using namespace std;

int iterativeSearch(vector<int> &v, int key, int &cmp) {
    int start = 0;
    int end = v.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        cmp++;
        if (v[mid] == key) {
            return mid;
        } else if (v[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int recursiveSearch(vector<int> &v, int key, int start, int end, int &cmp) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        cmp++;
        if (v[mid] == key) {
            return mid;
        } else if (v[mid] > key) {
            return recursiveSearch(v, key, start, mid - 1, cmp);
        } else {
            return recursiveSearch(v, key, mid + 1, end, cmp);
        }
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter size: ";
    cin >> n;
    if (n <= 0) return 0;

    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key: ";
    cin >> key;

    int c1 = 0, c2 = 0;
    int idx1 = iterativeSearch(arr, key, c1);
    int idx2 = recursiveSearch(arr, key, 0, n - 1, c2);

    cout << "Iterative index: " << idx1 << " | comparisons: " << c1 << "\n";
    cout << "Recursive index: " << idx2 << " | comparisons: " << c2 << "\n";
    cout << "Time: O(log n); iterative space O(1), recursive stack O(log n).\n";

    return 0;
}
