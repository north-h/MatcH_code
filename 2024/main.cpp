#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;

int a[N], n;

struct info {
    int ans1, la1, ra1, tot, ma1;
    int ans2, la2, ra2, ma2, ans;
};

info operator + (const info &l, const info &r) {
    info b;

    b.tot = l.tot + r.tot;
    b.la1 = max(l.la1, l.tot + r.la1);
    b.ra1 = max(r.ra1, r.tot + l.ra1);
    b.ma1 = max({l.ma1, r.ma1, l.ra1 + r.la1});
    b.ans1 = max({l.ans1, r.ans1, b.tot, b.la1, b.ra1, b.ma1});

    b.la2 = min(l.la2, l.tot + r.la2);
    b.ra2 = min(r.ra2, r.tot + l.ra2);
    b.ma2 = min({l.ma2, r.ma2, l.ra2 + r.la2});
    b.ans2 = min({l.ans2, r.ans2, b.tot, b.la2, b.ra2, b.ma2});

    return b;
}

struct node {
    info s;
} seg[N * 4];

void update(int id) {
    seg[id].s = seg[2 * id].s + seg[2 * id + 1].s;
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id].s = {a[l], a[l], a[l], a[l], a[l], a[l], a[l], a[l], a[l], a[l]};
    } else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}

info query(int id, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
        return seg[id].s;
    }
    int mid = (l + r) / 2;
    if (qr <= mid) {
        return query(id * 2, l, mid, ql, qr);
    } else if (ql > mid) {
        return query(id * 2 + 1, mid + 1, r, ql, qr);
    } else {
        return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << max(query(1, 1, n, l, r).ans1, abs(query(1, 1, n, l, r).ans2)) << "\n";
    }
    return 0;
}