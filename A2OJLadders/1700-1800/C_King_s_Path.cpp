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

const int N = 2e5 + 5;
typedef pair<ll, ll> pll;
vector<int> dx = {-1, 1, 0, 0, 1, -1, -1, +1};
vector<int> dy = {0, 0, 1, -1, 1, -1, +1, -1};
void solve()
{
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    cin >> n;
    map<pii, int> mp;
    int cnt = 0;
    vector<vector<int>> adj(N);
    int dist[N];
    init(dist, -1);

    for (int i = 0; i < n; i++)
    {
        int row, lo, hi;
        cin >> row >> lo >> hi;
        for (int j = lo; j <= hi; j++)
            if (mp.find(pii(row, j)) == mp.end())
                mp[pii(row, j)] = cnt++;
    }
    for(auto it=mp.begin();it!=mp.end();++it){
        auto p1= it->first;
        auto v=it->second;
        int x=p1.ff,y=p1.ss;
        for(int i=0;i<sz(dx);++i){
            int px= x+dx[i],py=dy[i]+y;
            if(mp.find(make_pair(px,py))!=mp.end()){
                adj[mp[make_pair(x,y)]].push_back(mp[pii(px,py)]);
            }
        }
    }
    queue<int> q;
    dist[mp[pii(x0,y0)]]=0;

    q.push(mp[pii(x0, y0)]);
    while (!q.empty())
    {
        auto cur = q.front();
       // debug(dist[cur]);
        q.pop();
        for (auto v : adj[cur])
        {
            //debug(v);
            if (dist[v] == -1)
            {
                q.push(v);
                dist[v] = dist[cur] + 1;
            }
        }
    }
    if(mp.find(make_pair(x1,y1))==mp.end()){
        cout<<"-1\n";
        return;
    }
    cout << dist[mp[pii(x1, y1)]] << '\n';
}
int main()
{
    fast;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t = 1;
    while (t--)
        solve();
    return 0;
}