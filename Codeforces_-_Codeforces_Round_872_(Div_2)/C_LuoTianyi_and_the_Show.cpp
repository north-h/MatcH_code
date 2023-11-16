/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-16 19:35:24
 *
 * Problem: C. LuoTianyi and the Show
 * Contest: Codeforces - Codeforces Round 872 (Div. 2)
 * URL:     https://codeforces.com/contest/1825/problem/C
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
    int n, m;
    cin >> n >> m;
    vector<int> a, b, c, vis(m + 1);
    map<int, int> mp;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        if(x == -1) {
            a.push_back(x);
        } else if(x == -2) {
            b.push_back(x);
        } else {
            c.push_back(x);
            mp[x]++;
        }
    }
    int aa = a.size(), bb = b.size(), cc = c.size();
    int ans = 0;
    if(mp.size() == 0)cout << max(aa, bb) << endl;
    else if(mp.size() == 1) {
        if(aa == 0 && bb == 0) {
            cout << 1 << endl;
        } else if(aa == 0 && bb) {
            cout << min(m, bb + 1) << endl;
        } else if(aa && bb == 0) {
            cout << min(m, aa + 1) << endl;
        } else {
            int l = c[0] - 1;
            int r = m - c[0];
            int x = l - aa;
            int y = r - bb;
            int ans = 1 + min(l, aa) + min(r, bb);
            if(x > 0 && y > 0);
            else if(x >= 1 && y < 0 || y >= 0 || x < 0)ans++;
            cout << min(ans, m) << endl;
        }
    } else cout << min(m, (int)mp.size() + aa + bb) << endl;
    // }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}