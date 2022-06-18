#include<iostream>
using namespace std;
void QuickSort(int arr[],int low,int high){
    if(low>high)
        return;
    int st=low;
    int ed=high-1;
    int pi=(low+high)/2;
    while(st<ed){
        while(arr[st]<arr[pi])
            st++;
        while(arr[ed]>arr[pi])
            ed--;
        if(st<ed){
            int temp=arr[st];
            arr[st]=arr[ed];
            arr[ed]=temp;
            st++;
            ed--;
        }
        QuickSort(arr,st,high);
        QuickSort(arr,low,ed);
    }
    
}
int main(){
    int arr[]={9,8,7,4,3,1,10};
    int n=7;
    QuickSort(arr,0,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";   
}