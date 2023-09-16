/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-16 12:10:38
 *
 * Problem: J. Jet Set
 * Contest: Codeforces - SMU Autumn 2023 Round 4(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/473585/problem/J
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
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
    int n;
    cin >> n;
    vector<PII > a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    vector<int> ans(1000, 0);
    vector<int> ans1(1000, 0);
    a[n] = a[0];
    for (int i = 1; i <= n; i++) {
        int ll = a[i - 1].se + 180;
        int rr = a[i].se + 180;
        int l = min(ll, rr);
        int r = max(ll, rr);
        int res = min(r - l, 360 - r + l);
        int re = abs(90 - a[i].fi) + abs(90 - a[i - 1].fi);
        re = min(re, abs(-90 - a[i].fi) + abs(-90 - a[i - 1].fi));
        // re = re * 2;
        cout << res << ' ' << re << endl;
        if (re <= res) {
            cout << "yes" << endl;
            return;
        } else if (360 - r + l > r - l) {
            for (int j = l; j <= r; j++)ans[j] = 1, ans1[j] = 1;
        } else {
            for (int j = 0; j < l; j++)ans[j] = 1, ans1[j] = 1;
            for (int j = r + 1; j <= 360; j++)ans[j] = 1, ans1[j] = 1;
        }
    }
    for (int i = 0; i < 360; i++) {
        if (!ans[i]) {
            printf("no %.1f\n", (i + i) / 2);
            return;
        }
    }
    for (int i = 0; i < 360; i++) {
        if (!ans1[i]) {
            printf("no %.1f\n", (i + i + 1) / 2);
            return;
        }
    }
    cout << "yes" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}