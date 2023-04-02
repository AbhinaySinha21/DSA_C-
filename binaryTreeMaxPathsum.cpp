#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
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
int maxL=INT_MIN;
class binary_tree{
    Node* root;
    pair<int,int> maxPathsum(Node* node){
        if(node==NULL)
            return {0,0};
        pair<int,int> left=maxPathsum(node->left);
        pair<int,int> right=maxPathsum(node->right);
        pair<int,int> sdp;
        int i;
        if(node->val<0)
        {
            i=0;
            sdp.second=max(max(left.second,left.first),max(right.second,right.first));
            sdp.first=0;
        }else{
            i=1;
            sdp.first+=left.first+right.first+node->val;
            sdp.second=max(left.second,max(right.second,left.first+right.first+node->val));
        }
        cout<<node->val<<" "<<sdp.first<<" "<<sdp.second<<" "<<i<<"\n";
        return sdp;
    }
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
    public:
    binary_tree(){
        root=Createfrompreorder();
    }
    Node* Createfrompreorder(){
        string it;
        cin>>it;
        Node* nn=new Node();
        if(it=="NULL")
            return NULL;
        else{
            nn->val=stoi(it);
            nn->left=Createfrompreorder();
            nn->right=Createfrompreorder();
        }
        return nn;
    }
    void display(){
        display(root);
    }
    int maxPathsum(){
        return maxPathsum(root).second;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    binary_tree *r=new binary_tree();
    cout<<r->maxPathsum();
    // r->display();
    return 0;

}