#include <iostream>
using namespace std;
#define MAX 1000
int a[MAX];
int top = -1;
void push(int item)
{
    top = top + 1;
    a[top] = item;
}
int pop()
{
    int item = a[top];
    top = top - 1;
    return item;
}
void traverse()
{
    int h = top;
    for (int i = 0; i <= h; i++)
        cout << a[i] << " item is at " << i + 1 << "\n";
}
int peek()
{
    return a[top];
}
bool isfull()
{
    return top == MAX - 1;
}
bool isempty()
{
    return top == -1;
}
int main()
{
    char ch;
    do
    {
        cout << "1.Push element\n2.Pop element\n3.Traverse\n";
        cout << "enter choice";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            if (top != MAX - 1)
            {
                printf("Enter number");
                int item;
                cin >> item;
                push(item);
            }
            else
            {
                cout << "Cannot add\n";
            }
            break;
        case 2:
            if (top != -1)
            {
                pop();
            }
            else
            {
                cout << "Stack is empty\n";
            }
            break;
        case 3:
            traverse();
            break;
        default:
            cout << "wrong choice";
        }

        cout << "want to choose again?(y/Y)";
        cin.ignore();
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
