#include <bits/stdc++.h>
using namespace std;
int MaxProfit(vector<int> v, int i, int j, int y)
{
    if (i > j)
        return 0;
    int first = y * v[i] + MaxProfit(v, i + 1, j, y + 1);
    int last = y * v[j] + MaxProfit(v, i, j - 1, y + 1);
    return max(first, last);
}
int MaxProfitBU(vector<int> v)
{
    vector<vector<int>> dp(v.size(), vector<int>(v.size(), 0));
    for (int i = 0; i < dp.size(); i++)
        dp[i][i] = v[i] * v.size();
    int y = v.size() - 1;
    for (int dia = 1; dia < dp.size(); dia++)
    {
        for (int j = dia; j < v.size(); j++)
        {
            int i = j - dia;
            int first = v[i] * y + dp[i + 1][j];
            int last = v[j] * y + dp[i][j - 1];
            dp[i][j] = max(first, last);
        }
        y--;
    }
    return dp[0][dp.size() - 1];
}
int main()
{
    vector<int> wine = {2, 3, 5, 1, 4};
    cout << MaxProfitBU(wine);
    return 0;
}