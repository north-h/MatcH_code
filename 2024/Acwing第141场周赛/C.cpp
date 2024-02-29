#pragma GCC optimize("Ofast")
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
const int N = 1000100;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    BIT(int N) {
        int n = N;
        sum1.resize(n + 1);
        sum2.resize(n + 1);
    }
    void add(int x, T k) {
        for(int i = x; i < N; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void range_add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);

    }
};

void solve() {
    int n;
    cin >> n;
    BIT<ll> bit(N);
    // unordered_map<int,int> mp;
    vector<int> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        bit.range_add(a[i], a[i], 1);
        sum += bit.range_query(a[i] + 1, N - 1);
        // mp[a[i]] = i;
    }
    // int ans = 0;
    // for (int i = 1;i <= n; i ++) {
    //     if (a[i] == i) continue;
    //     int ai = a[i], aj = i;
    //     int pi = mp[ai], pj = mp[aj];
    //     swap(a[pi], a[pj]);
    //     mp[ai] = pj;
    //     mp[aj] = pi;
    //     ans ++;
    // }
    // ans = 3 * n - ans;
    // if (ans % 2 == 0) cout << 1 << endl;
    // else cout << 2 << endl;
    // cout << sum << endl;
    if (sum % 2 == 3 * n % 2) cout << 1 << endl;
    else cout << 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--) solve();
    return 0;
}