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
struct Seg{
    struct Node{ 
        int l, r;
        T sum, lazy;
    };

    vector<Node> tr;
    vector<T> a;
    int n;

    Seg() {};

    void init(int N) {
        n = N;
        tr.resize(n * 4);
        a.resize(n);
    }

    void add(int x, T k) {
        a[x] = k;
    }

    void pushup(int u) {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    }

    void pushdown(int u) {
        if (tr[u].lazy) {
            tr[u << 1].sum += tr[u].lazy * (tr[u << 1].r - tr[u << 1].l + 1);
            tr[u << 1 | 1].sum += tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
            tr[u << 1].lazy += tr[u].lazy;
            tr[u << 1 | 1].lazy += tr[u].lazy;
            tr[u].lazy = 0;
        }
    }

    void build(int u, int l,int r) {
        tr[u] = {l, r, a[l], 0};
        if (l == r)return;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    //区间修改
    void modify(int u,int l,int r,int k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
            tr[u].lazy += k;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    //单点修改
    void modify(int u,int x,int k) {
        if (tr[u].l == tr[u].r) {
            tr[u].sum += k;
            return;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)modify(u << 1, x, k);
        else modify(u << 1 | 1, x, k);
    }
    //区间查询
    T query(int u,int l,int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
        pushdown(u);
        T sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)sum += query(u << 1, l, r);
        if (r > mid) sum += query(u << 1 | 1, l, r);
        return sum;
    }
    //单点查询
    T query(int u,int x) {
        if (tr[u].l == tr[u].r)return tr[u].sum;
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)return query(u << 1, x);
        else return query(u << 1 | 1, x);
    }
};

void solve() {
    int a, b; cin >> a >> b;
    cout << a + b << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}