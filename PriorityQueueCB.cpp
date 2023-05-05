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
    void downheapify(int pi, int n)
    {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int mini = pi;
        if (lci < n && v[mini] < v[lci])
            mini = lci;
        if (rci < n && v[mini] < v[rci])
            mini = rci;
        if (mini != pi)
        {
            int temp = v[mini];
            v[mini] = v[pi];
            v[pi] = temp;
            downheapify(mini, n);
        }
    }

public:
    int min()
    {
        return v[0];
    }
    void Swap(int i, int j)
    {
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
        downheapify(0, v.size());
        return rem;
    }
    void display()
    {
        for (int i : v)
            cout << i << " ";
    }
    void heapsort()
    {
        for (int i = v.size() / 2 - 1; i >= 0; i--)
            downheapify(v.size(), i);
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int temp = v[i];
            v[i] = v[0];
            v[0] = temp;
            downheapify(0, i);
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
/*
#include<bits/stdc++.h>
using namespace std;
class HeapSort {
void sort(vector <int> arr)
{
int N = arr.size();

for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);

for (int i = N - 1; i > 0; i--) {

int temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;

heapify(arr, i, 0);
}
}

void heapify(vector<int> arr, int N, int i)
{
int largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;

if (l < N && arr[l] > arr[largest])
    largest = l;

if (r < N && arr[r] > arr[largest])
    largest = r;

if (largest != i) {
    int swap = arr[i];
    arr[i] = arr[largest];
    arr[largest] = swap;
    heapify(arr, N, largest);
}
}

void display(vector<int> arr)
{
int N = arr.size();

for (int i = 0; i < N; ++i)
    cout<<arr[i]<<" ";
cout<<"\n";
}

int main()
{
vector<int> arr = { 12, 11, 13, 5, 6, 7 };
int N = arr.size();

HeapSort *ob = new HeapSort();
ob->sort(arr);

cout<<"Sorted array is";
display(arr);
}
}
*/