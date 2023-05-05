#include <bits/stdc++.h>
using namespace std;
int minOperation(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= s1.size() || j >= s2.size())
        return (i == s1.size() ? s2.size() - j : s1.size() - i);
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = minOperation(s1, s2, i + 1, j + 1, dp);
    else
        return dp[i][j] = min(minOperation(s1, s2, i + 1, j, dp), min(minOperation(s1, s2, i, j + 1, dp), minOperation(s1, s2, i + 1, j + 1, dp))) + 1;
}
int minOperationBU(string s1, string s2, vector<vector<int>> &dp)
{
    for (int i = 1; i <= s2.size(); i++)
        dp[0][i] = i;
    for (int i = 1; i <= s1.size(); i++)
        dp[i][0] = i;
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}
int main()
{
    string word1 = "food";
    string word2 = "money";
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    cout << minOperationBU(word1, word2, dp);
    return 0;
}