#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(PrimsPair *a, PrimsPair *b)
    {
        return a->cost > b->cost;
    }
};
class PrimsPair
{
public:
    int vtx;
    int acqvtx;
    int cost;

    PrimsPair(int vtx, int acqvtx, int cost)
    {
        this->vtx = vtx;
        this->acqvtx = acqvtx;
        this->cost = cost;
    }
};
class Prims
{
    unordered_map<int, unordered_map<int, int>> m;

public:
    Prims(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            m[i] = {};
        }
    }
    void AddEdge(int v1, int v2, int cost)
    {
        m[v1][v2] = cost;
        m[v2][v1] = cost;
    }
    int PrimsAlgo()
    {
        priority_queue<PrimsPair *, vector<PrimsPair *>, compare> pq;
        pq.push(new PrimsPair(1, 1, 0));
        set<int> visited;
        while (!pq.empty())
        {
            PrimsPair *rv = pq.top();
            pq.pop();
            if (visited.find(rv->vtx) != visited.end())
                continue;
            visited.insert(rv->vtx);
            cout << rv->vtx << " ";
            for (auto nbrs : m[rv->vtx])
            {
                if (visited.find(nbrs.first) == visited.end())
                {
                    PrimsPair *np = new PrimsPair(nbrs.first, rv->vtx, nbrs.second);
                    pq.push(np);
                }
            }
        }
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    Prims *p = new Prims(n);
    for (int i = 0; i < e; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        p->AddEdge(x, y, c);
        p->AddEdge(y, x, c);
    }
    p->PrimsAlgo();
    return 0;
}