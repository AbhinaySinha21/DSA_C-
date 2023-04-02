#include <bits/stdc++.h>
#define ll long long
using namespace std;
set<ll> s;
void DFT(ll src, unordered_map<ll, vector<ll>> &mp)
{
    stack<ll> st;
    st.push(src);
    while (!st.empty())
    {
        ll rv = st.top();
        st.pop();
        if (s.find(rv) != s.end())
            continue;
        s.insert(rv);
        for (auto it : mp[rv])
            if (s.find(it) == s.end())
                st.push(it);
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        unordered_map<ll, vector<ll>> mp;
        for (int i = 1; i <= m; i++)
        {
            ll x, y;
            cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        s.insert(b);
        DFT(a, mp);
        ll x = 0;
        for (int i = 1; i <= n; i++)
            if (s.find(i) == s.end())
                x++;
        s = {};
        s.insert(a);
        DFT(b, mp);
        ll y = 0;
        for (int i = 1; i <= n; i++)
            if (s.find(i) == s.end())
                y++;
        cout << (ll)(x * y) << endl;
        s = {};
    }
    return 0;
}