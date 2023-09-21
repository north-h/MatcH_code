/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-21 22:36:10
 *
 * Problem: F. Money Trees
 * Contest: Codeforces - Codeforces Round 898 (Div. 4)
 * URL:     https://codeforces.com/contest/1873/problem/F
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
#define debug(a,b) cout << (steing)a << '=' << b << endl;
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), pmax(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i], s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    for(int i = 1; i <= n; i++)pmax[i] = i;
    // for(int i = 1; i <= n; i++)cout << pmax[i] << ' ';
    // cout << endl;
    for(int i = n; i > 1; i--) {
        // cout << a[i - 1] << ' ' << a[i] << endl;
        if(b[i - 1] % b[i] == 0)pmax[i - 1] = pmax[i];
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int l = i, r = pmax[i], ans = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            if(s[mid] - s[i - 1] <= k)l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        res = max(res, ans - i + 1);
    }
    // for(int i = 1; i <= n; i++)cout << pmax[i] << ' ';
    // cout << endl;
    cout << res << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}