/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-19 19:02:58
 *
 * Problem: 小红的01连续段
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/69695/B
 * MemoryL: 524288 MB
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
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<PCI> a;
    int cnt = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1])cnt++;
        else {
            if(s[i - 1] == '?')a.push_back({'?', cnt});
            else if(s[i - 1] == '1')a.push_back({'1', cnt});
            else a.push_back({'0', cnt});
            cnt = 1;
        }
    }
    if(s.back() == '?')a.push_back({'?', cnt});
    else if(s.back() == '1')a.push_back({'1', cnt});
    else a.push_back({'0', cnt});
    // for(auto [x, y] : a)cout << x << ' ' << y << endl;
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        // if(i == 0) {
        //     if(a[i + 1].fi == '?')ans = max(ans, a[i].se + a[i + 1].se);
        //     else ans = max(ans, a[i].se);
        // } else if(i == a.size() - 1) {
        //     if(a[i - 1].fi == '?')ans = max(ans, a[i].se + a[i - 1].se);
        //     else ans = max(ans, a[i].se);
        // } else {
        int res = a[i].se;
        if(a[i + 1].fi == '?' && i + 1 < a.size())res += a[i + 1].se;
        if(a[i - 1].fi == '?' && i - 1 >= 0)res += a[i - 1].se;
        ans = max(res, ans);
        // }
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}