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

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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
        a[i].se += 180;
    }
    vector<int> ans(1000, 0);
    vector<int> ans1(1000, 0);
    a[n] = a[0];
    for (int i = 1; i <= n; i++) {
        if (abs(a[i].se - a[i - 1].se) == 180) {
            cout << "yes" << endl;
            return;
        }
        int l = min(a[i - 1].se, a[i].se);
        int r = max(a[i - 1].se, a[i].se);
        // cout << l << ' ' << r << endl;
        if(abs(l - r) > 180) {
            for(int i = 0; i <= l; i++)ans[i] = ans1[i] = 1;
            for(int i = r; i <= 360; i++)ans[i] = ans1[i] = 1;
        } else {
            for(int i = l; i <= r; i++)ans[i] = ans1[i] = 1;
        }
    }
    for (int i = 0; i <= 360; i++) {
        if (!ans[i]) {
            printf("no %.1f\n", (i - 180) * 1.0);
            return;
        }
    }
    for (int i = 0; i <= 360; i++) {
        if (!ans1[i]) {
            printf("no %.1f\n", (i + 0.5 - 180) * 1.0);
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