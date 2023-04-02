#include<iostream>
using namespace std;
class NodeD{
    public:
    int data;
    NodeD *next;
    NodeD *previous;
    NodeD(int d){
       data=d;
       next=NULL;
       previous=NULL;
    }
};

class DoublyLinkedlist{
    public:
    NodeD* head;
    NodeD* tail;
    DoublyLinkedlist(){
        head=tail=NULL;
    }
 void add(int data){
        NodeD *newnode=new NodeD(data);
        if(head==NULL || tail==NULL)
            head=tail=newnode;
        else{
            newnode->previous=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }
 void addfirst(int data){
        NodeD* newnode=new NodeD(data);
        if(head==NULL)
            head=newnode;
        else{
            head->previous=newnode;
            newnode->next=head;
            head=newnode;
        }
    }
 void addIth(int p,int data){
        if(p<0)
            addfirst(data);
        else{
            NodeD *newnode=new NodeD(data);
            int i=1;
            NodeD* temp=head;
            while(i<p-1){
                temp=temp->next;
                i++;
            }
            NodeD* ptemp=temp->next;
            ptemp->previous=newnode;
            newnode->previous=temp;
            temp->next=newnode;
            newnode->next=ptemp;
        }
    }
 int displayR(){
            NodeD* temp=tail;
            int i=0;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\n";
                temp=temp->previous;
                i++;

        }
        return i;
    }
     void displayS(){
        NodeD* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"\n";
            temp=temp->next;
        }
    }
     void deletefront(){
          if(head==NULL)
              cout<<"it is empty";
          else {
              cout<<"deleted is"+head->data;
              head=head->next;
              head->previous=NULL;
          }
    }
 void deleterear(){
        if(tail==NULL)
            cout<<"it is empty";
        else{NodeD* temp=tail;
            cout<<"deleted is "+temp->data;
            tail=tail->previous;
            temp->previous=NULL;
            tail->next=NULL;
        }


    }
 void deleteIth(int p){
        if(head==NULL)
           cout<<"empty";
        else{int i=1;
            NodeD* temp=head;
            while(i<p-1){
                temp=temp->next;
                i++;
            }
            NodeD* ptemp=temp->next;
            cout<<"Deleted data is "+ptemp->data;
            temp->next=ptemp->next;
            (ptemp->next)->previous=temp;
            ptemp->next=ptemp->previous=NULL;
}
 }
};
 int main(){
    DoublyLinkedlist *d=new DoublyLinkedlist();
    d->add(90);
    d->add(80);
    d->add(89);
    d->displayR();
 }