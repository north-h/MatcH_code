/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-27 20:03:02
 *
 * Problem: E. Look Back
 * Contest: Codeforces - Codeforces Round 905 (Div. 3)
 * URL:     https://codeforces.com/contest/1883/problem/E
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll last = 0;
    for(int i = 2; i <= n; i++) {
        int cnt = 0;
        if(a[i] == a[i - 1]) {
            ans += last;
            continue;
        } else if(a[i] > a[i - 1]) {
            while(a[i - 1] * (1ll << cnt) <= a[i]) {
                cnt++;
            }
            cnt--;
            last = max(0ll, last - cnt);
        } else {
            while(a[i - 1] > a[i] * (1ll << cnt)) {
                cnt++;
            }
            last = last + cnt;
        }
        ans += last;
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