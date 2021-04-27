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
#define debug(x) cout << #x << " : " << x << endl;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
//priority_queue<pii, vector<pii>, greater<pii> > pq;
const int N = 2e3 + 4;
vector<vector<int>> adj(N);
int ans = 1;
void dfs(int u, int p, int cnt)
{
    //debug(u);
    ans = max(ans, cnt);
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u, cnt + 1);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> par(n + 1);
    rep(i, n) cin >> par[i];
    rep(i, n)
    {
        if (par[i] == -1)
        {
            ans = max(ans, 1);
            continue;
        }
        adj[i + 1].push_back(par[i]);
        adj[par[i]].push_back(i + 1);
    }
    rep(i, n)
    {
        if (par[i] == -1)
            dfs(i + 1, -1, 1);
    }
    cout << ans << '\n';
}
int main()
{
    fast;
    int t = 1;
    while (t--)
        solve();
    return 0;
}