#include <bits/stdc++.h>
using namespace std;
template <typename PrefixType>
bool if_prefix(const string &str, PrefixType prefix)
{
    return str.starts_with(prefix);
}
vector<int> indegree(unordered_map<char, vector<char>> m)
{
    vector<int> ind(27, 0);
    for (auto it : m)
    {
        for (char nbrs : it.second)
        {
            ind[nbrs - 'a' + 1]++;
        }
    }
    return ind;
}
string TopologicalSort(unordered_map<char, vector<char>> m)
{
    vector<int> ind = indegree(m);
    string ans = "";
    queue<char> q;
    // for (int i = 1; i < ind.size(); i++)
    //     if (ind[i] == 0 && m.find(i - 1 + 'a') != m.end())
    //         q.push(i + 'a' - 1);
    for (auto it : m)
    {
        if (ind[it.first - 'a'] == 0)
            q.push(it.first);
    }
    int count = 0;
    while (!q.empty())
    {
        int rv = q.front();
        count++;
        ans.push_back(rv);
        for (char it : m[rv])
        {
            ind[it - 'a']--;
            if (ind[it - 'a'] == 0)
                q.push(it);
        }
    }
    return m.size() == count ? ans : "";
}
string alienOrder(vector<string> word)
{
    unordered_map<char, vector<char>> m;
    for (int i = 0; i < word.size(); i++)
    {
        string s = word[i];
        for (int j = 0; j < s.length(); j++)
        {
            if (m.find(s[j]) == m.end())
            {
                vector<char> v;
                m[s[j]] = v;
            }
        }
    }
    for (int i = 0; i < word.size() - 1; i++)
    {
        string s1 = word[i];
        string s2 = word[i + 1];
        if (if_prefix(s1, s2) && s1.length() > s2.length())
            for (int j = 0; j < min(s1.size(), s2.size()); j++)
            {
                if (s1[j] != s2[j])
                {
                    m[s1[j]].push_back(s2[j]);
                    break;
                }
            }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    cout << alienOrder(v);
    return 0;
}