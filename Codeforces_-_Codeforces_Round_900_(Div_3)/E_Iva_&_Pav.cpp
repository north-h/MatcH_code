/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-26 22:36:50
 *
 * Problem: E. Iva & Pav
 * Contest: Codeforces - Codeforces Round 900 (Div. 3)
 * URL:     https://codeforces.com/contest/1878/problem/E
 * MemoryL: 256 MB
 * TimeL:   5000 ms
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
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 200010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

struct Node {
    int l, r, sum, lazy;
} tr[N * 4];

int a[N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum & tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
    tr[u] = {l, r, a[l]};
    if (l == r)return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int sum = -1;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)sum = query(u << 1, l, r);
    if (r > mid) {
        if(sum != -1)sum &= query(u << 1 | 1, l, r);
        else sum = query(u << 1 | 1, l, r);
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 32>> s(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        // for (int j = 0; j < 30; j++) {
        //     if (x >> j & 1)s[i][30 - j] = 1;
        //     else s[i][30 - j] = 0;
        // }
    }
    build(1, 1, n);
    // for(int j = 1; j <= 30; j++) {
    //     for(int i = 1; i <= n; i++) {
    //         s[i][j] += s[i - 1][j];
    //     }
    // }
    // auto check = [&](int l, int r, int goal) {
    //     int res = 0;
    //     for(int i = 1; i <= 30; i++) {
    //         int cnt = s[r][i] - s[l - 1][i];
    //         if(r - l + 1 == cnt)res += (1 << (30 - i));
    //     }
    //     return res >= goal;
    // };
    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;
        int l = x, r = n, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (query(1, x, mid) >= k)l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}