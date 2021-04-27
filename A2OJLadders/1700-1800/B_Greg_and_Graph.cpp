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
const int N = 505;
int adj[N][N];
int d[N][N];
void solve()
{
    int n;
    cin >> n;
    repe(i, 1, n + 1)
    {
        repe(j, 1, n + 1) cin >> adj[i][j];
    }
    vector<int> del(n + 1);
    repe(i, 1, n + 1) cin >> del[i];
    // floyd warshall
    init(d, mod);
    reverse(del.begin() + 1, del.end());
    vector<ll> a;
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                adj[del[i]][del[j]] =
                    min(adj[del[i]][del[j]], adj[del[i]][del[k]] + adj[del[k]][del[j]]);
            }
        }
        ll ans = 0;
        repe(i, 1, k + 1)
        {
            repe(j, 1, k + 1)
            {
                ans += adj[del[i]][del[j]];
            }
        }
        a.push_back(ans);
    }
    reverse(all(a));
    rep(i, n) cout << a[i] << ' ';
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