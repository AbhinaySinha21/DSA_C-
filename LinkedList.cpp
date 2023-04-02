#include <bits/stdc++.h>
using namespace std;
class NodeL
{
public:
    int val;
    NodeL *next;
    NodeL(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class Linked_List
{
public:
    NodeL *head;
    Linked_List()
    {
        head = NULL;
    }
    void insert(int val)
    {
        NodeL *N = new NodeL(val);
        N->val = val;
        if (head == NULL)
        {
            head = N;
        }
        else
        {
            NodeL *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = N;
        }
    }
    void traverse()
    {
        NodeL *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    int deleteL(int val)
    {
        int j;
        if (head == NULL)
        {
            cout << "list is empty";
        }
        else
        {
            NodeL *temp = head;
            NodeL *ptemp = temp->next;
            while (ptemp->val != val)
            {
                temp = ptemp;
                ptemp = ptemp->next;
            }
            temp->next = ptemp->next;
            ptemp->next = NULL;
            j = ptemp->val;
        }
        return j;
    }
    int countL()
    {

        NodeL *temp = head;
        int c = 0;
        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
};
class Linked_list2
{
    NodeL *head;
    NodeL *tail;
    int size;

public:
    Linked_list2()
    {
        head = tail = NULL;
        size = 0;
    }
    void addFirst(int it)
    {
        NodeL *nnn = new NodeL(it);
        if (size == 0)
        {
            head = tail = nnn;
        }
        else
        {
            nnn->next = head;
            head = nnn;
        }
        size++;
    }
    void addLast(int it)
    {
        NodeL *nnn = new NodeL(it);
        if (size == 0)
        {
            head = tail = nnn;
        }
        else
        {
            tail->next = nnn;
            tail = nnn;
        }
        size++;
    }
    void addatind(int it, int k)
    {
        NodeL *nnn = new NodeL(it);
        if (k < 0 || k >= size)
        {
            cout << "galat index";
        }
        else if (k == 0)
        {
            addFirst(it);
        }
        else if (k == size)
        {
            addLast(it);
        }
        else
        {
            NodeL *temp = getNode(k);
            nnn->next = temp->next;
            temp->next = nnn;
            size++;
        }
    }
    NodeL *getNode(int k)
    {
        NodeL *temp = head;
        if (k < 0 || k >= size)
        {
            cout << "nahi chalega\n";
            temp = NULL;
        }
        else
        {
            for (int i = 1; i <= k; i++)
            {
                temp = temp->next;
            }
        }
        return temp;
    }
    int getFirst()
    {
        return head->val;
    }
    int getLast()
    {
        return tail->val;
    }
    int deleteF()
    {
        NodeL *temp = head;
        int k = temp->val;
        if (size == 1)
        {
            head = tail = NULL;
            size--;
        }
        else
        {
            head = head->next;
            temp->next = NULL;
            size--;
        }
        return k;
    }
    int deleteL()
    {
        NodeL *temp;
        int k = head->val;
        if (size == 1)
        {
            head = tail = NULL;
            size--;
        }
        else
        {
            temp = getNode(size - 2);
            k = tail->val;
            tail = temp;
            tail->next = NULL;
            size--;
        }
        return k;
    }
    int deleteati(int k)
    {
        NodeL *temp2;
        if (k < 0 || k >= size)
        {
            return -1;
        }
        else if (k == 0)
            return deleteF();
        else if (k == size - 1)
            return deleteL();
        else
        {
            NodeL *temp = getNode(k);
            temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next = NULL;
            size--;
        }
        return temp2->val;
    }
    void traverse()
    {
        NodeL *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
    }
    // floyd cycle detection and findking meeting point
    NodeL *Meetingpoint(NodeL *head)
    {
        NodeL *slow, *fast;
        slow = fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return slow;
        }
        return NULL;
    }
    void cycleRemove()
    {
        NodeL *meet = Meetingpoint(head);
        if (meet == NULL)
            return;
        NodeL *temp = meet;
        int c = 1;
        while (temp->next != meet)
        {
            c++;
            temp = temp->next;
        }
        NodeL *fast = head;
        for (int i = 1; i <= c; i++)
        {
            fast = fast->next;
        }
        NodeL *slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    void floydcycleRemoval()
    {
        NodeL *slow, *fast;
        slow = fast = head;
        bool f = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                f = true;
                break;
            }
        }
        if (!f)
            return;
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    void reversegroup(int k)
    {
        stack<int> st;
        NodeL *temp, *temp1, *temp2, *dem;
        temp = temp1 = head;
        while (head != NULL)
        {
            if (st.size() == 0)
                temp2 = head;
            st.push(head->val);
            if (st.size() == k)
            {
                while (!st.empty())
                {
                    dem = new NodeL(st.top());
                    st.pop();
                    temp1->next = dem;
                    temp1 = temp1->next;
                }
            }
            head = head->next;
        }
        if (st.size() > 0)
            dem->next = temp2;
    }
};
int main()
{
    Linked_list2 *l = new Linked_list2();
    l->addFirst(90);
    l->addFirst(60);
    l->addFirst(80);
    l->addFirst(60);
    l->traverse();
}