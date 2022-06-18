#include<iostream>
using namespace std;
void mergeInplace(int arr[],int st,int ed,int mid){
    int i=st;
    int j=mid;
    int arr1[ed-st];
    int k=0;
    while(i<mid && j<ed){
        if(arr[i]>arr[j])
            {arr1[k]=arr[j];
             j++;}
        else{
            arr1[k]=arr[i];
            i++;
        }
        k++;
    }
    while(i<mid)
    {
        arr1[k]=arr[i];
        k++;
        i++;
    }
    while(j<ed)
    {
        arr1[k]=arr[j];
        k++;
        j++;
    }
    for(i=0;i<ed-st;i++)
        arr[i+st]=arr1[i];
    
}
void mergeSort(int arr[],int st,int ed){
    if(ed-st==1)
        return;
    int mid=(st+ed)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid,ed);
    mergeInplace(arr,st,ed,mid);
}
int main(){
    int arr[]={5,7,6,4,8,10,3};
    int n=7;
    mergeSort(arr,0,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}