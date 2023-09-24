/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-24 22:35:23
 *
 * Problem: A. Rigged!
 * Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1879/problem/A
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
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int>s(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> c[i];
    }
    auto check = [&](int x) {
        for(int i = 1; i < n; i++) {
            if(s[i] >= x && c[i] >= c[0] )return false;
        }
        return true;
    };
    int l = 1, r = s[0], ans = -1;
    while(l <= r) {
        int mid = l + r >> 1;
        // cout << l << ' ' << r << endl;
        if(check(mid)) {
            r = mid - 1, ans = mid;
            break;
        } else l = mid + 1;
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}