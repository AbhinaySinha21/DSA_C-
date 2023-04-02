#include <bits/stdc++.h>
using namespace std;
// class compare
// {
// public:
//     bool operator()(PrimsPair *a, PrimsPair *b)
//     {
//         return a->cost > b->cost;
//     }
// };
// class PrimsPair
// {
// public:
//     int vtx;
//     int acqvtx;
//     int cost;

//     PrimsPair(int vtx, int acqvtx, int cost)
//     {
//         this->vtx = vtx;
//         this->acqvtx = acqvtx;
//         this->cost = cost;
//     }
// };
// class Graph
// {
//     unordered_map<int, vector<int>> m;

// public:
//     Graph(int v)
//     {
//         for (int i = 1; i <= v; i++)
//             m[i] = {};
//     }
//     void AddEdge(int v1, int v2)
//     {
//         m[v1].push_back(v2);
//         m[v2].push_back(v1);
//     }
//     int PrimsAlgo()
//     {
//         priority_queue<PrimsPair *, vector<PrimsPair *>, compare> pq;
//         pq.push(new PrimsPair(1, 1, 0));
//         set<int> visited;
//         int sum = 0;
//         while (!pq.empty())
//         {
//             PrimsPair *rv = pq.top();
//             pq.pop();
//             if (visited.find(rv->vtx) != visited.end())
//                 continue;
//             visited.insert(rv->vtx);
//             sum += rv->cost;
//             for (auto nbrs : m[rv->vtx])
//             {
//                 if (visited.find(nbrs) == visited.end())
//                 {
//                     int cost = 0;
//                     if (find(m[rv->vtx].begin(), m[rv->vtx].end(), nbrs) != m[rv->vtx].end())
//                         cost = 1;
//                     PrimsPair *np = new PrimsPair(nbrs, rv->vtx, cost);
//                     pq.push(np);
//                 }
//             }
//         }
//     }
// };

vector<set<int>> arr;
unordered_set<int> s;
void setup(int v)
{
    for (int i = 0; i < v; i++)
        arr.push_back({});
}
void AddEdge(int v1, int v2)
{
    arr[v1].insert(v2);
    arr[v2].insert(v1);
}
void DFS(int x)
{
    vector<int> v;
    for (int i : s)
    {
        if (arr[x].find(i) == arr[x].end())
            v.push_back(i);
    }
    for (int i : v)
        s.erase(i);
    for (int i : v)
        DFS(i);
}
int main()
{
    int n, e;
    cin >> n >> e;
    setup(n);
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        AddEdge(v1 - 1, v2 - 1);
    }
    for (int i = 0; i < n; i++)
        s.insert(i);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(i) != s.end())
        {
            s.erase(i);
            count++;
            DFS(i);
        }
    }
    cout << count - 1;
}