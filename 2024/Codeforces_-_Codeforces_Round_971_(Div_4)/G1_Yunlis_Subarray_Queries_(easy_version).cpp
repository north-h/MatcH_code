/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-05 13:08:11
 *
 * Problem: G1. Yunli's Subarray Queries (easy version)
 * Contest: Codeforces - Codeforces Round 971 (Div. 4)
 * URL:     https://codeforces.com/contest/2009/problem/G1
 * MemoryL: 512 MB
 * TimeL:   3000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 400010, INF = 0x3f3f3f3f;

using namespace std;

struct S {
    int l, r, id;
} q[N];

int a[N], ans, n, k, m, belong[N], sz, ANS[N];
unordered_map<int, int> cnt, num;

void add(int x) {
    num[cnt[a[x]]] --;
    cnt[a[x]] ++;
    num[cnt[a[x]]] ++;
    while (num[ans + 1]) ans ++;
}

void del(int x) {
    num[cnt[a[x]]] --;
    cnt[a[x]] --;
    num[cnt[a[x]]] ++;
    while (!num[ans]) ans --;
}

void solve() {
    cin >> n >> k >> m;
    cnt.clear();
    num.clear();
    sz = (int)sqrt(n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] = a[i] - i + n;
        belong[i] = i / sz;
    }
    for (int i = 1; i <= m; i ++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m, [&](S a, S b) {
        if (belong[a.l] != belong[b.l]) return belong[a.l] < belong[b.l];
        else return a.r < b.r;
    });
    int l = 1, r = 0;
    num[0] = 1; ans = 0;
    for (int i = 1; i <= m; i ++) {
        auto [ql, qr, qid] = q[i];
        while (l < ql) del(l ++);
        while (l > ql) add(-- l);
        while (r < qr) add(++ r);
        while (r > qr) del(r --);
        ANS[qid] = ans;
    }
    for (int i = 1; i <= m; i ++) {
        cout << k - ANS[i] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}