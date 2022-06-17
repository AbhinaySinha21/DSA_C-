#include<iostream>
using namespace std;
#define MAX  4
int a[MAX];
int top=-1;
void push(int item){
    top=top+1;
    a[top]=item;
}
void pop(){
   int item = a[top];
    cout<<"popped item is \n"<<item<<"\n";
    top=top-1;
}
void traverse(){
    int h=top;
    for(int i=0;i<=h;i++)
        cout<<a[i]<<" item is at "<<i+1<<"\n";
}
int main(){
     char ch;
   do{
       cout<<"1.Push element\n2.Pop element\n3.Traverse\n";
       cout<<"enter choice";
       int c;
       cin>>c;
       switch(c){
           case 1: if(top!=MAX-1){
           printf("Enter number");
                   int item;
                   cin>>item;
                   push(item);}else{
                       cout<<"Cannot add\n";
                   }break;
            case 2: if(top!=-1){
                pop();
            }else{
                cout<<"Stack is empty\n";
            }break;
            case 3:traverse();break;
            default: cout<<"wrong choice";}

            cout<<"want to choose again?(y/Y)";
           
            cin.ignore();
            cin>>ch;
       }while(ch=='y' || ch=='Y');
   }
