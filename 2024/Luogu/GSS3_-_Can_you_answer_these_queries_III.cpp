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
#include <bits/stdc++.h>
#define ls num<<1
#define rs num<<1|1
using namespace std;
template<typename T>inline void read(T &FF) {
    T RR = 1; FF = 0; char CH = getchar();
    for (; !isdigit(CH); CH = getchar())if (CH == '-')RR = -1;
    for (; isdigit(CH); CH = getchar())FF = (FF << 1) + (FF << 3) + (CH ^ 48);
    FF *= RR;
}
template<typename T>void write(T x) {
    if (x < 0)putchar('-'), x *= -1;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
template<typename T>void writen(T x) {
    write(x);
    puts("");
}
const int MAXN = 5e4 + 10;
struct Tree {
    int sum, l, r, ans; //维护的4个量
} t[MAXN * 4];
int a[MAXN], f, x, y;
Tree pushup(Tree L, Tree R) {
    Tree z;
    z.sum = L.sum + R.sum; //和
    z.l = max(L.l, L.sum + R.l); //2种情况
    z.r = max(R.r, R.sum + L.r); //2种情况
    z.ans = max(max(L.ans, R.ans), L.r + R.l); //3种情况
    return z;
}
void build(int l, int r, int num) { //建树
    if (l == r) {
        t[num].sum = a[l];
        t[num].l = a[l];
        t[num].r = a[l];
        t[num].ans = a[l]; //边界初始化
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    t[num] = pushup(t[ls], t[rs]); //pushup
}
void change(int l, int r, int num) { //单点修改
    if (l == r) {
        t[num].sum = y;
        t[num].l = y;
        t[num].r = y;
        t[num].ans = y; //边界初始化
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)change(l, mid, ls);
    else change(mid + 1, r, rs);
    t[num] = pushup(t[ls], t[rs]);
}
Tree query(int x, int y, int num, int l, int r) {
    if (x <= l && r <= y)return t[num];
    int mid = (l + r) >> 1;
    if (y <= mid)return query(x, y, ls, l, mid); //右区间和查询区间没有交，答案当然在左区间
    if (mid < x)return query(x, y, rs, mid + 1, r); //左区间和查询区间没有交，答案当然在右区间
    return pushup(query(x, mid, ls, l, mid), query(mid + 1, y, rs, mid + 1, r)); //是不是很简洁？
}
int main() {
    int n, T;
    read(n);
    for (int i = 1; i <= n; i++)read(a[i]);
    build(1, n, 1);
    read(T);
    while (T--) {
        read(f); read(x); read(y);
        if (f == 0)change(1, n, 1);
        else writen(query(x, y, 1, 1, n).ans);
    }
    return 0;
}