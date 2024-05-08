/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-07 15:49:54 ms
 *
 * Problem: G. Joy of Handcraft
 * Contest: Codeforces - SMU Spring 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/522675/problem/G
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

template <class T>
struct Seg {
    struct Node{ int l, r; T sum, add, mx; };
    vector<Node> tr; vector<T> a; int n;
    void init(int N) {
        n = N;
        tr.resize(n * 4);
        a.resize(n);
    }
    void add(int x, T k) {
        a[x] = k;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        if (tr[u].add) {
            tr[u << 1].sum += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
            tr[u << 1].mx = tr[u << 1].mx + tr[u].add;
            tr[u << 1 | 1].sum += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
            tr[u << 1 | 1].mx = tr[u << 1 | 1].mx + tr[u].add;
            tr[u << 1].add += tr[u].add;
            tr[u << 1 | 1].add += tr[u].add;
            tr[u].add = 0;
        }
    }
    Node merge(Node l, Node r) {
        Node t;
        t.sum = l.sum + r.sum;
        t.mx = max(l.mx, r.mx);
        return t;
    }
    void build(int u, int l,int r) {
        tr[u] = {l, r, a[l], 0, 0};
        if (l == r)return;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u,int l,int r,int k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
            tr[u].add += k;
            tr[u].mx += k;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    Node query(int u,int l,int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) return query(u << 1, l, r);
        if (r > mid) return  query(u << 1 | 1, l, r);
        return merge(tr[u << 1], tr[u << 1 | 1]);
    }
};

void solve(int t) {
    int n, m; cin >> n >> m;
    map<int, int> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        mp[x] = max(mp[x], x);
    }
    Seg<int> sg;
    sg.init(m + 1);
    sg.build(1, 1, m);
    for (auto [x, y] : mp) {
        for (int j = 1, k = 0; j <= m; j += x, k ++) {
            if (k % 2 == 0) {
                if (j + x - 1 <= m) sg.modify(1, j, j + x - 1, y);
                else sg.modify(1, j, m, y);
            }
        }
    }
    cout << "Case #" << t << ": ";
    for (int i = 1; i <= m; i ++) {
        cout << sg.query(1, i, i).mx << " \n"[i == m];
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1, t = 1;
    cin >> h_h;
    while (h_h--)solve(t ++);
    return 0;
}