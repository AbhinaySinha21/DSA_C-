#include <iostream>
using namespace std;

class BinaryTreeusingArray
{
public:
    int arr[10000];
    int lastusedindex;
    int len;
    BinaryTreeusingArray(int n)
    {
        len = n + 1;
        arr[len] = {0};
        lastusedindex = 0;
    }
    void insert(int val)
    {
        if (len == lastusedindex)
            cout << "array is full"
                 << "\n";
        else
        {
            arr[lastusedindex + 1] = val;
            lastusedindex++;
        }
    }
    void traverse(int index)
    {
        if (index > lastusedindex)
            return;
        cout << arr[index] << "\n";
        traverse(2 * index);
        traverse(2 * index + 1);
    }
};
int main()
{
    BinaryTreeusingArray *a = new BinaryTreeusingArray(4);
    a->insert(91);
    a->insert(89);
    a->insert(90);
    a->traverse(1);
}