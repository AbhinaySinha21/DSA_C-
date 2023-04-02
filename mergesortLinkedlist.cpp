#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "NULL";
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *reverse(Node *head)
{
    Node *p, *curr, *prev;
    prev = NULL;
    curr = head;
    for (; curr != NULL;)
    {
        p = curr->next;
        curr->next = prev;
        prev = curr;
        curr = p;
    }
    return prev;
}
Node *combine(Node *left, Node *right)
{
    Node *dum = NULL, *temp;
    while (left != NULL && right != NULL)
    {
        if (left->data >= right->data)
        {
            if (dum == NULL)
            {
                dum = right;
                temp = dum;
            }
            else
            {
                dum->next = right;
                dum = dum->next;
            }
            right = right->next;
        }
        else if (left->data < right->data)
        {
            if (dum == NULL)
            {
                dum = left;
                temp = dum;
            }
            else
            {
                dum->next = left;
                dum = dum->next;
            }
            left = left->next;
        }
    }
    if (left != NULL)
        dum->next = left;
    if (right != NULL)
        dum->next = right;
    return temp;
}
Node *mergesort(Node *head)
{
    if (head->next == NULL)
        return head;
    Node *slow, *fast, *low;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        low = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow;
    low->next = NULL;
    Node *left = mergesort(head);
    Node *right = mergesort(temp);
    return combine(left, right);
}
Node *insert(Node *head, int n)
{
    Node *temp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *dem = new Node(x);
        if (head == NULL)
        {
            head = dem;
            temp = head;
        }
        else
        {
            temp->next = dem;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Node *head1 = insert(NULL, n);
    Node *head2 = insert(NULL, m);
    Node *head3 = insert(NULL, k);
    int sum;
    cin >> sum;
    head2 = mergesort(head2);
    head3 = mergesort(head3);
    head3 = reverse(head3);
    display(head3);
    return 0;
}