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
const double EPS = 1e-8;
const double PI = acos(-1.0);
//priority_queue<pii, vector<pii>, greater<pii> > pq;

int n, m;
const int N = 1e5 + 5;
vector<vector<pii>> adj(N);
vector<int> visited(N);
vector<int> score(N);
vector<int> whites(N);

void dfs(int u, int cnt)
{
    visited[u] = 1;
    score[u] += whites[u];
    for (auto v : adj[u])
    {
        if (!visited[v.ff])
        {
            dfs(v.ff, cnt);
            score[u] += score[v.ff];
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
        if (t == 2)
        {
            whites[u] = 1;
            whites[v] = 1;
        }
    }
    dfs(1, 0);
    vector<int> ans;
    for (int i = 2; i <= n; ++i)
    {
        if (whites[i] == 1 && score[i] == 1)
        {
            ans.push_back(i);
        }
    }
    cout << sz(ans) << '\n';
    for (int v : ans)
        cout << v << ' ';
    cout << '\n';
}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--)
        solve();
    return 0;
}