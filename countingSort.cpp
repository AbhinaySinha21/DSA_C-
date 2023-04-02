#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={67,89,3 ,45 ,0,98 ,56};
    vector<int> count(99,0);
    for(int i=0;i<v.size();i++){
        count[v[i]]++;
    }
    for(int i=1;i<count.size();i++){
        count[i]=count[i]+count[i-1];
    }
    vector<int> res(v.size());
    for(int i=0;i<v.size();i++){
        int va=v[i];
        int pos=count[va];
        int id=pos-1;
        res[id]=va;
        count[va]--;
    }
    for(int i:res)
        cout<<i<<" ";
    return 0;
}