/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-10 18:58:27
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
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    auto cal = [&](int b, int c) -> int {
        int deta = b * b - 4 * c;
        if(deta < 0)return 0;
        int x1 = (b - sqrt(deta)) / 2;
        int x2 = (b + sqrt(deta)) / 2;
        if(deta == 0)return mp[x1] * (mp[x1] - 1) / 2;
        if(x1 + x2 != b || x1 * x2 != c)return 0;
        return mp[x1] * mp[x2];
    };
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << cal(x, y) << ' ';
    }
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}