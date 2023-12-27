/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-10 00:07:18
 *
 * Problem: D2. Set To Max (Hard Version)
 * Contest: Codeforces - Codeforces Round 914 (Div. 2)
 * URL:     https://codeforces.com/contest/1904/problem/D2
 * MemoryL: 256 MB
 * TimeL:   4000 ms
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
    int n;
    cin >> n;
    vector<int>a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    RMQ<int> A(a), B(b);
    vector<PII> t;
    for(int i = 1; i <= n; i++) {
        if(a[i] > b[i]) {
            cout << "NO" << endl;
            return ;
        }
        if(a[i] != b[i])t.push_back({i, b[i]});
    }
    for(auto [x, y] : t) {
        int  ans = 0;
        int l = x + 1, r = n;
        while(l <= r) {
            int mid = l + r >> 1;
            if(A.query_max(x, mid) == y) {
                if(B.query_min(x, mid) >= y) {
                    ans = 1;
                    break;
                } else r = mid - 1;
            } else if(A.query_max(x, mid) > y) {
                r = mid - 1;
            } else l = mid + 1;
        }
        l = 1, r = x - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(A.query_max(mid, x) == y) {
                if(B.query_min(mid, x) >= y) {
                    ans = 1;
                    break;
                } else l = mid + 1;
            } else if(A.query_max(mid, x) > y) {
                l = mid + 1;
            } else r = mid - 1;
        }
        if(ans == 0) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}