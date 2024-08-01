/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-08-01 16:47:19 ms
 *
 * Problem: B. Infinite Binary String
 * Contest: Codeforces - The 19th Southeast University Programming Contest (Summer)
 * URL:     https://codeforces.com/gym/105013/problem/B
 * MemoryL: 2048 MB
 * TimeL:   8000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

template<class T>
struct SegmentTree {
#define ls tr[u].lid
#define rs tr[u].rid
    struct Info {
        int lid, rid, l, r;
        int ok = -1;
        T sum = 0;
    };
    int n, idx = 0, root = 0;
    vector<Info> tr;
    SegmentTree(int n) {
        tr.resize(n * 2 + 1);
    };
    Info merge(Info &u, Info l, Info r) {
        u.sum = l.sum + r.sum;
        return u;
    }
    void build(int &u, int l, int r) {
        if (u) return ;
        u = ++ idx;
        tr[u].l = l, tr[u].r = r;
        
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[ls], tr[rs]);
    }
    void calc(Info &u, int ok) {
        u.ok = ok;        
    }
    void pushdown(int u) {
        int add = tr[u].add;
        if (!add) return ;
        calc(tr[ls], add);
        calc(tr[rs], add);
        tr[u].add = 0;
    }
    void modify(int &u, int l, int r, int L, int R, int ok) {
        build(u, l, r);
        if (l >= L && r <= R) {
            calc(tr[u], ok);
            return ;
        }
        pushdown(u);
        int mid = l + r >> 1;
        if (L <= mid) modify(ls, l, mid, L, R, ok);
        if (R > mid) modify(rs, mid + 1, r, L, R, ok);
        pushup(u);
    }
    Info query(int &u, int l, int r, int L, int R) {
        build(u, l, r);
        if (l >= L && r <= R) return tr[u];
        pushdown(u);
        int mid = l + r >> 1;
        if (R <= mid) return query(ls, l, mid, L, R);
        if (L > mid) return query(rs, mid + 1, r, L, R);
        Info t = merge(t, query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
        return t;
    }
};

void solve() {
    SegmentTree<int> sg(N);
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        char op; cin >> op;
        int x1, x2, k;
        if (op == '+') {
            cin >> x1 >> x2;
        } else if (op == '-') {
            cin >> x1 >> x2;
        } else {
            cin >> k;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}