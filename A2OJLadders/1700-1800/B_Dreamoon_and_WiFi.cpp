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
set<string> st;
long long compute_hash(string const &s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int bits = 0;
    int s1 = 0, s2 = 0;
    int n = sz(a);
    rep(i, n)
    {
        if (a[i] == '+')
            s1++;
        if (a[i] == '-')
            s1--;
        if (b[i] == '+')
            s2++;
        if (b[i] == '-')
            s2--;
        if (b[i] == '?')
            bits++;
    }

    float ok = 1;
    if (bits == 0)
    {
        if (s1 == s2)
            ok = 1;
        else
            ok = 0;
        cout << fixed << setprecision(10) << ok << '\n';
        return;
    }
    ok = 0;
    for (int i = 0; i <= pow(2, bits) - 1; ++i)
    {
        int cur = 0;
        for (int j = 0; j < bits; ++j)
        {
            if (i & (1 << j))
                cur++;
            else
                cur--;
        }

        //debug(cur);
        if (s1 == (s2 + cur))
        {
            ok++;
        }
    }
    float tot = 1;
    rep(i, bits) tot *= 2;
    //    debug(ok);
    //    debug(tot);
    float ans = ok / tot;
    cout << fixed << setprecision(10) << ans << '\n';
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