#include<iostream>
using namespace std;
//using recursion
void selectionsort(int arr[],int n){
    if(n<=0)
        return;
    int j=-1,max=INT_MIN;
    for(int i=0;i<=n;i++){
       if(max<arr[i]){
        max=arr[i];
        j=i;
       }
    }
    if(j!=n){
        int temp=arr[j];
        arr[j]=arr[n];
        arr[n]=temp;
    }
    selectionsort(arr,n-1);
}
int main(){
    int arr[]={6,8,7,5,3,4};
    int n=6;
    selectionsort(arr,5);
    //iterative
    for(int i=0;i<n-1;i++){
        int min=INT_MAX,temp=-1;
        for(int j=i;j<n;j++){
            if(min>arr[j])
            {
                min=arr[j];
                temp=j;
            }
        }
        if(temp!=i){
            int c=arr[temp];
            arr[temp]=arr[i];
            arr[i]=c;
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}