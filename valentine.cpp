/*
    It's Valentine's Day in Russia today. as we all know number of girls in Russia is more than number of boys 😜 hence boys
    have an extra advantage while choosing girl for the valentine evening.
    Each boy has certain number of chocolates and each girl has certain number of candies.
     Now you being the anchor of evening wants to pair all the boys with girls such that the sum of absolute
    difference between boy's chocolate and girl's candy in a pair is minimized. Ofcourse some of the girls will remain unpaired but that's okay as we are in Russia 😜

Input Format
The first line consists of two integers N and M. then follow N integers in second line. Then follow M integers in third line. M >= N

Constraints
1 <= N <= 5000
1 <= M <= 5000
M >= N
1 <= chocolates <= 1000000
1 <= candies <= 1000000

Output Format
The only line which consists of required sum of absolute differences.

Sample Input
2 5
4 5
1 2 3 4 5
Sample Output
0
Explanation
we can pair boy numbered 1 with girl numbered 4 and boy numbered 2 with girl numbered 5
*/
#include <bits/stdc++.h>
using namespace std;
int pairUP(vector<int> &g, vector<int> &b, int i, int j, vector<vector<int>> &dp)
{
    if (j == b.size())
        return 0;
    if (i == g.size())
        return 1e7;
    if (dp[i][j] != -1)
        return dp[i][j];
    int pick = abs(g[i] - b[j]) + pairUP(g, b, i + 1, j + 1, dp);
    int notpick = pairUP(g, b, i + 1, j, dp);
    return dp[i][j] = min(pick, notpick);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g(m), b(n);
    for (int j = 0; j < n; j++)
        cin >> b[j];
    for (int i = 0; i < m; i++)
        cin >> g[i];
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << pairUP(g, b, 0, 0, dp);
    return 0;
}