// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 1000010;
const int INF = 0x3f3f3f3f;

using namespace std;

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
        for(int i = x; i < n; i += (i & -i))
            tr[i] += k;
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i; i -= (i & -i))
            res += tr[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    BIT<int> pre, suf;
    pre.init(N);
    suf.init(N);
    ll sum = 0;
    for (int i = n; i >= 1; i --) {
        suf.add(a[i], 1);
        sum += suf.range_query(1, a[i] - 1);
    }
    ll ans = 0;
    if (sum >= k) ans ++;
    // debug1(sum);
    for (int i = 1, j = 1; i <= n; i ++) {
        // pre.add(a[i], a[i], -1);
        suf.add(a[i], -1);
        sum -= pre.range_query(a[i] + 1, N - 1);
        sum -= suf.range_query(1, a[i] - 1);
        while (j <= i && sum < k) {
            pre.add(a[j], 1);
            sum += pre.range_query(a[j] + 1, N - 1);
            sum += suf.range_query(1, a[j] - 1);
            j ++;
        }
        // debug2(i, j);
        ans += i - j + 1;
    }
    cout << ans << endl;
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