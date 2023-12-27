/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-10 02:06:44
 *
 * Problem: 一个简单的整数问题
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/248/
 * MemoryL: 64 MB
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int n) : n(n), sum1(n + 1), sum2(n + 1) {}
    void add(int x, T k) {
        for(int i = x; i <= n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void range_add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);

    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    BIT<int> bit(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.range_add(i, i, a[i]);
    }
    while(q--) {
        char op;
        cin >> op;
        if(op == 'Q') {
            int x;
            cin >> x;
            cout << bit.range_query(x, x) << endl;
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            bit.range_add(l, r, k);
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}