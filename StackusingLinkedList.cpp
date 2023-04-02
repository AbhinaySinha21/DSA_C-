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
class StackByLinkedlist
{
    NodeL *top;

public:
    StackByLinkedlist() { top = NULL; }
    void push(int data)
    {
        NodeL *newn = new NodeL(data);
        if (top == NULL)
            top = newn;
        else
        {
            newn->next = top;
            top = newn;
        }
    }
    bool isempty()
    {
        if (top == NULL)
            return true;
        return false;
    }
    int pop()
    {
        if (top == NULL)
            cout << "it is empty";
        else
        {
            NodeL *temp = top;
            top = top->next;
            return temp->data;
        }
        return INT_MIN;
    }
    int peek()
    {
        return top->data;
    }
    void display()
    {
        NodeL *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
};
int main()
{
    StackByLinkedlist s;
    s.push(0);
    s.push(90);
    s.push(89);
    cout << s.peek();
}