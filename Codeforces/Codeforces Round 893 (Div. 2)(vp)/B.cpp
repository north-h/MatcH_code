/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-16 20:33:25
 * Problem :
 * =====================================
 *                   _   _         _
 *  _ __   ___  _ __| |_| |__     | |__
 * | '_ \ / _ \| '__| __| '_ \    | '_ \
 * | | | | (_) | |  | |_| | | |   | | | |
 * |_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                           |_____|
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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m, 0);
    int res = 1;
    for(auto &i : a)cin >> i;
    sort(ALL(a));
    vector<int> b;
    bool ok = true;
    if(a[0] != 1)b.push_back(1);
    for(auto i : a)b.push_back(i);
    if(b.back() != n)ok = false;
    // for(auto i : b)cout << i << ' ';
    // cout << endl;
    for(int i = 1; i < b.size(); i++) {
        res += (b[i] - b[i - 1] + d - 1) / d;
    }
    if(!ok)res += (n - b[b.size() - 1]) / d;
    // cout << res << endl;
    int ans = 0;
    for(int i = 1; i < b.size() - 1; i++) {
        int x = (b[i] - b[i - 1] + d - 1) / d + (b[i + 1] - b[i] + d - 1) / d;
        int y = (b[i + 1] - b[i - 1] + d - 1) / d;
        // cout << x << ' ' << y << endl;
        if(y < x)ans++;
    }
    int len = b.size() - 1;
    int x = (n - b[len]) / d + (b[len] - b[len - 1] + d - 1) / d;
    int y = (n - b[len - 1]) / d;
    if(y < x)ans++;
    // if(ok) {
    //     int x = (b[m + 1] - b[m] + d - 1) / d ;
    //     int y = (b[m + 1] - b[m - 1] + d - 1) / d;
    //     if(y < x)ans++;
    // }
    if(!ans)cout << res << ' ' << m << endl;
    else cout << res - 1 << ' ' << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}