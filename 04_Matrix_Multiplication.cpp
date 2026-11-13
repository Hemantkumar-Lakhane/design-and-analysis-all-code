// Q4. Implement matrix multiplication and determine time and space complexity.
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> matrix_Multiply(vector<vector<long long>> &mat1, int row1, int col1, vector<vector<long long>> &mat2, int col2) {
    vector<vector<long long>> result(row1, vector<long long>(col2, 0));

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int row1, col1, row2, col2;
    cout << "Enter rows and columns of matrix A: ";
    cin >> row1 >> col1;
    cout << "Enter rows and columns of matrix B: ";
    cin >> row2 >> col2;

    if (row1 <= 0 || col1 <= 0 || row2 <= 0 || col2 <= 0 || col1 != row2) {
        cout << "Invalid dimensions.\n";
        return 0;
    }

    vector<vector<long long>> mat1(row1, vector<long long>(col1));
    vector<vector<long long>> mat2(row2, vector<long long>(col2));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter matrix B:\n";
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> mat2[i][j];
        }
    }

    vector<vector<long long>> ans = matrix_Multiply(mat1, row1, col1, mat2, col2);

    cout << "Product matrix:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Time: O(r1*c1*c2); output space: O(r1*c2).\n";

    return 0;
}
