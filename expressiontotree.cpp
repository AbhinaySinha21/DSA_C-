#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    char val;
    Node *left;
    Node *right;
    Node()
    {
        this->val = ' ';
        this->left = NULL;
        this->right = NULL;
    }
    Node(char val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class binary_tree
{
    Node *root;

public:
    binary_tree(string s)
    {
        root = buildexpressiontree(s);
    }
    Node* buildexpressiontree(string s)
    {
        stack<Node*> st;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                Node* nn=new Node(s[i]);
                nn->right=st.top();
                st.pop();
                nn->left=st.top();
                st.pop();
                st.push(nn);
            }else
            {st.push(new Node(s[i]));}
        }
        return st.top();
    }
};
int main(){

}