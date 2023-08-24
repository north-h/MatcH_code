/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-24 01:42:14
 * =====================================
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
 */

#pragma GCC optimize(3)

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
const int N = 200010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;


struct Node {
    int l, r, sum, lazy;
} tr[N * 4];

int a[N];
int n, m;

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

void build(int u, int l, int r) {
    tr[u] = {l, r, a[l], 0};
    if (l == r)return;
    int mid = l + r >> 1;
    pushdown(u);
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int k) {
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

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int sum = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

int query(int u, int x) {
    if(tr[u].l == tr[u].r)return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid)return query(u << 1, x);
    else return query(u << 1 | 1, x);
}

int change(int x, int k) {
    int res = x;
    while(k--) {
        int temp = 0;
        while(res) {
            temp += res % 10;
            res /= 10;
        }
        res = temp;
        if(res < 10)return res;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)a[i] = 0;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    build(1, 1, n);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            modify(1, l, r, 1);
        } else {
            int x;
            cin >> x;
            cout << change(b[x], query(1, x)) << endl;;
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}