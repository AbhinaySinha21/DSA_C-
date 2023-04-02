#include<bits/stdc++.h>
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
class binary_search_tree{
    Node* root;
    void inorder(Node* node){
        if(node==NULL)
            return;
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }
    public:
    binary_search_tree(vector<int> inorder){
        root=CreateBST(inorder,0,inorder.size()-1);
    }
    Node* CreateBST(vector<int> inorder,int st,int ed){
        if(st>ed)
            return NULL;
        int mid=(st+ed)/2;
        Node* node=new Node();
        node->val=inorder[mid];
        node->left=CreateBST(inorder,st,mid-1);
        node->right=CreateBST(inorder,mid+1,ed);
        return node;
    }
    void inorder(){
        inorder(root);
    }
};
int main()
{
    vector<int> v={10,20,30,40,50,60,70,80};
    binary_search_tree *r=new binary_search_tree(v);
    r->inorder();
    return 0;
}