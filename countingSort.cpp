#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {67, 89, 3, 45, 0, 98, 56};
    int maxL = *max_element(v.begin(), v.end());
    vector<int> count(maxL + 1, 0);
    for (int i = 0; i < v.size(); i++)
    {
        count[v[i]]++;
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    vector<int> res(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int pos = count[v[i]];
        res[pos - 1] = v[i];
        count[v[i]]--;
    }
    for (int i : res)
        cout << i << " ";
    return 0;
}