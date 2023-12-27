/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-03 11:15:23
 *
 * Problem: C. Nested Segments
 * Contest: Codeforces - SMU Autumn 2023 Trial 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475593/problem/C
 * MemoryL: 256 MB
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
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 400010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

struct S {
    int l, r, id;
};
int n;
int tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    for(int i = x; i <= n * 2; i += lowbit(i))
        tr[i] += k;
}

int query(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i))res += tr[i];
    return res;
}


void solve() {
    cin >> n;
    vector<S> a(n + 1);
    vector<int> b, ans(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
        b.push_back(a[i].l);
        b.push_back(a[i].r);
    }
    sort(ALL(b));
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int i = 1; i <= n; i++) {
        a[i].l = lower_bound(ALL(b), a[i].l) - b.begin() + 1;
        a[i].r = lower_bound(ALL(b), a[i].r) - b.begin() + 1;
    }
    sort(a.begin() + 1, a.end(), [](S x, S y) {
        return x.r < y.r;
    });
    // for(auto [x, y, z] : a)cout << x << ' ' << y << endl;
    for(int i = 1; i <= n; i++) {
        int id = a[i].id;
        int l = a[i].l;
        ans[id] = i - 1 - query(l - 1);
        // debug2(query(l - 1), id);
        add(l, 1);
    }
    for(int i = 1; i <= n; i++)cout << ans[i] << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}