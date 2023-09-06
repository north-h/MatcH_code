/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-12 18:36:49
 * Problem : cf-1624_D
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
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto i : s)mp[i]++;
    int sl = 0, db = 0;
    for(auto [x, y] : mp) {
        if(y >= 2)db += y / 2, sl += y % 2;
        else sl++;
    }
    auto check = [&](int x) {
        int dbb = 0, sll = 0;
        if(x % 2 == 0)dbb += x / 2 * k;
        else dbb += (x - 1) / 2 * k, sll += k;
        if(dbb <= db && sll <= sl + (db - dbb) * 2)return true;
        return false;
    };
    int l = 0, r = 2e5 + 10, ans = 0;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid))l = mid + 1, ans = mid;
        else r = mid - 1;
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