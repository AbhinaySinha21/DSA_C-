#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        pq.push(v[i]);
    while (pq.size())
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += (a + b);
    }
    cout << sum;

    return 0;
}