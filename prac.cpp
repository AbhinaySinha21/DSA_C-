#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool isValid(string s)
{
    int i = 0;
    stack<int> st;
    while (i < s.length())
    {
        if (s[i] == '<')
            st.push(s[i]);
        else if (st.empty() && s[i] == '>')
            return false;
        else if (st.top() == '<' && s[i] == '>')
            st.pop();
        i++;
    }
    if (st.empty())
        return true;
    return false;
}
vector<int> balancedorNot(vector<string> expression, vector<int> maxReplacement)
{
    vector<int> ans;
    for (int i = 0; i < expression.size(); i++)
    {
        if (isValid(expression[i]))
            ans.push_back(1);
        else
        {
            int k = 0;
            for (int j = 0; j < expression[i].size(); j++)
            {
                if (expression[i][j] == '>')
                    k--;
                else
                    k++;
            }
            if (k < 0 && abs(k) <= maxReplacement[i])
                ans.push_back(0);
            else
                ans.push_back(1);
        }
    }
    return ans;
}
string gameWinner(string colors)
{
    string wend = "www";
    string bob = "bbb";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}