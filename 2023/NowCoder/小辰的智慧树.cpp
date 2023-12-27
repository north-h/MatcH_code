/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-19 21:17:57
 *
 * Problem: 小辰的智慧树
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/69791/E
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
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 1000010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int s[N];

void solve() {
    int n, m;
    cin >> n >> m;
    int mx = 0;
    for(int i = 0, r, l; i < n; i++) {
        cin >> r >> l;
        s[l + 1]++;
        s[r + 1]--;
        mx = max(mx, r);
    }
    for(int i = 1; i <= mx; i++)s[i] += s[i - 1];
    ll ans = 0;
    for(int i = mx; i >= 1; i--) {
        if(m - s[i] >= 0) {
            int res = s[i] * (i * 2 - 1);
            ans += res;
            m -= s[i];
        } else {
            ans += m * (i * 2 - 1);
            break;
        }
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