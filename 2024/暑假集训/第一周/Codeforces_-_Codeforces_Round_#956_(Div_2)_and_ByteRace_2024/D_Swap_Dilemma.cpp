/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-08 13:31:04 ms
 *
 * Problem: D. Swap Dilemma
 * Contest: Codeforces - Codeforces Round #956 (Div. 2) and ByteRace 2024
 * URL:     https://codeforces.com/contest/1983/problem/D
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 200010;
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

BIT<int> bit(N + 1);

int get(vector<int> a) {
    int mx = *max_element(a.begin() + 1, a.end());
    int cv = 0;
    for (int i = 1; i < a.size(); i ++) {
        cv += bit.range_query(a[i] + 1, N);
        bit.range_add(a[i], a[i], 1);
    }
    for (int i = 1; i < a.size(); i ++) {
        bit.range_add(a[i], a[i], -1);
    }
    return cv;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> aa, bb;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        aa[a[i]] ++;
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        bb[b[i]] ++;
    }

    if (get(a) % 2 == get(b) % 2 && aa == bb) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}