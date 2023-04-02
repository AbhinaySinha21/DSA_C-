#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool ispossible(vector<int> v,int mid){
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=abs(mid-v[i]);
    }
    if(sum>=v[0] && sum<=v[v.size()-1])
        return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> v;
    sort(v.begin(),v.end());
    int ans,mid;
    int st=0;
    int ed=v[v.size()-1]-v[0];
    while(st<=ed){
        mid=(st+ed)/2;
        if(ispossible(v,mid))
            {   ans=mid;
                ed=mid-1;
            }
        else
            st=mid+1;
    }
    int s=0;
    for(int i=0;i<v.size();i++)
        s+=abs(ans-v[i]);
    cout<<s;
    return 0;

}