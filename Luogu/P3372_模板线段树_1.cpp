/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-09 00:57:54
 *
 * Problem: P3372 【模板】线段树 1
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3372
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100010;

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
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    }

    void pushdown(int u) {
        if (tr[u].lazy) {
            tr[u << 1].sum += tr[u].lazy * (tr[u << 1].r - tr[u << 1].l + 1);
            tr[u << 1 | 1].sum += tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
            tr[u << 1].lazy += tr[u].lazy;
            tr[u << 1 | 1].lazy += tr[u].lazy;
            tr[u].lazy = 0;
        }
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, a[l], 0};
        if (l == r) return;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, T k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
            tr[u].lazy += k;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }

    T query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
        pushdown(u);
        T sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) sum += query(u << 1, l, r);
        if (r > mid) sum += query(u << 1 | 1, l, r);
        return sum;
    }
};

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int N) {
        n = N;
        sum1.resize(n + 1);
        sum2.resize(n + 1);
    }
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


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    BIT<int> bit(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.range_add(i, i, a[i]);
    }
    SegmentTree<int> ST(a, n);
    while(m--) {
        int op, l, r, k, x;
        cin >> op;
        if(op == 1) {
            cin >> l >> r >> k;
            bit.range_add(l, r, k);
        } else {
            cin >> l >> r;
            cout << bit.range_query(l, r) << endl;
        }
    }
    return 0;
}