// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

template<class T>
struct Seg {
    struct Node {int l, r; T add, mul, mx;};
    vector<Node> tr; vector<T> a; int N;
    Seg(int n) { int N = n + 1; tr.resize(N * 4); a.resize(N); }
    Node merge(Node u, Node ls, Node rs) {
        u.mx = max(ls.mx, rs.mx);
        return u;
    }
    void calc(Node &u, int add, int mul) {
        int lvl = u.r - u.l + 1;
        u.mx = u.mx * mul + lvl * add;
        u.add = u.add * mul + add;
        u.mul = u.mul * mul;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        auto [_, __, a, m, _1] = tr[u];
        calc(tr[u << 1], a, m);
        calc(tr[u << 1 | 1], a, m);
        tr[u].mul = 1;
        tr[u].add = 0;
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 1, a[l]};
        if (l == r) return ;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T add, T mul) {
        if (tr[u].l >= l && tr[u].r <= r) {
            calc(tr[u], add, mul);
            return ;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, add, mul);
        if (r > mid) modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        Node t = merge(t, query(u << 1, l, r), query(u << 1 | 1, l, r));
        pushup(u);
        return t;
    }
};


void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), s(n + 1);
    Seg<int> sg(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sg.a[i] = a[i];
        s[i] = s[i - 1] + a[i];
    }
    sg.build(1, 1, n);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            int sum = s[j] - s[i - 1];
            int mx = sg.query(1, i, j).mx;
            if (mx >= sum) ans ++;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}