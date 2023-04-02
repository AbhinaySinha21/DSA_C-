#include <bits/stdc++.h>
using namespace std;
class Heap
{
    vector<int> v;
    void upheapify(int ci)
    {
        int pi = (ci - 1) / 2;
        if (v[pi] > v[ci])
        {
            Swap(pi, ci);
            upheapify(pi);
        }
    }
    void downheapify(int pi,int n)
    {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int mini = pi;
        if (lci < n && v[mini] > v[lci])
            mini = lci;
        if (rci < n && v[mini] > v[rci])
            mini = rci;
        if (mini != pi)
        {
            Swap(mini, pi);
            downheapify(mini,n);
        }
    }

public:
    int min()
    {
        return v[0];
    }
    int size()
    {
        return v.size();
    }
    void Swap(int i, int j)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    void add(int item)
    {
        v.push_back(item);
        upheapify(v.size() - 1);
    }
    int remove()
    {
        Swap(0, v.size() - 1);
        int rem = v[v.size() - 1];
        v.pop_back();
        downheapify(0,v.size());
        return rem;
    }
    void display()
    {
        for (int i : v)
            cout << i << " ";
    }
    void heapsort(){
        for (int i = size() - 1; i > 0; i--) {
        Swap(0, i);
        downheapify(0,i);
    }
}
};
int main()
{
    Heap hp;
    hp.add(3);
    hp.add(0);
    hp.add(10);
    hp.add(20);
    hp.add(80);
    hp.add(16);
    hp.add(90);
    hp.add(95);
    hp.heapsort();
    hp.display();
    return 0;
}