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

#include<iostream>
#include<cstdio>
#define MAXN 1000010
using namespace std;
int n, q, op, l, r, x;
int a[MAXN];
int c1[MAXN], c2[MAXN];
int lowbit(int x) {
    return x & -x;
}
void update(int x, int k) {
    int t = x;
    for(; x <= n; x += lowbit(x)) {
        c1[x] += k;
        c2[x] += k * (t - 1);
    }
}
int query(int x) {
    int ans = 0, t = x;
    for(; x >= 1; x -= lowbit(x))
        ans += c1[x] * t - c2[x];
    return ans;
}
int main() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        update(i, a[i] - a[i - 1]);
    }
    // cout << query(5) - query(1) << endl;;
    for(int i = 1; i <= q; i++) {
        scanf("%d", &op);
        if(op == 1) {
            int x, k;
            cin >> x >> k;
            update(x, k);
            update(x + 1, -k);
        } else {
            int l, r;
            cin >> l >> r;
            printf("%d\n", query(r) - query(l - 1));
        }
    }
    return 0;
}
