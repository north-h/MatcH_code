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
struct BIT {
    vector<T> tr;
    int n;
    BIT() {}
    void init(int N) {
        n = N;
        tr.resize(n + 1);
    }
    void add(int x, T k) {
        for (int i = x; i < n; i += (i & -i))
            tr[i] += k;
    }
    T query(int x) {
        T res = 0;
        for (int i = x; i; i -= (i & -i))
            res += tr[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> s(n + 1);
    set<ll> st;
    unordered_map<ll, int> pos;
    BIT<ll> bit;
    st.insert(0);
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        s[i] = s[i - 1] + x;
        st.insert(s[i]);
        st.insert(s[i] - k);
    }
    int c = 1;
    for (auto i : st) pos[i] = c ++;
    bit.init(c + 1);
    ll ans = 0;
    bit.add(pos[0], 1);
    for (int i = 1; i <= n; i ++) {
        int p = pos[s[i] - k];
        // debug2(p, s[i] - k);
        ans += bit.query(p);
        // debug1(bit.query(p));
        bit.add(pos[s[i]], 1);
    }
    cout << ans << '\n';
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