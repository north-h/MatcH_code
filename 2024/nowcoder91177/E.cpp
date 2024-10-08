// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, -1), belong(n + 1);
    int sz = sqrt(n);
    for (int i = 1; i <= n; i ++) {
        belong[i] = i / sz;
    }
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<array<int, 3>> qq;
    for (int i = 1; i <= q; i ++) {
        int l, r; cin >> l >> r;
        qq.push_back({l, r, i - 1});
    }
    sort(qq.begin(), qq.end(), [&](array<int, 3> x, array<int, 3> y) {
        if (belong[x[0]] != belong[y[0]]) return belong[x[0]] < belong[y[0]];
        else {
            if (belong[x[0]] & 1) return x[1] < y[1];
            return x[1] > y[1];
        }
    });
    multiset<int> L, R;
    auto add = [&](int i) -> void {
        if (!L.size() || (*L.rbegin()) >= a[i]) L.insert(a[i]);
        else R.insert(a[i]);
    };
    auto del = [&](int i) -> void {
        if (L.count(a[i])) L.erase(L.find(a[i]));
        else if (R.count(a[i])) R.erase(R.find(a[i]));
    };
    auto adjust = [&]() -> void {
        while ((int)L.size() - (int)R.size() > 1) {
            R.insert((*L.rbegin()));
            L.erase((--L.end()));
        }

        while ((int)R.size() - (int)L.size() > 0) {
            L.insert((*R.begin()));
            R.erase(R.begin());
        }
    };
    for (int i = qq[0][0]; i <= qq[0][1]; i ++) {
        add(i);
        adjust();
    }
    vector<int> ans(q);
    ans[qq[0][2]] = (*L.rbegin());
    // for (auto i : L) cout << i << ' ';
    // cout << '\n';
    // for (auto i : R) cout << i << ' ';
    // cout << '\n';
    int l = qq[0][0], r = qq[0][1];
    for (int i = 1; i < q; i ++) {
        auto [ql, qr, id] = qq[i];
        // debug2(l, r);
        while (ql > l) del(l ++), adjust();
        while (qr > r) add(++ r), adjust();
        while (ql < l) add(-- l), adjust();
        while (qr < r) del(r --), adjust();
        // debug2(l, r);
        // cout << (*L.rbegin()) << '\n';
        ans[id] = (*L.rbegin());
        // for (auto i : L) cout << i << ' ';
        // cout << '\n';
        // for (auto i : R) cout << i << ' ';
        // cout << '\n';
    }
    for (auto i : ans) cout << i << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}