/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-21 12:49:22
 *
 * Problem: A. Liebig's Barrels
 * Contest: Codeforces - SMU Autumn 2023 Trial 21
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/480222/problem/A
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n * k);
    ll sum = 0;
    for(auto &i : a)cin >> i, sum += i;
    vector<int> b;
    int mn = *min_element(ALL(a));

    for(auto i : a) {
        if(abs(i - mn) <= l)b.push_back(i);
    }
    sort(ALL(b));
    // for(auto i : b)cout << i << ' ';
    // cout << endl;
    if(b.size() < n)cout << 0 << endl;
    else if(n == 1) {
        cout << mn << endl;
    } else if(k == 1) {
        cout << sum << endl;
    } else {
        ll ans = 0;
        int x = (b.size() - n) / (k - 1);
        int y = (b.size() - n) % (k - 1);
        // debug2(x, y);
        int pos = 0;
        for(int j = 0; j < x; j++, pos += k) {
            ans += b[pos];
        }
        // debug1(pos);
        if(y != 0)ans += b[pos], pos += y + 1;
        for(int i = pos; i < b.size(); i++) {
            ans += b[i];
        }
        cout << ans << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}