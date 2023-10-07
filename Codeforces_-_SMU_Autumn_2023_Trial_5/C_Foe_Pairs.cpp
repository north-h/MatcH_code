/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-01 09:54:49
 *
 * Problem: C. Foe Pairs
 * Contest: Codeforces - SMU Autumn 2023 Trial 5
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475590/problem/C
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
const int N = 300010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

// int a[N], pos[N], b[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1, n), pos(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    while(m--) {
        int l, r;
        cin >> l >> r;
        if(pos[l] > pos[r])swap(l, r);
        b[pos[l]] = min(b[pos[l]], pos[r] - 1);
    }
    for(int i = n - 1; i >= 1; i--)b[i] = min(b[i], b[i + 1]);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += b[i] - i + 1;
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