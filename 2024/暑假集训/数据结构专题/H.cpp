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
    struct Node {int l, r; T mx, k;};
    vector<Node> tr; vector<T> a; int n;
    Seg(int N) { n = N + 1; tr.resize(n * 4); a.resize(n); }
    void pushup(int u) {
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }
    void build(int u, int l, int r, int m, int k) {
        tr[u] = {l, r, m, k};
        if (l == r) return ;
        int mid = l + r >> 1;
        build(u << 1, l, mid, m, k);
        build(u << 1 | 1, mid + 1, r, m, k);
        pushup(u);
    }
    void modify(int u, int l, int r, T k) {
        // debug1(u);
        // debug2(tr[u].l, tr[u].r);
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].mx -= k;
            tr[u].k --;
            if (!tr[u].k) tr[u].mx = 0;
            return ;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    int query_pos(int u, int l, int r, int x) {
        if (tr[u].l == tr[u].r) return tr[u].l;
        int mid = tr[u].l + tr[u].r >> 1, pos;
        // debug2(u, mid);
        // debug2(tr[u].l, tr[u].r);
        if (tr[u << 1].mx >= x) pos = query_pos(u << 1, l, r, x);
        else pos = query_pos(u << 1 | 1, l, r, x);
        pushup(u);
        return pos;
    }
    int query_mx(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
        int mid = tr[u].l + tr[u].r >> 1, mx = 0;
        if (l <= mid) mx = query_mx(u << 1, l, r);
        if (r > mid) mx = max(mx, query_mx(u << 1 | 1, l, r));
        pushup(u);
        return mx;
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    Seg<int> sg(n + 1);
    sg.build(1, 1, n, m, k);
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (sg.query_mx(1, 1, n) < x) {
            cout << -1 << '\n';
            continue;
        }
        int pos = sg.query_pos(1, 1, n, x);
        cout << pos << '\n';
        sg.modify(1, pos, pos, x);
        // for (int i = 1; i <= n; i ++) {
        //     cout << sg.query_mx(1, i , i) << ' ';
        // }
        // cout << '\n';
        // cout << "-------------------------" << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}