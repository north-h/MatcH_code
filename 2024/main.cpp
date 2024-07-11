// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, sq;
    cin >> n >> m;
    sq = sqrt(n);
    vector<int> a(n + 1), st(sq + 1), ed(sq + 1), sum(sq + 1), mk(sq + 1), sz(sq + 1), belong(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= sq; i ++) {
        st[i] = n / sq * (i - 1) + 1;
        ed[i] = n / sq * i;
    }
    ed[sq] = n;
    for (int i = 1; i <= sq; i ++) {
        for (int j = st[i]; j <= ed[i]; j ++) {
            sum[i] += a[j];
            belong[j] = i;
        }
    }
    for (int i = 1; i <= sq; i ++) {
        sz[i] = ed[i] - st[i] + 1;
    }
    auto modify = [&] (int l, int r, int k) -> void{
        if (belong[l] == belong[r]) {
            for (int i = l; i <= r; i ++) {
                a[i] += k;
                sum[belong[i]] += k;
            }
            return ;
        }
        for (int i = l; i <= ed[belong[l]]; i ++) {
            a[i] += k;
            sum[belong[i]] += k;
        }
        for (int i = st[belong[r]]; i <= r; i ++) {
            a[i] += k;
            sum[belong[i]] += k;
        }
        for (int i = belong[l] + 1; i < belong[r]; i ++) {
            mk[i] += k;
        }
    };

    auto query = [&] (int l, int r) -> int {
        int res = 0;
        if (belong[l] == belong[r]) {
            for (int i = l; i <= r; i ++) {
                res += a[i] + mk[belong[i]];
            }
            return res;
        }
        for (int i = l; i <= ed[belong[l]]; i ++) {
            res += a[i] + mk[belong[i]];
        }
        for (int i = st[belong[r]]; i <= r; i ++) {
            res += a[i] + mk[belong[i]];
        }
        for (int i = belong[l] + 1; i < belong[r]; i ++) {
            res += sum[i] + mk[i] * sz[i];
        }
        return res;
    };
    while (m --) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            int k;
            cin >> k;
            modify(x, y, k);
        } else {
            cout << query(x, y) << endl;
        }
    }
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}