#include<iostream>
using namespace std;
class NodeL{
    public:
        int data;
        NodeL* next;
}
void insert(NodeL* head,int val){
    NodeL N={val,NULL};
    if(head==NULL)
        head=N;
    else{
        NodeL *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=&N;
    }

}
int main(){
    NodeL *head=NULL;
    insert(head,8);
    insert(head,9);
    insert(head,10);

}