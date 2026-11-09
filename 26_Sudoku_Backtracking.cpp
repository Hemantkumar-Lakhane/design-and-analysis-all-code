// Q26. Solve Sudoku using Backtracking and display the completed grid.
#include <bits/stdc++.h>
using namespace std;
int a[9][9];
bool safe(int r, int c, int x)
{
    for (int i = 0; i < 9; i++)
        if (a[r][i] == x || a[i][c] == x)
            return false;
    int br = r / 3 * 3, bc = c / 3 * 3;
    for (int i = br; i < br + 3; i++)
        for (int j = bc; j < bc + 3; j++)
            if (a[i][j] == x)
                return false;
    return true;
}
bool solve()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (a[i][j] == 0)
            {
                for (int x = 1; x <= 9; x++)
                    if (safe(i, j, x))
                    {
                        a[i][j] = x;
                        if (solve())
                            return true;
                        a[i][j] = 0;
                    }
                return false;
            }
    return true;
}
int main()
{
    cout << "Enter Sudoku grid (use 0 for empty cells):\n";
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    if (!solve())
    {
        cout << "No solution exists.\n";
        return 0;
    }
    cout << "Solved Sudoku:\n";
    for (auto &r : a)
    {
        for (int x : r)
            cout << x << " ";
        cout << "\n";
    }
}
