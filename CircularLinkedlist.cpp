#include <iostream>
using namespace std;
class NodeS
{
public:
    int data;
    NodeS *next;
    NodeS(int d)
    {
        data = d;
        next = NULL;
    }
};
class CircularLinkedList
{
    NodeS *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
    void add(int data)
    {
        NodeS *newn = new NodeS(data);
        if (head == NULL)
        {
            head = newn;
            head->next = head;
        }
        else
        {
            NodeS *temp = head->next;
            while (temp->next != head)
                temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
        }
    }
    void addIth(int p, int data)
    {
        if (head == NULL)
            add(data);
        else
        {
            NodeS *newn = new NodeS(data);
            NodeS *temp = head;
            int i = 1;
            while (i < p - 1)
            {
                temp = temp->next;
                i++;
            }
            newn->next = temp->next;
            temp->next = newn;
        }
    }
    void addfirst(int data)
    {
        NodeS *newn = new NodeS(data);
        if (head == NULL)
        {
            head = newn;
            newn->next = head;
        }
        else
        {
            NodeS *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
            head = newn;
        }
    }
    int no_of_nodes()
    {
        int n = 1;
        NodeS *temp = head->next;
        while (temp != head)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }

    void deleteL(int p)
    {
        if (head == NULL)
            cout << "it is empty"
                 << "\n";
        else if (p <= 0 || p >= no_of_nodes())
        {
            NodeS *temp = head;
            NodeS *ptemp = temp->next;
            while (ptemp->next != head)
            {
                temp = ptemp;
                ptemp = ptemp->next;
            }
            cout << "Deleted node " << ptemp->data;
            temp->next = head;
        }
        else
        {
            NodeS *temp = head;
            int i = 0;
            while (i < p - 2)
            {
                temp = temp->next;
                i++;
            }
            NodeS *p1 = temp->next;
            temp->next = p1->next;
        }
    }

    void deletefirst()
    {
        if (head == NULL)
            cout << "empty"
                 << "\n";
        else
        {
            NodeS *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
        }
    }

    void display()
    {
        NodeS *temp = head->next;
        cout << head->data << "\n";
        while (temp != head)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
};
int main()
{
    CircularLinkedList c;
    c.add(90);
    c.add(80);
    c.add(70);
    c.deleteL(1);
    c.display();
}