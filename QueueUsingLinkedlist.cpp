#include <iostream>
using namespace std;
class NodeL
{
public:
    int data;
    NodeL *next;
    NodeL(int d)
    {
        data = d;
        next = NULL;
    }
};
class Queuebylinkedlist
{
    NodeL *front;
    NodeL *rear;

public:
    Queuebylinkedlist()
    {
        front = rear = NULL;
    }
    void enqueue(int data)
    {
        NodeL *newn = new NodeL(data);
        if (front == NULL && rear == NULL)
            front = rear = newn;
        else
        {
            rear->next = newn;
            rear = newn;
        }
    }
    int dequeue()
    {
        NodeL *temp = new NodeL(-1);
        if (front == rear && front == NULL)
            cout << "Empty";
        else if (front == rear)
        {
            temp = front;
            front = rear = NULL;
        }
        else
        {
            temp = front;
            front = front->next;
        }
        return temp->data;
    }
    bool isempty()
    {
        if (front == rear && front == NULL)
            return true;
        return false;
    }
    void display()
    {
        NodeL *temp = front;
        while (temp != rear)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
};
int main()
{
    Queuebylinkedlist q;
    q.enqueue(89);
    q.enqueue(90);
    q.enqueue(91);
    q.dequeue();
    q.display();
}