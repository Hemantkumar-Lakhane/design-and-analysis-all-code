// Q22. Solve N-Queens using Backtracking and display all possible solutions.
#include <bits/stdc++.h>
using namespace std;
int n, countSolutions = 0;
vector<int> pos;
bool safe(int row, int col)
{
    for (int r = 0; r < row; r++)
        if (pos[r] == col || abs(pos[r] - col) == abs(r - row))
            return false;
    return true;
}
void solve(int row)
{
    if (row == n)
    {
        countSolutions++;
        cout << "\nSolution " << countSolutions << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (pos[i] == j ? "Q " : " .");
            cout << "\n";
        }
        return;
    }
    for (int c = 0; c < n; c++)
        if (safe(row, c))
        {
            pos[row] = c;
            solve(row + 1);
        }
}
int main()
{
    cout << "Enter N (1 to 12 recommended): ";
    cin >> n;
    if (n < 1 || n > 12)
        return 0;
    pos.resize(n);
    solve(0);
    cout << "\nTotal solutions: " << countSolutions << "\n";
}
