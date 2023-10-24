/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-24 14:59:49
 *
 * Problem: C. Number of Pairs
 * Contest: Codeforces - SMU Autumn 2023 Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481465/problem/C
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
const int N = 200010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    for(int i = x; i < N; i += lowbit(i))
        tr[i] += k;
}

int query(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve() {
    map<int,int> mp;
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    for(int i = 1; i <= n; i++) {
        int t=a[i];
        a[i] = lower_bound(ALL(b), a[i]) - b.begin() + 1;
        mp[a[i]]=t;
    }
    for(int i=1;i<=n;i++)add(i,a[i]);
    for(int i=1;i<=n;i++){
        int li=l-mp[a[i]];
        int ri=r-mp[a[i]];
        int x=lower_bound(ALL(b), li) - b.begin() + 1;
        int y=lower_bound(ALL(b), ri) - b.begin() + 1;
        
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}