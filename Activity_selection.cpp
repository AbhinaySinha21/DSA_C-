#include <bits/stdc++.h>
using namespace std;
bool static compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), compare);
    vector<pair<int, int>> ans;
    pair<int, int> demo = v[0];
    ans.push_back(demo);
    for (int i = 1; i < v.size(); i++)
    {
        if (demo.second <= v[i].first)
        {
            ans.push_back(v[i]);
            demo = v[i];
        }
    }
    for (auto it : ans)
        cout << it.first << " " << it.second << "\n";
    return 0;
}