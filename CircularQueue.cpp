#include <iostream>
using namespace std;
#define MAX 10
class CircularQueue
{
    int beg;
    int end;
    int Queue[MAX];
    int len;

public:
    CircularQueue(int n)
    {
        beg = end = -1;
        for (int i = 0; i < n; i++)
            Queue[i] = INT_MIN;
        len = n;
    }
    void enqueue(int data)
    {
        if (beg == ((end + 1) % len))
            cout << "it is full"
                 << "\n";
        else if (beg == -1 && end == -1)
        {
            beg = end = 0;
            Queue[beg] = data;
        }
        else
        {
            end = (end + 1) % len;
            Queue[end] = data;
        }
    }
    void dequeue()
    {
        if (beg == end)
            cout << "Queue is empty";
        else
        {
            cout << "deleted element is " << Queue[beg];
            beg = (beg + 1) % len;
        }
    }
    void display()
    {
        for (int i = beg; i != end; i = (i + 1) % len)
            cout << Queue[i] << "\n";
        cout << Queue[end];
    }
};
int main()
{
    CircularQueue *Q = new CircularQueue(10);
    Q->enqueue(90);
    Q->enqueue(89);
    Q->display();
}
