/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-27 10:19:30
 *
 * Problem: C. The Union of k-Segments
 * Contest: Codeforces - SMU Autumn 2023 Trial 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475544/problem/C
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
#define debug(a) cout<<#a<<'='<<a<<endl
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<PII> a;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.push_back({l, -1});
        a.push_back({r, 1});
    }
    sort(ALL(a));
    // for(auto [x, y] : a)cout << x << ' ' << y << endl;
    int ans = 0;
    int cnt = 0;
    int l = -1, r;
    vector<PII> b;
    bool ok = true;
    for(int i = 0; i < a.size(); i++) {
        if(a[i].se == -1)cnt++;
        else cnt--;
        // debug(cnt);
        if(cnt == k && ok) {
            l = a[i].fi;
            ok = false;
        } else if(cnt == k - 1 && !ok) {
            b.push_back({l, a[i].fi});
            ok = true;
        }
    }
    cout << b.size() << endl;
    for(auto [x, y] : b)cout << x << ' ' << y << endl;
}
int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}