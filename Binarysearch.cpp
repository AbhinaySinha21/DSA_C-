#include <bits/stdc++.h>
using namespace std;
// using recursion
int binarySearch(int arr[], int st, int ed, int target)
{
    if (st - ed == 1)
        return -1;
    int mid = (ed + st) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, st, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, ed, target);
}
int main()
{
    vector<int> arr = {0, 8, 10, 11, 56, 78, 89};
    // cout<<binarySearch(arr,0,7,56)+1;
    // iterative
    int st = 0;
    int ed = arr.size();
    int mid;
    int target = 56;
    int ans = -1;
    while (st <= ed)
    {
        mid = (st + ed) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] > target)
            ed = mid - 1;
        else
            st = mid + 1;
    }
    if (ans != -1)
        cout << "The index for " << target << " is " << ans + 1;
    else
        cout << "elemnt is not present";
}