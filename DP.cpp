#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int lis(vector<int> &v)
{ // DP approach (N^2)
    // vector<int> dp(v.size(), 1);
    // for (int i = 1; i < dp.size(); i++)
    // {
    //     for (int j = i - 1; j >= 0; j--)
    //     {
    //         if (v[i] > v[j])
    //             dp[i] = max(dp[j] + 1, dp[i]);
    //     }
    // }
    // int maxL = dp[0];
    // for (int i = 1; i < dp.size(); i++)
    //     maxL = max(dp[i], maxL);
    // return maxL;

    // Binary Search approach (NlogN)
    vector<int> sub(v.size());
    sub[0] = v[0];
    int len = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] <= sub[len - 1])
        {
            int it = lower_bound(sub.begin(), sub.begin() + len, v[i]) - sub.begin();
            sub[it] = v[i];
        }
        else
        {
            sub[len] = v[i];
            len++;
        }
    }
    return len;
}
// i--> s1 and j--> s2
int lcs(string s1, string s2, int i, int j)
{
    int ans = 0;
    if (i == s1.length() || j == s2.length())
        return 0;
    if (s1[i] == s2[j])
        ans = 1 + lcs(s1, s2, i + 1, j + 1);
    else
    {
        int fs = lcs(s1, s2, i + 1, j);
        int ss = lcs(s1, s2, i, j + 1);
        ans = max(fs, ss);
    }
    return ans;
}
int lcsTD(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    int ans = 0;
    if (i == s1.length() || j == s2.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        ans = 1 + lcsTD(s1, s2, i + 1, j + 1, dp);
    else
    {
        int fs = lcsTD(s1, s2, i + 1, j, dp);
        int ss = lcsTD(s1, s2, i, j + 1, dp);
        ans = max(fs, ss);
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int lcsBU(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    string s1, s2;
    s1 = "abcde";
    s2 = "ace";
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    for (int i = 0; i < s1.length(); i++)
        dp[i][0] = 0;
    for (int i = 0; i < s2.length(); i++)
        dp[0][i] = 0;
    cout << lcsBU(s1, s2);
    return 0;
}