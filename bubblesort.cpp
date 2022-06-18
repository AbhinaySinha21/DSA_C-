#include<iostream>
using namespace std;
//using recursion
void bubblesort(int arr[],int st,int ed){
    if(st>ed)
        return;
    if(st<ed)
        {
            if(arr[st]>arr[st+1])
                {
                    int temp=arr[st];
                    arr[st]=arr[st+1];
                    arr[st+1]=temp;
                }
            bubblesort(arr,st+1,ed);
        }
    else
        bubblesort(arr,0,ed-1);
}
int main(){
    int arr[]={7,9,2,5,4,1,9,5};
    bubblesort(arr,0,5);
    int n=8;
    //iterative
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}