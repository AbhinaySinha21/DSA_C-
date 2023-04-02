#include <bits/stdc++.h>
using namespace std;
class Graph
{
    unordered_map<int, unordered_map<int, int>> m;

public:
    Graph(int v)
    {
        for (int i = 1; i <= v; i++)
        {
            unordered_map<int, int> map;
            m[i] = map;
        }
    }
    void AddEdge(int v1, int v2, int cost)
    {
        m[v1][v2] = cost;
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
    vector<int> indegree()
    {
        vector<int> ind(m.size() + 1, 0);
        for (auto it : m)
        {
            for (auto nbrs : it.second)
            {
                ind[nbrs.first]++;
            }
        }
        return ind;
    }
    void TopologicalSort()
    {
        vector<int> ind = indegree();
        // for (int it = 1; it < ind.size(); it++)
        //     cout << ind[it] << " ";
        // cout << "\n";
        queue<int> q;
        for (int i = 1; i < ind.size(); i++)
            if (ind[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int rv = q.front();
            q.pop();
            cout << rv << " ";
            for (auto it : m[rv])
            {
                ind[it.first]--;
                if (ind[it.first] == 0)
                {
                    q.push(it.first);
                }
            }
        }
    }
    bool cycleindag()
    {
        vector<int> ind = indegree();
        queue<int> q;
        for (int i = 1; i < ind.size(); i++)
            if (ind[i] == 0)
                q.push(i);
        int count = 0;
        while (!q.empty())
        {
            int rv = q.front();
            q.pop();
            count++;
            for (auto it : m[rv])
            {
                ind[it.first]--;
                if (ind[it.first] == 0)
                {
                    q.push(it.first);
                }
            }
        }
        return !(count == m.size());
    }
};
int main()
{
    Graph *g = new Graph(8);
    g->AddEdge(1, 2, 0);
    g->AddEdge(2, 4, 0);
    g->AddEdge(3, 1, 0);
    g->AddEdge(2, 3, 0);
    g->AddEdge(4, 5, 0);
    g->AddEdge(4, 6, 0);
    g->AddEdge(5, 6, 0);
    g->AddEdge(7, 8, 0);
    cout << boolalpha;
    cout << g->cycleindag();
    return 0;
}