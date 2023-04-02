// Disjoint Set Union

/*
operations:
1. Union
   > Union by Rank (whos rank less then change the parent )
   > path compression (for optimized)
*/
#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    return 0;
}