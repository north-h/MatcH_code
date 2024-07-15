#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define int long long
const int N = 500010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct Node {
    int l, r, lazy;
    long long mx, lmx, rmx, sum, mn, lmn, rmn;
} tr[N * 4];
int a[N];

Node merge(Node t, Node l, Node r) {
    t.lmx = max(l.lmx, l.sum + r.lmx);
    t.rmx = max(r.rmx, r.sum + l.rmx);
    t.sum = l.sum + r.sum;
    t.mx = max(max(l.mx, r.mx), l.rmx + r.lmx);

    t.lmn = min(l.lmn, l.sum + r.lmn);
    t.rmn = min(r.rmn, r.sum + l.rmn);
    t.sum = l.sum + r.sum;
    t.mn = min(min(l.mn, r.mn), l.rmn + r.lmn);
    return t;
}
void pushup(int u) {
    tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void build(int u, int l, int r) {
    tr[u] = {l, r, 0, a[l], a[l], a[l], a[l], a[l], a[l], a[l]};
    if (l >= r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    if (l > mid) return query(u << 1 | 1, l, r);
    Node t = merge(t, query(u << 1, l, r), query(u << 1 | 1, l, r));
    return t;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q; cin >> q;
    for (int i = 1; i <= q; i ++) {
        int l, r; cin >> l >> r;
        long long ans = max(query(1, l, r).mx, abs(query(1, l, r).mn));
        cout << ans << '\n';
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}