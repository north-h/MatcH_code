// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define PII pair<int, int>
// #define int long long
const int N = 200010, INF = 0x3f3f3f3f;

using namespace std;

int n, q;
int a[N];
struct seg_Tree {
#define lc p << 1
#define rc p << 1 | 1
    struct nod {
        int l, r, len, st, tag1, tag2;
    } t[N << 2];
    int ql, qr, qlen, qst, qp;
    nod merge(nod a, nod b) {
        nod res;
        res.l = a.l, res.r = b.r;
        res.len = __gcd(a.len, b.len);
        res.tag1 = res.tag2 = 0;
        return res;
    }
    void pushup(int p) {
        t[p] = merge(t[lc], t[rc]);
    }
    void bd(int p, int l, int r) {
        t[p] = {l, r, 0, 0, 0, 0};
        if (l == r) return ;
        int mid = l + r >> 1;
        bd(lc, l, mid);
        bd(rc, mid + 1, r);
    }
    void pushdn(int p) {
        if (t[p].tag1) {
            t[lc].len = t[p].tag1;
            t[lc].tag1 = t[p].tag1;
            t[rc].len = t[p].tag1;
            t[rc].tag1 = t[p].tag1;
            t[p].tag1 = 0;
        }
        if (t[p].tag2) {
            t[lc].st = t[p].tag2;
            t[lc].tag2 = t[p].tag2;
            t[rc].st = t[p].tag2;
            t[rc].tag2 = t[p].tag2;
            t[p].tag2 = 0;
        }
    }
    void update(int p) {
        if (ql <= t[p].l && qr >= t[p].r) {
            t[p].len = qlen, t[p].st = qst;
            t[p].tag1 = qlen, t[p].tag2 = qst;
            return ;
        }
        int mid = t[p].l + t[p].r >> 1;
        pushdn(p);
        if (ql <= mid) update(lc);
        if (qr > mid) update(rc);
        pushup(p);
    }
    void updt(int l, int r, int len, int st) {
        ql = l, qr = r;
        qlen = len, qst = st;
        update(1);
    }
    nod query(int p) {
        if (qp == t[p].l && qp == t[p].r) return t[p];
        int mid = t[p].l + t[p].r >> 1;
        pushdn(p);
        if (qp <= mid) return query(lc);
        if (qp > mid) return query(rc);
    }
    PII ask(int p) {
        qp = p;
        nod res = query(1);
        return {res.len, res.st};
    }
    nod query2(int p) {
        if (ql <= t[p].l && qr >= t[p].r) return t[p];
        int mid = t[p].l + t[p].r >> 1;
        pushdn(p);
        if (ql > mid) return query2(rc);
        if (qr <= mid) return query2(lc);
        return merge(query2(lc), query2(rc));
    }
    PII ask2(int l, int r) {
        ql = l, qr = r;
        nod res = query2(1);
        return {res.len, res.st};
    }
} tr;
int yz[N];
inline void ans() {
    auto [len, st] = tr.ask(n);
    if (len == n) { cout << len << endl; return ;}
    cout << yz[tr.ask2(1, n - len).first] << endl;
}


void solve() {
    cin >> n >> q;
    int cnt = 0;
    tr.bd(1, 1 , n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] >= a[i - 1]) cnt ++;
        else tr.updt(i - cnt, i - 1, cnt, i - cnt), cnt = 1;
    }
    tr.updt(n - cnt + 1, n, cnt, n - cnt + 1);
    // for (int i = 1; i <= n; i ++) cout << tr.ask(i).first << ' ';
    // cout << '\n';
    // cout << tr.t[1].len << '\n';
    ans();
    while (q --) {
        int p, v; cin >> p >> v;
        a[p] = v;
        // for (int i = 1; i <= n; i ++) cout << a[i] << ' ';
        // cout << '\n';
        auto [nlen, nst] = tr.ask(p);
        if (nlen == 1) {
            if (p - 1 > 0 && a[p] >= a[p - 1]) {
                auto [llen, lst] = tr.ask(p - 1);
                tr.updt(lst, p, llen + 1, lst);
            } else if (p + 1 <= n && a[p] <= a[p + 1]) {
                auto [llen, lst] = tr.ask(p + 1);
                tr.updt(p, p + llen, llen + 1, p);
            }
        } else if (p == nst) {
            if (a[p] <= a[p + 1]) {
                if (p - 1 > 0 && a[p] >= a[p - 1]) {
                    auto [llen, lst] = tr.ask(p - 1);
                    tr.updt(lst, p + nlen - 1, nlen + llen, lst);
                }
            } else if (p - 1 > 0 && a[p] >= a[p - 1]) {
                auto [llen, lst] = tr.ask(p - 1);
                tr.updt(lst, p, llen + 1, lst);
                tr.updt(p + 1, p + nlen - 1, nlen - 1, p + 1);
            } else {
                tr.updt(p, p, 1, p);
                tr.updt(p + 1, p + nlen - 1, nlen - 1, p + 1);
            }
        } else if (p == nst + nlen - 1) {
            if (a[p] >= a[p - 1]) {
                if (p + 1 <= n && a[p] <= a[p + 1]) {
                    auto [llen, lst] = tr.ask(p + 1);
                    tr.updt(nst, p + 1 + llen - 1, nlen + llen, nst);
                }
            } else if (p + 1 <= n && a[p] <= a[p + 1]) {
                tr.updt(nst, p - 1, nlen - 1, nst);
                auto [llen, lst] = tr.ask(p + 1);
                tr.updt(p, p + llen, llen + 1, p);
            } else {
                tr.updt(p, p, 1, p);
                tr.updt(nst, p - 1, nlen - 1, nst);
            }
        } else {
            if (a[p] >= a[p - 1] && a[p] <= a[p + 1]) {
                ans();
                continue;
            }
            if (a[p] > a[p + 1]) {
                tr.updt(nst, p, p - nst + 1, nst);
                tr.updt(p + 1, nst + nlen - 1, nlen - (p - nst + 1), p + 1);
            } else if (a[p] < a[p - 1]) {
                tr.updt(nst, p - 1, p - nst, nst);
                tr.updt(p, nst + nlen - 1, nlen - (p - nst), p);
            }
        }
        ans();
    }
    // for (int i = 1; i <= n; i ++) cout << tr.ask(i).first << ' ';
    // cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    for (int i = 1; i <= 200000; i ++) {
        for (int j = i; j <= 200000; j += i) yz[j] ++;
    }
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}