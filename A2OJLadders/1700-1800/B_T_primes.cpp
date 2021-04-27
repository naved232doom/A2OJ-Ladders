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

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
vector<bool> is_prime(1e6 + 6, true);
void sieve(int n)
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
pair<ll, ll> isPerfectSquare(ll x)
{
    ll s = (ll)sqrt(x);
    while (s * s < x)
        s++;
    while (s * s > x)
        s--;
    return {s * s == x, s};
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    rep(i, n) cin >> arr[i];
    vector<int> ans(n);
    rep(i, n)
    {
        if (arr[i] == 1)
        {
            ans[i] = 0;
            continue;
        }
        auto p = isPerfectSquare(arr[i]);
        //debug(p.ff);debug(p.ss);
        if (p.ff && is_prime[p.ss])
        {
            ans[i] = 1;
        }
        else
            ans[i] = 0;
    }
    rep(i, n)
    {
        if (ans[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int main()
{
    sieve(1e6 + 6);
    fast;
    int t = 1;
    while (t--)
        solve();
    return 0;
}