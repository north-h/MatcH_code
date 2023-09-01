/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-30 13:19:52
 * =====================================
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
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), s(n + 1), ss(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] | a[i];
        if(i == 1)ss[i] = s[i];
        else ss[i] = ss[i - 1] & s[i];
    }
    // for(int i = 1; i <= n; i++)cout << s[i] << ' ';
    // cout << endl;
    // for(int i = 1; i <= n; i++)cout << ss[i] << ' ';
    // cout << endl;
    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        int ans = 0;
        for(int i = 0; i < 60; i++) {
            int x1 = (s[l - 1] >> i & 1);
            int y1 = (s[r] >> i & 1);
            (ss[l - 1] >> i & 1);
            int y2 = (s[r] >> i & 1);
            if(x1 == 0 && y1 == 1 || (x1 == 1 && y1 == 1 && y2 == 1))ans += pow(2ll, i);
        }
        cout << (ans | x) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}