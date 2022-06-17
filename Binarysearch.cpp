#include<iostream>
using namespace std;
//using recursion
int binarySearch(int arr[],int st,int ed,int target){
    if(st-ed==1)
        return -1;
    int mid=(ed+st)/2;
    if(arr[mid]==target)
        return mid;
    else if(arr[mid]>target)
        return binarySearch(arr,st,mid-1,target);
    else 
        return binarySearch(arr,mid+1,ed,target);
}
int main(){
    int arr[]={0,8,10,11,56,78,89};
    cout<<binarySearch(arr,0,7,56)+1;
    //iterative
    int st=0;
    int ed=7;
    int mid;
    int target=56;
    while(st<=ed){
        mid=(st+ed)/2;
        if(arr[mid]==target)
        {
            cout<<mid+1;
            break;
        }else if(arr[mid]>target)
            ed=mid-1;
        else
            st=mid+1;
    }
}