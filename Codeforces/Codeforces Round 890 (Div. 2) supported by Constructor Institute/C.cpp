/*
   Author : north_h
   File : C.cpp
   Time : 2023/8/5/22:27
                  _   _         _
 _ __   ___  _ __| |_| |__     | |__
| '_ \ / _ \| '__| __| '_ \    | '_ \
| | | | (_) | |  | |_| | | |   | | | |
|_| |_|\___/|_|   \__|_| |_|___|_| |_|
                          |_____|
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
    vector<int> a(n);
    for (auto &i : a)cin >> i;
    auto check = [&](int x) {
        int res = INT_MAX;
        if (*max_element(ALL(a)) >= x)return true;
        for (int i = 0; i < n - 1; i++) {
            int y = x;
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (a[j] >= y) {
                    res = min(cnt, res);
                    break;
                }
                cnt += (y - a[j]), y--;
            }
        }
        return res <= k;
    };
    int l = 1, r = 2e8, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))l = mid + 1, ans = mid;
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