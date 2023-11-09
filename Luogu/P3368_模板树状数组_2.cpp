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

using namespace std;

const int N = 100010;

int tr1[N], tr2[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int k) {
    for(int i = x; i < N; i += lowbit(i)) {
        tr1[i] += k;
        // tr2[i] += k * x;
    }
}

void range_add(int l, int r, int x) {
    add(l, x);
    add(r + 1, -x);
}

int query(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) {
        // res += (x + 1) * tr2[i] - tr1[i];
        res += tr1[i];
    }
    return res;
}

int range_query(int l, int r) {
    return query(r) - query(l);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++) {
        b[i] = a[i] - a[i - 1];
        add(i, b[i]);
    }
    while(m--) {
        int op, l, r, k, x;
        cin >> op;
        if(op == 1) {
            cin >> l >> r >> k;
            range_add(l, r, k);
        } else {
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}