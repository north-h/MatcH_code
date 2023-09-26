/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-26 22:36:45
 *
 * Problem: D. Reverse Madness
 * Contest: Codeforces - Codeforces Round 900 (Div. 3)
 * URL:     https://codeforces.com/contest/1878/problem/D
 * MemoryL: 256 MB
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
#define lcm(x,y) x*y/__gcd(x,y)
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int f[N][30], g[N][30], lg2[N];
int n, m;
string s;
int l[N], r[N], a[N];

// void init() {
//     lg2[0] = -1;
//     for(int i = 1; i <= m; i ++) lg2[i] = lg2[i >> 1] + 1;
//     // 数组下标从1开始
//     for (int i = 1; i <= m; i++)f[i][0] = a[i];
//     for (int i = 1; i <= m; i++)g[i][0] = a[i];

//     for (int j = 1; (1 << j) <= m; j++) {
//         for (int i = 1; i + (1 << j) - 1 <= m; i++) {
//             f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
//             g[i][j] = min(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
//         }
//     }
// }

// int querymax(int l, int r) {
//     int k = lg2[r - l + 1];
//     return max(f[l][k], f[r - (1 << k) + 1][k]);
// }

// int querymin(int l, int r) {
//     int k = lg2[r - l + 1];
//     return min(g[l][k], g[r - (1 << k) + 1][k]);
// }

void solve() {
    cin >> n >> m >> s;
    s = " " + s;
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int i = 1; i <= m; i++)cin >> l[i];
    for(int i = 1; i <= m; i++)cin >> r[i];
    for(int i = 1; i <= m; i++) {
        a[i] = r[i] + l[i];

    }
    int q;
    cin >> q;
    // vector<PCI> ans(n + 1);
    // for(int i = 1; i <= n; i++) {
    //     ans[i].fi = s[i];
    //     ans[i].se = i;
    // }
    for(int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int ll = 1, rr = n, ans;
        while(ll <= rr) {
            int mid = ll + rr >> 1;
            if(r[mid] > x)rr = mid - 1, ans = mid;
            else if(l[mid] < x)ll = mid + 1, ans = mid;
            else {
                ans = mid;
                break;
            }
        }
        cout <<  ans << endl;
    }
    cout << s << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}