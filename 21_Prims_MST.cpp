// Q21. Implement Prim's algorithm for Minimum Spanning Tree.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    if (n <= 0)
        return 0;
    const int INF = 1e9;
    vector<vector<int>> g(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 means no edge; diagonal 0):\n";
    for (auto &r : g)
        for (int &x : r)
            cin >> x;
    vector<int> key(n, INF), parent(n, -1);
    vector<bool> used(n, false);
    key[0] = 0;
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!used[v] && (u == -1 || key[v] < key[u]))
                u = v;
        if (u == -1 || key[u] == INF)
        {
            cout << "Graph is disconnected; no spanning tree exists.\n";
            return 0;
        }
        used[u] = true;
        total += key[u];
        for (int v = 0; v < n; v++)
            if (g[u][v] > 0 && !used[v] && g[u][v] < key[v])
                key[v] = g[u][v], parent[v] = u;
    }
    cout << "MST edges:\n";
    for (int v = 1; v < n; v++)
        cout << parent[v] + 1 << " - " << v + 1 << " : " << key[v] << "\n";
    cout << "Total weight: " << total << "\nTime: O(V^2) with adjacency matrix.\n";
}
