// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int N) {
        n = N;
        sum1.resize(n + 1);
        sum2.resize(n + 1);
    }
    void add(int x, T k) {
        for (int i = x; i <= n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void range_add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for (int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);

    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int m; cin >> m;
    vector<array<int, 3>> q(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> q[i][1] >> q[i][0];
        q[i][2] = i;
    }
    sort(q.begin() + 1, q.end());
    vector<int> ans(m + 1);
    map<int, int> lst;
    int idx = 1;
    BIT<int> bit(n + 1);
    for (int i = 1; i <= m; i ++) {
        auto [r, l, id] = q[i];
        while (idx <= r) {
            if (!lst.count(a[idx])) {
                bit.range_add(idx, idx, 1);
                lst[a[idx]] = idx;
            } else {
                bit.range_add(lst[a[idx]], lst[a[idx]], -1);
                bit.range_add(idx, idx, 1);
                lst[a[idx]] = idx;
            }
            idx ++;
        }
        ans[id] = bit.range_query(l, r);
    }
    for (int i = 1; i <= m; i ++) cout << ans[i] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}