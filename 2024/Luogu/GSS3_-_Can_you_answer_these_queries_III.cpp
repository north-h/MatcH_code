/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-05-04 18:33:48 ms
 *
 * Problem: GSS3 - Can you answer these queries III
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/SP1716
 * MemoryL: 1 MB
 * TimeL:   330000 ms
 * =========================================================
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ls u<<1
#define rs u<<1|1
const int N = 500010;
int n, m, a[N];
struct Tree { //线段树
    int l, r;
    //区间和,最大左子段和,最大右子段和,最大子段和
    int sum, lmx, rmx, mx;
} tr[N * 4];

void pushup(Tree &u, Tree l, Tree r) {
    u.sum = l.sum + r.sum;
    u.lmx = max(l.lmx, l.sum + r.lmx);
    u.rmx = max(r.rmx, r.sum + l.rmx);
    u.mx = max(max(l.mx, r.mx), l.rmx + r.lmx);
}
void build(int u, int l, int r) { //建树
    tr[u] = {l, r, a[r], a[r], a[r], a[r]};
    if (l == r) return;
    int m = l + r >> 1;
    build(ls, l, m);
    build(rs, m + 1, r);
    pushup(tr[u], tr[ls], tr[rs]);
}
void change(int u, int x, int v) { //点修
    if (tr[u].l == tr[u].r) {
        tr[u] = {x, x, v, v, v, v};
        return;
    }
    int m = tr[u].l + tr[u].r >> 1;
    if (x <= m) change(ls, x, v);
    else change(rs, x, v);
    pushup(tr[u], tr[ls], tr[rs]);
}
Tree query(int u, int x, int y) { //区查
    if (x <= tr[u].l && tr[u].r <= y) return tr[u];
    int m = tr[u].l + tr[u].r >> 1;
    if (y <= m) return query(ls, x, y);
    if (x > m) return query(rs, x, y);
    Tree T; //开一个临时节点，存储拼凑结果
    pushup(T, query(ls, x, m), query(rs, m + 1, y));
    return T;
}
// Tree query(int u,int x,int y){ //区查
//   if(x>tr[u].r||y<tr[u].l)
//     return {tr[u].l,tr[u].r,0,-1e9,-1e9,-1e9};
//   if(x<=tr[u].l && tr[u].r<=y) return tr[u];
//   Tree T; //开一个临时节点，存储拼凑结果
//   pushup(T,query(ls,x,y),query(rs,x,y));
//   return T;
// }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    cin >> m;
    while (m--) {
        int k, x, y; scanf("%d%d%d", &k, &x, &y);
        if (k == 1) {
            if (x > y) swap(x, y);
            printf("%d\n", query(1, x, y).mx);
        } else change(1, x, y);
    }
    return 0;
}