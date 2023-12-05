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

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 200010;
const int M = 1910;

using namespace std;

template<class T>
struct SegmentTree {
    struct Node {
        int l, r;
        T sum, lazy;
    };

    vector<Node> tr;
    vector<T> a;

    SegmentTree(const vector<T> &arr, const int n) {
        tr.resize(n * 4);
        a = arr;
        build(1, 1, n);
    }
    void pushup(int u) {
        tr[u].sum = tr[u << 1].sum & tr[u << 1 | 1].sum;
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, a[l], 0};
        if (l == r) return;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int x, int k) {
        if (tr[u].l == tr[u].r) {
            tr[u].sum += k;
            return;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, k);
        else modify(u << 1 | 1, x, k);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
        int sum = -1;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) sum &= query(u << 1, l, r);
        if (r > mid) sum &= query(u << 1 | 1, l, r);
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<array<int, 32>> s(n + 1);
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    SegmentTree<int> ST(a, n);
    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;
        int l = x, r = n, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (ST.query(1, x, mid) >= k)l = mid + 1, ans = mid;
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