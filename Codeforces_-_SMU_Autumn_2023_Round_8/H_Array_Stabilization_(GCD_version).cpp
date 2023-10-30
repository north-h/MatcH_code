/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-15 13:03:21
 *
 * Problem: H. Array Stabilization (GCD version)
 * Contest: Codeforces - SMU Autumn 2023 Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/479563/problem/H
 * MemoryL: 512 MB
 * TimeL:   4000 ms
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

int n, a[400010], GCD, ans, st[400010][20];
bool b[400010], bb;

int gcd(int x, int y) {
    if(!y) return x;
    return gcd(y, x % y);
}

int query(int i, int j) {   // ST 表查询
    int k = log2(j - i + 1);
    return gcd(st[i][k], st[j - (1 << k) + 1][k]);
}

void solve() {
    cin >> n, ans = bb = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i], b[i] = 0;
    for(int i = 1; i <= n; i++) a[i + n] = a[i], st[i][0] = st[i + n][0] = a[i];    // 破环为链
    for(int i = 1; i <= n; i++)
        if(a[i] != a[1]) {
            bb = 1;
            break;
        }
    if(!bb) {
        puts("0");
        return ;
    }
    GCD = a[1];
    for(int i = 2; i <= n; i++) GCD = gcd(GCD, a[i]);
    for(int j = 1; (1 << j) <= n + n; j++)    // 注意这里是 n + n，ST 表需要处理整条链
        for(int i = 1; i + (1 << j) - 1 <= n + n; i++)
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    for(int i = 1, L, R, mid; i <= n; i++) {
        L = i, R = n + i - 1;
        while(L < R) {
            int mid = (L + R) >> 1;
            if(query(i, mid) != GCD) L = mid + 1;
            else R = mid;
        }
        ans = max(ans, L - i);
    }
    printf("%d\n", ans);
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}