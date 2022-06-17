#include<iostream>
using namespace std;
/*using recursion*/
int linearSearch(int arr[],int n,int target){
    if(n==0)
        return -1;
    if(arr[n-1]==target)
        return n-1;
    int l=linearSearch(arr,n-1,target);
    return l;
}
int main(){
    int arr[]={1,4,5,7,8,9,6,4};
    int target=8;
    int n=8;
    //iterative
    for(int i=0;i<n;i++)
        if(arr[i]==target)
            {
                cout<<"position is "<<i+1;
                break;
            }
    cout<<linearSearch(arr,8,8);
}