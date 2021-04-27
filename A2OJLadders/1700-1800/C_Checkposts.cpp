#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef pair<int, int> pii;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define ld long double
#define rep(i, a) for (ll i = 0; i < a; i++)
#define repe(i, a, b) for (ll i = a; i < b; i++)
#define bac(i, a) for (ll i = a; i >= 0; i--)
#define bace(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define in insert
#define ff first
#define ss second
#define setbit(x) __builtin_popcountll(x)
#define init(c, a) memset(c, a, sizeof(c))
#define all(c) c.begin(), c.end()
#define sz(c) (ll) c.size()
#define lb lower_bound
#define ub upper_bound
#define maxe *max_element
#define mine *min_element
#define rev reverse
#define endl "\n"
#define debug(x) cout << #x << " : " << x << endl;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
//priority_queue<pii, vector<pii>, greater<pii> > pq;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int toDigit(char ch)
{
    return (ch - '0');
}
ll fact(int f)
{
    ll ans = 1;
    for (int i = 1; i <= f; ++i)
    {
        ans = (ans % mod * i % mod) % mod;
    }
    return ans;
}
vector<vector<int>> adj;
vector<vector<int>> adjt;
vector<int> visited;
vector<int> order;
vector<int> component;
vector<int> cost;
ll curmin = inf;
void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
    order.push_back(u);
}
void dfs2(int u)
{
    component.push_back(cost[u]);

    curmin = min(curmin, 1ll * cost[u]);
    visited[u] = 1;
    for (int v : adjt[u])
    {
        if (!visited[v])
            dfs2(v);
    }
}

void solve()
{
    int n;
    cin >> n;
    cost.resize(n + 1);
    repe(i, 1, n + 1)
    {
        cin >> cost[i];
    }
    adj.resize(n + 1);
    adjt.resize(n + 1);
    visited.resize(n + 1);
    int m;
    cin >> m;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }

    repe(i, 1, n + 1)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(all(order));

    for (int i = 1; i <= n; ++i)
    {
        visited[i] = 0;
    }
    ll ans = 1;
    ll c = 0;
    for (int i : order)
    {
        if (!visited[i])
        {

            curmin = inf;
            // debug(i);
            dfs2(i);

            sort(all(component));
            int p = 0;

            for (int j : component)
            {
                if (j == curmin)
                    p++;
                else
                    break;
            }

            ans = (ans % mod * p % mod) % mod;
            c = (c + curmin);
            component.clear();
        }
    }
    cout << c << " " << ans << '\n';
}
int main()
{
    fast;

    int t = 1;
    while (t--)
        solve();
    return 0;
}