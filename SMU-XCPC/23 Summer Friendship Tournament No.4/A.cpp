/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-09 23:37:40
 * =====================================
 * Thirty years east, thirty years west,
 * don't you dare bully me because I'm poor now.
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
 */

#pragma GCC optimize(3)

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
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 25;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

struct S {
    int h, l, r;
} a[N];

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].h >> a[i].l >> a[i].r;
        mx = max(mx, a[i].h);
    }
    for(int i = 0; i <= 1825 * mx; i++) {
        bool ok = true;
        for(int j = 1; j <= n; j++) {
            int k = i % a[j].h;
            if(a[j].l < a[j].r) {
                if(k >= 0 && k <= a[j].l || k >= a[j].r && k < a[j].h)continue;
                else {
                    ok = false;
                    break;
                }
            } else {
                if(k >= a[j].r && k <= a[j].l)continue;
                else {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            cout << i << endl;
            return ;
        }
    }
    cout << "impossible" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}