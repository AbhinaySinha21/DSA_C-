#include <iostream>
using namespace std;
class NodeP
{
public:
    int data;
    int priority;
    NodeP *next;
    NodeP(int d, int p)
    {
        data = d;
        priority = p;
        next = NULL;
    }
};
class PriorityQueue
{
public:
    NodeP *front;
    NodeP *rear;
    PriorityQueue()
    {
        front = rear = NULL;
    }
    void enqueue(int data, int priority)
    {
        NodeP *newn = new NodeP(data, priority);
        if (front == NULL || newn->priority < front->priority)
        {
            newn->next = front;
            front = newn;
            rear = newn;
        }
        else
        {
            NodeP *temp = front;
            while (temp->next != NULL && newn->priority >= temp->next->priority)
                temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
        }
    }
    void dequeue()
    {
        NodeP *temp = front;
        cout << "deleted element is " << temp->data << "\n";
        front = front->next;
        temp->next = NULL;
    }
    void display()
    {
        NodeP *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " " << temp->priority << "\n";
            temp = temp->next;
        }
    }
};
int main()
{
    PriorityQueue p;
    p.enqueue(90, 2);
    p.enqueue(70, 1);
    p.enqueue(50, 3);
    p.dequeue();
    p.display();
}