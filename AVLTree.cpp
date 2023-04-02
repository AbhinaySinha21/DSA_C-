#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    int balance;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class AVLDemo
{
public:
    Node *root;
    AVLDemo()
    {
        root = NULL;
    }
    Node *rightrotation(Node *A)
    {
        Node *B = A->left;
        Node *Bright = B->right;
        B->right = A;
        A->left = Bright;
        updateheightandbalance(A);
        updateheightandbalance(B);
        return B;
    }
    Node *leftrotation(Node *A)
    {
        Node *B = A->right;
        Node *Bleft = B->left;
        B->left = A;
        A->right = Bleft;
        updateheightandbalance(A);
        updateheightandbalance(B);
        return B;
    }
    Node *getrotation(Node *node)
    {
        updateheightandbalance(node);
        if (node->balance == 2)
        {
            if (node->left->balance == 1)
            {
                return rightrotation(node);
            }
            else
            {
                node->left = leftrotation(node->left);
                return rightrotation(node);
            }
        }
        else if (node->balance == -2)
        {
            if (node->right->balance == -1)
            {
                return leftrotation(node);
            }
            else
            {
                node->right = rightrotation(node->right);
                return leftrotation(node);
            }
        }
        return node;
    }
    void updateheightandbalance(Node *troot)
    {
        int lh = -1;
        int rh = -1;
        if (troot->left != NULL)
            lh = troot->left->height;
        if (troot->right != NULL)
            rh = troot->right->height;
        troot->balance *= lh - rh;
        troot->height = max(lh, rh) + 1;
    }
    void display(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        string str = "";
        str += node->left != NULL ? node->left->data + " " : "->";
        str += "< -" + node->data;
        str += node->right != NULL ? node->right->data + " " : "->";
        cout << str << "\n";
        display(node->left);
        display(node->right);
    }
    Node *insertinAvl(Node *root, Node *newnode)
    {
        if (root == NULL)
        {
            root = newnode;
            return root;
        }
        else if (newnode->data < root->data)
        {
            if (root->left == NULL)
            {
                root->left = newnode;
            }
            else
            {
                root->left = insertinAvl(root->left, newnode);
            }
        }
        else if (newnode->data > root->data)
        {
            if (root->right == NULL)
            {
                root->right = newnode;
            }
            else
            {
                root->right = insertinAvl(root->right, newnode);
            }
        }
        root = getrotation(root);
        return root;
    }
};
int main()
{
    Node *n1 = new Node(30);

    Node *n2 = new Node(20);

    Node *n3 = new Node(10);
    AVLDemo *t = new AVLDemo();
    t->root = t->insertinAvl(n1, n2);
    t->root = t->insertinAvl(t->root, new Node(25));
    t->root = t->insertinAvl(t->root, n3);
    t->root = t->insertinAvl(t->root, new Node(11));
    t->root = t->insertinAvl(t->root, new Node(5));
    cout << "display data";
    t->display(t->root);
}
