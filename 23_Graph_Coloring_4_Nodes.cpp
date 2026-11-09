// Q23. Solve graph coloring problem for 4 nodes using Backtracking.
#include <bits/stdc++.h>
using namespace std;
const int N = 4;
int g[N][N], color[N], m, solutions = 0;
bool safe(int v, int c)
{
    for (int i = 0; i < N; i++)
        if (g[v][i] && color[i] == c)
            return false;
    return true;
}
void solve(int v)
{
    if (v == N)
    {
        solutions++;
        cout << "Coloring " << solutions << ": ";
        for (int x : color)
            cout << x << " ";
        cout << "\n";
        return;
    }
    for (int c = 1; c <= m; c++)
        if (safe(v, c))
        {
            color[v] = c;
            solve(v + 1);
            color[v] = 0;
        }
}
int main()
{
    cout << "Enter 4x4 adjacency matrix:\n";
    for (auto &r : g)
        for (int &x : r)
            cin >> x;
    cout << "Enter number of colors: ";
    cin >> m;
    if (m <= 0)
        return 0;
    solve(0);
    if (!solutions)
        cout << "No valid coloring exists.\n";
}
