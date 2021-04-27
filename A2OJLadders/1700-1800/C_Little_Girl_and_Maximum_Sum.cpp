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

int n, q;
// one based BIT watch for rterorrs
const int N = 2e5 + 5;
int BIT[N], a[N];
void update(int x, int delta)
{
    for (; x <= n; x += x & -x)
        BIT[x] += delta;
}
int query(int x)
{
    int sum = 0;
    for (; x > 0; x -= x & -x)
        sum += BIT[x];
    return sum;
}
void solve()
{
    cin >> n >> q;
    vector<ll> arr(n + 1);
    repe(i, 1, n + 1) cin >> arr[i];
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        update(u, 1);
        update(v + 1, -1);
    }
    vector<ll> inx(n + 1);
    repe(i, 1, n + 1)
    {
        inx[i] = query(i);
    }
    sort(all(inx));
    sort(all(arr));

    ll ans = 0;
    for (int i = n; i >= 1; --i)
    {
        // debug(arr[i]);
        // debug(inx[i]);
        ans += inx[i] * arr[i];
    }
    cout << ans << '\n';
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