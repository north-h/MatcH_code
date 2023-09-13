/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-13 16:05:31
 *
 * Problem: B. Gardener and Tree
 * Contest: Codeforces - SMU Autumn 2023 Round 3(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470094/problem/B
 * MemoryL: 256 MB
 * TimeL:   4000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
const int N = 400010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<int> g[N];
int r[N];
int dg[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        r[i] = dg[i] = 0;
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        dg[a]++;
        dg[b]++;
    }
    auto topsort = [&]() {
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(dg[i] == 1) {
                r[i] = 1;
                q.push(i);
            }
        }
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(auto i : g[t]) {
                dg[i]--;
                if(dg[i] == 1) {
                    q.push(i);
                    r[i] = r[t] + 1;
                }
            }
        }
    };
    int ans = n;
    topsort();
    for(int i = 1; i <= n; i++) {
        ans -= (r[i] <= k);
        // cout << rank[i] << ' ';
    }
    // cout << endl;
    cout << ans << endl;
}
int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}