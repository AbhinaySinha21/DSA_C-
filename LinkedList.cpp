#include<iostream>
using namespace std;
class NodeL{
    public:
    int val;
    NodeL* next;
    NodeL(int val){
        val=val;
        next=NULL;
    }
};
class Linked_List{
    public:
    NodeL* head;
    Linked_List(){
        head=NULL;
    }
    void insert(int val){
        NodeL *N=new NodeL(val);
        N->val=val;
        if(head==NULL)
            {head=N;}
        else{
            NodeL *temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=N;
        }
    }
    void traverse(){
        NodeL* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    int deleteL(int val){
        int j;
        if(head==NULL)
            {cout<<"list is empty";}
        else{
            NodeL *temp=head;
            NodeL *ptemp=temp->next;
            while(ptemp->val!=val)
                {
                    temp=ptemp;
                    ptemp=ptemp->next;
                }
            temp->next=ptemp->next;
            ptemp->next=NULL;
              j=ptemp->val;
            }
            return j;
    }
    int countL(){
        
            NodeL* temp=head;
            int c=0;
            while(temp!=NULL){
                 c++;
                 temp=temp->next;
            }
            return c;
        
    }
    
};
int main(){
    Linked_List l;
    l.insert(90);
    l.insert(60);
    l.insert(80);
    l.deleteL(60);
    l.traverse();
    cout<<l.countL();
}