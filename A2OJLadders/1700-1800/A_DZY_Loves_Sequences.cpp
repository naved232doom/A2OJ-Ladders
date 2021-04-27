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

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    rep(i, n) cin >> arr[i];
    ll up[n], down[n];
    ll cnt = 1;
    ll ans = -1;
    for (int i = 0; i < n; ++i)
    {
        if (i - 1 >= 0 && arr[i] > arr[i - 1])
            cnt++;
        else
            cnt = 1;
        up[i] = cnt;
        ans = max(ans, up[i]);
    }
    cnt = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (i + 1 < n && arr[i + 1] > arr[i])
            cnt++;
        else
            cnt = 1;
        down[i] = cnt;
        ans = max(down[i], ans);
    }

    for (int i = 0; i < n; ++i)
    {
        if (i + 1 < n)
            ans = max(down[i + 1] + 1, ans);
        if (i - 1 >= 0)
            ans = max(up[i - 1] + 1, ans);
        if (i + 1 < n && i - 1 >= 0 && arr[i + 1] > arr[i - 1] + 1)
        {
            ans = max(ans, up[i - 1] + down[i + 1] + 1);
        }
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