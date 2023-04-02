#include <iostream>
#include <vector>
using namespace std;

class NodeBT
{
public:
    int data;
    NodeBT *left;
    NodeBT *right;
    NodeBT(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST2
{
    NodeBT *root;

public:
    BST2()
    {
        root = NULL;
    }
    NodeBT *getter()
    {
        return root;
    }
    void setter(NodeBT *t)
    {
        root = t;
    }
    vector<int> preorder(NodeBT *root)
    {
        if (root == NULL)
        {
            vector<int> v;
            return v;
        }
        vector<int> a1, a2;
        a1.push_back(root->data);
        for (int i : preorder(root->left))
            a1.push_back(i);
        a2 = preorder(root->right);
        for (int i : a2)
            a1.push_back(i);
        return a1;
    }

    void preorder1(NodeBT *root)
    {
        if (root == NULL)
            return;
        cout << root->data << "\n";
        preorder1(root->left);
        preorder1(root->right);
    }

    void insert(int data)
    {
        NodeBT *newn = new NodeBT(data);
        if (root == NULL)
        {
            root = newn;
            return;
        }
        NodeBT *temp = root;
        while (true)
        {
            if (root->data >= data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newn;
                    return;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newn;
                    return;
                }
                else
                    temp = temp->right;
            }
        }
    }

    NodeBT *insertR(int data, NodeBT *temp)
    {
        if (temp == NULL)
        {
            return new NodeBT(data);
        }
        if (temp->data >= data)
            temp->left = insertR(data, temp->left);
        else
            temp->right = insertR(data, temp->right);
        return temp;
    }

    NodeBT *deleteNode(NodeBT *root, int data)
    {
        if (root == NULL)
            return NULL;
        if (data < root->data)
        {
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = deleteNode(root->right, data);
        }
        else
        {
            if (root->right == NULL && root->left == NULL)
            {
                root = NULL;
                return root;
            }
            else if (root->left == NULL)
            {
                root = root->right;
                return root;
            }
            else if (root->right == NULL)
            {
                root = root->left;
                return root;
            }
            else
            {
                // int min = MinimumE(root->right);
                // root->data = min;
                // root->right = deleteNode(root->right, min);
            }
        }
        return root;
    }
};
int main()
{
    BST2 *t = new BST2();
    t->setter(t->insertR(89, t->getter()));
    t->setter(t->insertR(90, t->getter()));
    t->setter(t->insertR(9, t->getter()));
    t->setter(t->insertR(0, t->getter()));
    t->preorder1(t->getter());
}