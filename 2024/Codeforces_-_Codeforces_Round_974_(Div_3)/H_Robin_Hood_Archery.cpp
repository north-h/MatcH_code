/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-22 01:48:32
 *
 * Problem: H. Robin Hood Archery
 * Contest: Codeforces - Codeforces Round 974 (Div. 3)
 * URL:     https://codeforces.com/contest/2014/problem/H
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 2000100, INF = 0x3f3f3f3f;

using namespace std;

struct S {
    int l, r, id;
} b[N];

int a[N], belong[N], n, m, now, ans[N], cnt[N], cv;

void add(int p) {
    if (!cnt[a[p]]) now ++;
    cnt[a[p]] ++;
    if (cnt[a[p]] % 2 == 0) cv --;
    else cv ++;
}

void del(int p) {
    cnt[a[p]] --;
    if (!cnt[a[p]]) now --;
    if (cnt[a[p]] % 2 == 0) cv --;
    else cv ++;
}

void solve() {
    cin >> n >> m;
    int sz = sqrt(n), block = (n + sz - 1) / sz;
    for (int i = 1; i <= n; i ++) {
        belong[i] = i / sz;
    }
    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int i = 1; i <= m; i ++) {
        cin >> b[i].l >> b[i].r;
        b[i].id = i;
    }
    sort(b + 1, b + m + 1, [&](S a, S b) {
        if (belong[a.l] != belong[b.l]) return belong[a.l] < belong[b.l];
        else {
            if (belong[a.l] & 1) return a.r < b.r;
            return a.r > b.r;
        }
    });
    int l = 1, r = 0;
    for (int i = 1; i <= m; i ++) {
        auto [ql, qr, qid] = b[i];
        while (l < ql) del(l ++);
        while (l > ql) add(-- l);
        while (r < qr) add(++ r);
        while (r > qr) del(r --);
        ans[qid] = (cv == 0);
    }
    for (int i = 1; i <= m; i ++) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
    for (int i = 1; i <= mx; i ++) cnt[i] = 0;
    now = cv = 0;
    for (int i = 1; i <= n; i ++) ans[i] = a[i] = belong[i] = 0;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}

