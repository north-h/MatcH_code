#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int N = 4e5 + 10;

int a[N], pos[N] , vis[N], ans[N];
struct node {
    int l, r, id;
} ex[N];
bool cmp(node a, node b) {
    return pos[a.l] == pos[b.l] ? a.r < b.r : pos[a.l] < pos[b.l];
}
int cnt[N], num[N], Ans;
// void add(int x) {
//     --num[cnt[a[x]]], ++num[++cnt[a[x]]];
//     while (num[Ans + 1]) ++Ans;
// }

// void del(int x) {
//     --num[cnt[a[x]]], ++num[--cnt[a[x]]];
//     while (!num[Ans]) --Ans;
// }

void add(int x) {
    num[cnt[a[x]]] --;
    cnt[a[x]] ++;
    num[cnt[a[x]]] ++;
    while (num[Ans + 1]) Ans ++;
}

void del(int x) {
    num[cnt[a[x]]] --;
    cnt[a[x]] --;
    num[cnt[a[x]]] ++;
    while (!num[Ans]) Ans --;
}

void solve() {

    int n, k, q;
    cin >> n >> k >> q;

    memset(cnt, 0, sizeof cnt);
    memset(num, 0, sizeof num);
    memset(ans, 0, sizeof ans);

    int siz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] - i + n;
        pos[i] = i / siz;
    }
    for (int i = 1; i <= q; i++) {
        cin >> ex[i].l >> ex[i].r;
        ex[i].id = i;
    }
    sort(ex + 1, ex + 1 + q, cmp);
    Ans = 0, num[0] = 1;
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++) {
        int ql = ex[i].l, qr = ex[i].r;
        while (r < qr) add(++r);
        while (r > qr) del(r--);
        while (l < ql) del(l++);
        while (l > ql) add(--l);
        ans[ex[i].id] = Ans;
    }
    for (int i = 1; i <= q; i++) {
        cout << k - ans[i] << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
