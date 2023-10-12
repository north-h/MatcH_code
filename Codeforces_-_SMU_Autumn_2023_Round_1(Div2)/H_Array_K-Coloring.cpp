/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-09 16:34:06
 *
 * Problem: H. Array K-Coloring
 * Contest: Codeforces - SMU Autumn 2023 Round 1(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470092/problem/H
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<PII> a(n);
    map<int, int>  mp;
    int res = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
        mp[a[i].fi]++;
    }
    sort(ALL(a));
    int mx = 0;
    for(auto [x, y] : mp)mx = max(mx, y);
    if(mx > k || n < k)cout << "NO" << endl;
    else {
        vector<int> ans(n);
        int t = k;
        for(int i = 1; i < n; i++) {
            ans[a[i - 1].se] = t;
            t--;
            if(t == 0)t = k;
        }
        ans[a[n - 1].se] = t;
        cout << "YES" << endl;
        for(auto i : ans)cout << i << ' ';
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}