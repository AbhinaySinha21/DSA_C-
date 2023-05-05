#include <bits/stdc++.h>

using namespace std;

class DSU
{
public:
    vector<int> parent;
    vector<int> rank;

    void createSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            if (rank[px] < rank[py])
            {
                parent[px] = py;
            }
            else if (rank[px] > rank[py])
            {
                parent[py] = px;
            }
            else
            {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
};

struct Edge
{
    int u, v, w;

    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU ds;
    ds.createSet(n);

    int ans = 0;
    for (Edge edge : edges)
    {
        if (ds.find(edge.u) != ds.find(edge.v))
        {
            ds.merge(edge.u, edge.v);
            cout << edge.u << " -> " << edge.v << " = " << edge.w << "\n";
            ans += edge.w;
        }
    }

    cout << ans << endl;

    return 0;
}
