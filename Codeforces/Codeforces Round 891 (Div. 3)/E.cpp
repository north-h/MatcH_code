/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-10 18:01:34
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(ALL(a));
    // for(int i = 0; i < n; i++)cout << a[i].fi << ' ';
    // cout << endl;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i].fi - a[0].fi + 1;
    }
    ans[a[0].se] = sum;
    for(int i = 1; i < n; i++) {
        sum += (ll)(a[i].fi - a[i - 1].fi) * max(0, i - 2 + 1);
        sum -= (ll)(a[i].fi - a[i - 1].fi) * (n - i - 1);
        ans[a[i].se] = sum;
    }
    for(auto i : ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}