// Q4. Implement matrix multiplication and determine time and space complexity.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of matrix B: ";
    cin >> r2 >> c2;
    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 || c1 != r2)
    {
        cout << "Invalid dimensions.\n";
        return 0;
    }
    vector<vector<long long>> A(r1, vector<long long>(c1)), B(r2, vector<long long>(c2)), C(r1, vector<long long>(c2, 0));
    cout << "Enter matrix A:\n";
    for (auto &row : A)
        for (auto &x : row)
            cin >> x;
    cout << "Enter matrix B:\n";
    for (auto &row : B)
        for (auto &x : row)
            cin >> x;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
    cout << "Product matrix:\n";
    for (auto &row : C)
    {
        for (auto x : row)
            cout << x << " ";
        cout << "\n";
    }
    cout << "Time: O(r1*c1*c2); output space: O(r1*c2).\n";
}
