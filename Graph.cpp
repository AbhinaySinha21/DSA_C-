#include <map>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Graph
{
public:
    map<int, vector<int>> h;
    Graph()
    {
        h = {};
    }
    void insert(int v, int add, bool edge)
    {
        vector<int> l;
        h[v] = l;
        l.push_back(add);
        h[v] = l;
        if (edge == true)
        {
            vector<int> l1;
            h[add] = l1;
            li.push_back(v);
            h[add] = l1;
        }
    }
    void BFS_traversal(int source)
    {
        Queuebylinkedlist q = new Queuebylinkedlist();
        q.enqueue(source);
        HashSet<Integer> s = new HashSet();
        s.add(source);
        while (!q.isempty())
        {
            int front = q.dequeue();
            System.out.println(front);
            vector<int> l = h.getOrDefault(front, new vector<int>());
            NodeS temp = l.head;
            while (temp != null)
            {
                if (!s.contains(temp.data))
                {
                    q.enqueue(temp.data);
                    s.add(temp.data);
                }
                temp = temp.next;
            }
        }
    }
    void DFS_traversal(int source, bool[] visited)
    {
        // System.out.println(source);
        visited[source] = true;
        Stack<Integer> s = new Stack<>();
        s.push(source);
        /* vector<int> s=h.get(source);
         NodeS temp=s.head;
         while(temp!=null){
             if(!visited[temp.data])
                 DFS_traversal(temp.data,visited);
             temp=temp.next;
         }*/
        while (!s.isEmpty())
        {
            int top = s.pop();
            System.out.println(top);
            NodeS temp = h.get(top).head;
            while (temp != null)
            {
                if (!visited[temp.data])
                {
                    s.push(temp.data);
                    visited[temp.data] = true;
                }
                temp = temp.next;
            }
        }
    }
    Map<Integer, Integer> SSSP(int source)
    {
        Queuebylinkedlist q = new Queuebylinkedlist();
        q.enqueue(source);
        Map<Integer, Integer> m = new HashMap<>();
        for (int res : h.keySet())
            m.put(res, Integer.MAX_VALUE);
        m.put(source, 0);
        while (!q.isempty())
        {
            int front = q.dequeue();
            vector<int> l = h.get(front);
            NodeS temp = l.head;
            while (temp != null)
            {
                if (m.get(temp.data) == Integer.MAX_VALUE)
                { // s.add(temp.data);
                    m.put(temp.data, m.get(front) + 1);
                    q.enqueue(temp.data);
                }
                temp = temp.next;
            }
        }
        return m;
    }

    static void main(String[] args)
    {
        Graph g = new Graph();
        g.insert(0, 1, true);
        g.insert(0, 2, true);
        g.insert(1, 4, true);
        g.insert(2, 3, true);
        g.insert(3, 4, true);
        g.insert(2, 4, true);
        // g.BFS_traversal(2);
        bool[] arr = {false, false, false, false, false, false, false, false, false};
        g.DFS_traversal(2, arr);

        for (Map.Entry<Integer, Integer> h : g.SSSP(1).entrySet())
        {
            // System.out.println(h.getKey()+" "+h.getValue());
        }
    }
}