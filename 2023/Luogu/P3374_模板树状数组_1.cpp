/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-30 22:57:54
 *
 * Problem: P3374 【模板】树状数组 1
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3374
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */
#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int n, q, op, l, r, x;
// int a[MAXN];
// int c1[MAXN], c2[MAXN];
// int lowbit(int x) {
//     return x & -x;
// }
// void update(int x, int k) {
//     int t = x;
//     for(; x <= n; x += lowbit(x)) {
//         c1[x] += k;
//         c2[x] += k * (t - 1);
//     }
// }
// int query(int x) {
//     int ans = 0, t = x;
//     for(; x >= 1; x -= lowbit(x))
//         ans += c1[x] * t - c2[x];
//     return ans;
// }

template<class T>
struct SegmentTree {
    struct Node {
        int l, r;
        T sum, lazy;
    };

    vector<Node> tr;
    vector<T> a;

    SegmentTree(const vector<T> &arr, int n) {
        tr.resize(n * 4);
        a = arr;
        build(1, 1, a.size() - 1);
    }
    void pushup(int u) {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
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

    T query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
        T sum =  0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) sum = query(u << 1, l, r);
        if (r > mid) sum += query(u << 1 | 1, l, r);
        return sum;
    }
};

int main() {
    scanf("%d%d", &n, &q);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        // update(i, a[i] - a[i - 1]);
    }
    SegmentTree<int> ST(a, N);
    // cout << query(5) - query(1) << endl;;
    for(int i = 1; i <= q; i++) {
        scanf("%d", &op);
        if(op == 1) {
            int x, k;
            cin >> x >> k;
            ST.modify(1, x, k);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ST.query(1, l, r) << endl;
        }
    }
    return 0;
}
