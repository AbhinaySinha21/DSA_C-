#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class kruskelpair
{
public:
    int vtx;
    int acqvtx;
    int cost;
    kruskelpair(int vtx, int acqvtx, int cost)
    {
        this->vtx = vtx;
        this->acqvtx = acqvtx;
        this->cost = cost;
    }
};
class DSU
{
    class Node
    {
    public:
        int vtx;
        Node *parent;
        int rank;

        Node()
        {
            this->vtx = 0;
            this->parent = NULL;
            this->rank = 0;
        }
        Node(int vtx, Node *parent, int rank)
        {
            this->vtx = vtx;
            this->parent = parent;
            this->rank = rank;
        }
    };
    map<int, Node *> m;
    Node *find(Node *nn)
    {
        if (nn->parent == nn)
            return nn;
        Node *node = find(nn->parent);
        nn->parent = node; // path compression
        return node;
    }

public:
    void CreateSet(int v)
    {
        Node *node = new Node();
        node->vtx = v;
        node->parent = node;
        node->rank = 0;
        m[v] = node;
    }
    int find(int v)
    {
        Node *nn = m[v];
        return find(nn)->vtx;
    }
    void unionDSU(int v1, int v2)
    {
        Node *re1 = find(m[v1]);
        Node *re2 = find(m[v2]);
        if (re1->rank == re2->rank)
        {
            re1->parent = re2;
            re2->rank++;
        }
        else if (re1->rank < re2->rank)
        {
            re1->parent = re2;
        }
        else
        {
            re2->parent = re1;
        }
    }
};
class Kruskel
{
    unordered_map<int, unordered_map<int, int>> m;

public:
    Kruskel(int n)
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
    void kruskelAlgo()
    {
        vector<kruskelpair *> result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}