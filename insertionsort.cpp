#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
    // Base case
    if (n <= 1)
        return;
    insertionSort(arr,n-1);
    int key = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
int main(){
int arr[]={9,7,8,6,3,5,4};
int n=7;
insertionSort(arr,n);
//iterative
int key, j;
for(int i = 1; i<n; i++) {
   key = arr[i];
   j = i;
   while(j > 0 && arr[j-1]>key) {
      arr[j] = arr[j-1];
      j--;
   }
   arr[j] = key;   
}
for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
}

