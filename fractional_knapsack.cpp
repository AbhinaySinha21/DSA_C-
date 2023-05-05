#include <bits/stdc++.h>
using namespace std;
bool static compare(pair<int, int> a, pair<int, int> b)
{
    return (a.first / (double)a.second) > (b.first / (double)b.second);
}
double knapsack_F(vector<pair<int, int>> &k, int W)
{
    sort(k.begin(), k.end(), compare);
    int n = k.size();
    double result = 0.0;
    int i = 0;
    while (W > 0 && i < n)
    {
        if (W >= k[i].second)
        {
            result += k[i].first;
            W -= k[i].second;
        }
        else
        {
            result += (double)W / k[i].second * k[i].first;
            W = 0;
        }
        i++;
    }
    return result;
}
int main()
{
    vector<pair<int, int>> v = {{60, 10}, {100, 20}, {120, 30}};
    int w = 50;
    cout << knapsack_F(v, w);
    return 0;
}