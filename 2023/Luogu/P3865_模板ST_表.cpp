/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-15 01:34:36
 *
 * Problem: P3865 【模板】ST 表
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3865
 * MemoryL: 125 MB
 * TimeL:   800000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 110;

using namespace std;

template <typename T>
T read() {
    T x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}


template<class T>
struct RMQ {
    T n;
    vector<T> arr;
    vector<vector<T>> f, g;
    vector<int> lg2;
    RMQ(const vector<T> &a) :
        n(a.size()), arr(a),
        f(n, vector<T>(log2(n) + 1)),
        g(n, vector<T>(log2(n) + 1)),
        lg2(n + 1) {
        init();
    }
    void init() {
        lg2[0] = -1;
        for(int i = 1; i <= n; i ++)
            lg2[i] = lg2[i >> 1] + 1;
        for (int i = 0; i < n; i++) {
            f[i][0] = arr[i];
            g[i][0] = arr[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query_max(int l, int r) {
        int k = lg2[r - l + 1];
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }

    T query_min(int l, int r) {
        int k = lg2[r - l + 1];
        return min(g[l][k], g[r - (1 << k) + 1][k]);
    }
};


void solve() {
    int n, q;
    // cin >> n >> q;
    n = read<int>();
    q = read<int>();
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        // cin >> a[i];
        a[i] = read<int>();
    }
    RMQ<int> rmq(a);
    while(q--) {
        int l, r;
        // cin >> l >> r;
        l = read<int>();
        r = read<int>();
        cout << rmq.query_max(l, r) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}