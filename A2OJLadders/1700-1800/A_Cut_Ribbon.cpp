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

void solve()
{
    int n;
    vector<int> arr(3);
    cin >> n;
    rep(i, 3) cin >> arr[i];
    sort(all(arr));
    int ans = 0;
    for (int i = 0; i <= n / arr[1]; ++i)
    {
        for (int j = 0; j <= n / arr[2]; ++j)
        {
            int rem = n - (arr[1] * i + arr[2] * j);
            if (rem % arr[0] == 0)
            {
                ans = max(ans, (i + j + rem / arr[0]));
            }
        }
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