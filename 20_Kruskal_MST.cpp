// Q20. Implement Kruskal's algorithm for Minimum Spanning Tree.
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, w;
};
struct DSU
{
    vector<int> p, r;
    DSU(int n) : p(n), r(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};
int main()
{
    int n, m;
    cout << "Enter vertices and edges: ";
    cin >> n >> m;
    if (n <= 0 || m < 0)
        return 0;
    vector<Edge> e(m);
    cout << "Enter edges (u v weight), vertices 1..n:\n";
    for (auto &x : e)
    {
        cin >> x.u >> x.v >> x.w;
        --x.u;
        --x.v;
    }
    sort(e.begin(), e.end(), [](auto a, auto b)
         { return a.w < b.w; });
    DSU d(n);
    long long cost = 0;
    int used = 0;
    for (auto x : e)
        if (d.unite(x.u, x.v))
        {
            cout << x.u + 1 << " - " << x.v + 1 << " : " << x.w << "\n";
            cost += x.w;
            used++;
        }
    if (used != n - 1)
        cout << "Graph is disconnected; no spanning tree exists.\n";
    else
        cout << "MST total weight: " << cost << "\n";
    cout << "Time: O(E log E).\n";
}
