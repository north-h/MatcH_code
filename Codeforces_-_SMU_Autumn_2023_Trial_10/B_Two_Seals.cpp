/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-06 10:13:45
 *
 * Problem: B. Two Seals
 * Contest: Codeforces - SMU Autumn 2023 Trial 10
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475598/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int n, A, B;
    cin >> n >> A >> B;
    vector<PII> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = a[i].fi, y = a[i].se;
        // debug2(x, y);
        for(int j = i + 1; j < n; j++) {
            int z = a[j].fi, w = a[j].se;
            // debug2(z, w);
            int x1 = x + z;
            int y1 = max(y, w);
            int x2 = max(x, z);
            int y2 = y + w;
            int x3 = x + w;
            int y3 = max(y, z);
            int x4 = max(x, w);
            int y4 = y + z;
            // debug2(x1, y1);
            // debug2(x2, y2);
            if(x1 <= A && y1 <= B || x2 <= A && y2 <= B || x3 <= A && y3 <= B || x4 <= A && y4 <= B || x1 <= B && y1 <= A || x2 <= B && y2 <= A || x3 <= B && y3 <= A || x4 <= B && y4 <= A) {
                ans = max(ans, x * y + z * w);
            }
            // debug1(ans);
        }
        // cout << endl;
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