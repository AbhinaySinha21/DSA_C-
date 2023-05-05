#include <bits/stdc++.h>
using namespace std;
class DIJIPAiR
{
public:
    int vtx;
    string aq_path;
    int cost;
    friend ostream &operator<<(ostream &os, const DIJIPAiR *dt);
    DIJIPAiR(int vtx, string aq_path, int cost)
    {
        this->vtx = vtx;
        this->aq_path = aq_path;
        this->cost = cost;
    }
};
ostream &operator<<(ostream &output, const DIJIPAiR *D)
{
    output << D->vtx << " , " << D->aq_path << " , " << D->cost;
    return output;
}
class compare
{
public:
    bool operator()(DIJIPAiR *a, DIJIPAiR *b)
    {
        return a->cost > b->cost;
    }
};
class Graph
{
    unordered_map<int, unordered_map<int, int>> m;

public:
    Graph(int v)
    {
        for (int i = 1; i <= v; i++)
            m[i] = {};
    }
    void AddEdge(int v1, int v2, int cost)
    {
        m[v1][v2] = cost;
        m[v2][v1] = cost;
    }
    bool containsEdge(int v1, int v2)
    {
        if (m[v1].find(v2) != m[v1].end())
            return true;
        return false;
    }
    bool containsVertix(int v1)
    {
        return (m.find(v1) != m.end());
    }
    int no_of_Edges()
    {
        int s = 0;
        for (auto it : m)
        {
            s += it.second.size();
        }
        return (s / 2);
    }
    void removeEdge(int v1, int v2)
    {
        if (containsEdge(v1, v2))
        {
            m[v1].erase(v2);
            m[v2].erase(v1);
        }
        else
            cout << "Edge not present between " << v1 << " and " << v2 << "\n";
    }
    void removeVertix(int v1)
    {
        for (auto vc : m[v1])
            m[vc.first].erase(v1);
        m.erase(v1);
    }
    void display()
    {
        for (auto vc : m)
        {
            cout << vc.first << " -> [";
            for (auto it : vc.second)
            {
                cout << "( " << it.first << "," << it.second << " ) ";
            }
            cout << "]\n";
        }
    }
    bool hasPath(int src, int dis, set<int> s)
    {
        s.insert(src);
        if (src == dis)
            return true;
        bool f = false;
        for (auto it : m[src])
        {
            if (s.find(it.first) == s.end())
            {
                f = hasPath(it.first, dis, s);
                if (f)
                    return f;
            }
        }
        s.erase(src);
        return false;
    }
    void countPath(int src, int dis, set<int> s, string demo, vector<string> &ans)
    {
        s.insert(src);
        if (src == dis)
        {
            demo += to_string(dis);
            ans.push_back(demo);
            return;
        }
        for (auto it : m[src])
            if (s.find(it.first) == s.end())
                countPath(it.first, dis, s, demo + to_string(src), ans);
        s.erase(src);
    }
    bool BFS(int v, int target)
    {
        queue<int> q;
        set<int> s;
        q.push(v);
        while (!q.empty())
        {
            int rv = q.front();
            q.pop();
            if (s.find(rv) != s.end())
                continue;
            s.insert(rv);
            if (rv == target)
                return true;
            for (auto it : m[rv])
                if (s.find(it.first) == s.end())
                    q.push(it.first);
        }
        return false;
    }
    bool DFS(int v, int target)
    {
        stack<int> st;
        set<int> s;
        st.push(v);
        while (!st.empty())
        {
            int rv = st.top();
            st.pop();
            if (s.find(rv) != s.end())
                continue;
            s.insert(rv);
            if (target == rv)
                return true;
            for (auto it : m[rv])
                if (s.find(it.first) == s.end())
                    st.push(it.first);
        }
        return false;
    }
    void BFT()
    {
        queue<int> q;
        set<int> s;
        for (auto src : m)
        {
            if (s.find(src.first) == s.end())
            {
                q.push(src.first);
                while (!q.empty())
                {
                    int rv = q.front();
                    q.pop();
                    if (s.find(rv) != s.end())
                        continue;
                    s.insert(rv);
                    cout << rv << " ";
                    for (auto it : m[rv])
                        if (s.find(it.first) == s.end())
                            q.push(it.first);
                }
            }
        }
    }
    void DFT()
    {
        stack<int> st;
        set<int> s;
        for (auto src : m)
        {
            if (s.find(src.first) == s.end())
            {
                st.push(src.first);
                while (!st.empty())
                {
                    int rv = st.top();
                    st.pop();
                    if (s.find(rv) != s.end())
                        continue;
                    s.insert(rv);
                    cout << rv << " ";
                    for (auto it : m[rv])
                        if (s.find(it.first) == s.end())
                            st.push(it.first);
                }
            }
        }
    }
    bool isValidTree()
    {
        queue<int> q;
        set<int> s;
        int count = 0;
        for (auto src : m)
        {
            if (s.find(src.first) == s.end())
            {
                count++;
                if (count > 1)
                    return false;
                q.push(src.first);
                while (!q.empty())
                {
                    int rv = q.front();
                    q.pop();
                    if (s.find(rv) != s.end())
                        return false;
                    s.insert(rv);
                    cout << rv << " ";
                    for (auto it : m[rv])
                        if (s.find(it.first) == s.end())
                            q.push(it.first);
                }
            }
        }
        return true;
    }
    bool isBipartite()
    {
        unordered_map<int, int> visited;
        queue<pair<int, int>> q;
        for (int src = 0; src < m.size(); src++)
        {
            if (visited.find(src) != visited.end())
            {
                continue;
            }
            q.push({src, 0});
            while (!q.empty())
            {
                // 1. remove
                auto rv = q.front(); // (1,0)
                q.pop();
                // 2. if Already Visited then Ignore kro
                if (visited.find(rv.first) != visited.end())
                {

                    if (visited[rv.first] != rv.second)
                        return false;
                    else
                        continue;
                }
                // 3. visited
                visited[rv.first] = rv.second;

                // 5. add nbrs
                for (auto nbrs : m[rv.first])
                {
                    if (visited.find(nbrs.first) == visited.end())
                    {
                        q.push({nbrs.first, rv.second + 1});
                    }
                }
            }
        }
        return true;
    }
    void DIJI()
    {
        priority_queue<DIJIPAiR, vector<DIJIPAiR *>, compare> pq;
        set<int> visited;
        pq.push(new DIJIPAiR(1, "1", 0));
        while (!pq.empty())
        {
            DIJIPAiR *rv = pq.top();
            pq.pop();
            if (visited.find(rv->vtx) != visited.end())
                continue;
            visited.insert(rv->vtx);
            cout << rv << "\n";
            for (auto it : m[rv->vtx])
            {
                if (visited.find(it.first) == visited.end())
                {
                    int cost = rv->cost + it.second;
                    pq.push(new DIJIPAiR(it.first, rv->aq_path + to_string(it.first), cost));
                }
            }
        }
    }
};
int main()
{
    Graph *g = new Graph(6);
    g->AddEdge(1, 3, 1);
    g->AddEdge(2, 3, 1);
    g->AddEdge(3, 4, 1);
    g->AddEdge(4, 5, 1);
    g->AddEdge(5, 6, 1);
    g->AddEdge(6, 7, 1);
    // cout<<boolalpha;
    // cout<<g->hasPath(1,6,{});
    // vector<string> a;
    // g->countPath(1,6,{},"",a);
    // cout << boolalpha;
    // cout << g->DFS(1, 6);
    // g->BFT();
    // cout << "\n";
    // g->DFT();
    g->DIJI();
    return 0;
}