#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node()
    {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Binary_Tree
{
    Node *root;
    void display(Node *node)
    {
        if (node == NULL)
            return;
        string s = "";
        s = "<-" + to_string(node->val) + "->";
        if (node->left == NULL && node->right == NULL)
            s = "." + s + ".";
        else if (node->left == NULL)
            s = "." + s + to_string(node->right->val);
        else if (node->right == NULL)
            s = to_string(node->left->val) + s + ".";
        else
        {
            s = to_string(node->left->val) + s + to_string(node->right->val);
        }
        cout << s << "\n";
        display(node->left);
        display(node->right);
    }
    void preorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node == NULL)
            return;
        preorder(node->left);
        preorder(node->right);
        cout << node->val << " ";
    }
    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        preorder(node->left);
        cout << node->val << " ";
        preorder(node->right);
    }
    bool search(Node *node, int it)
    {
        if (node == NULL)
            return false;
        if (node->val == it)
            return true;
        bool left = search(node->left, it);
        bool right = search(node->right, it);
        return left || right;
    }
    int maxElement(Node *node)
    {
        if (node == NULL)
            return INT_MIN;
        int leftmax = maxElement(node->left);
        int rightmax = maxElement(node->right);
        int maxI = max(leftmax, rightmax, node->val);
        return maxI;
    }
    int heightofTree(Node *node)
    {
        if (node == NULL)
            return -1; // for single node have height 0
                       // return 0;     for single node have height 1
        int lefthei = heightofTree(node->left) + 1;
        int righthei = heightofTree(node->right) + 1;
        return max(lefthei, righthei) + 1;
    }
    bool issymmetric(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;
        bool left = issymmetric(root1->left, root2->right);
        bool right = issymmetric(root1->right, root2->left);
        return left && right;
    }
    vector<vector<int>> lvlOrderTraversal(Node *node)
    {
        queue<Node *> q, q1;
        q.push(root);
        vector<vector<int>> v;
        vector<int> demo;
        while (!q.empty())
        {
            demo.push_back(q.front()->val);
            if (q.front()->left != NULL)
                q1.push(q.front()->left);
            if (q.front()->right != NULL)
                q1.push(q.front()->right);
            q.pop();
            if (q.empty())
            {
                v.push_back(demo);
                demo = {};
                q = q1;
                q1 = {};
            }
        }
        return v;
    }
    Node *LCA(Node *root, Node *p, Node *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        Node *left = LCA(root->left, p, q);
        Node *right = LCA(root->right, p, q);
        if (left != NULL && right != NULL)
            return root;
        else if (left == NULL)
            return right;
        else
            return left;
    }
    int diameterofBT(Node *root)
    {
        int ld = diameterofBT(root->left);
        int rd = diameterofBT(root->right);
        int sd = heightofTree(root->left) + heightofTree(root->right) + 2;
        return max(ld, max(rd, sd));
    }
    pair<int, int> DOB(Node *node)
    {
        if (node == NULL)
            return {-1, 0};
        pair<int, int> ld = DOB(node->left);
        pair<int, int> rd = DOB(node->right);
        int sd = ld.first + rd.first + 2;
        pair<int, int> sdp = {max(ld.first, rd.first) + 1, max(ld.second, max(rd.second, sd))};
        return sdp;
    }

public:
    Binary_Tree()
    {
        root = CreateTreePreorerNullseq();
    }
    void DisplayPub()
    {
        display(root);
    }
    void preOrder()
    {
        preorder(root);
    }
    void postOrder()
    {
        postorder(root);
    }
    void inOrder()
    {
        inorder(root);
    }
    int maxElement()
    {
        return maxElement(root);
    }
    int height()
    {
        return heightofTree(root);
    }
    bool isSymmetric()
    {
        return issymmetric(root, root);
    }
    void lvlorderTraversal()
    {
        lvlOrderTraversal(root);
    }
    void lca(Node *p, Node *q)
    {
        LCA(root, p, q);
    }
    Node *Create_tree()
    {
        int item;
        cin >> item;
        Node *nn = new Node();
        nn->val = item;
        bool hlc;
        cin >> boolalpha;
        cin >> hlc;
        if (hlc)
            nn->left = Create_tree();
        bool hrc;
        cin >> boolalpha;
        cin >> hrc;
        if (hrc)
            nn->right = Create_tree();
        return nn;
    }
    bool Search(int item)
    {
        return search(root, item);
    }
    Node *CreateTreelvlorder()
    {
        queue<Node *> q;
        Node *nn = new Node();
        int val;
        cin >> val;
        nn->val = val;
        root = nn;
        q.push(nn);
        while (!q.empty())
        {
            int v1, v2;
            cin >> v1 >> v2;
            Node *rv = q.front();
            q.pop();
            if (v1 != -1)
            {
                Node *dem = new Node(v1);
                rv->left = dem;
                q.push(dem);
            }
            if (v2 != -1)
            {
                Node *dem = new Node(v2);
                rv->right = dem;
                q.push(dem);
            }
        }
        return root;
    }
    Node *CreateTreePreorerNullseq()
    {
        string s;
        cin >> s;
        Node *nn = new Node();
        if (s != "NULL")
        {
            nn->val = stoi(s);
            nn->left = CreateTreePreorerNullseq();
            nn->right = CreateTreePreorerNullseq();
        }
        else
        {
            return NULL;
        }
        return nn;
    }
    int diameterofBT()
    {
        return diameterofBT(root);
    }
    int dob()
    {
        return DOB(root).second;
    }
};
int main()
{
    Binary_Tree *r = new Binary_Tree();
    r->DisplayPub();
}