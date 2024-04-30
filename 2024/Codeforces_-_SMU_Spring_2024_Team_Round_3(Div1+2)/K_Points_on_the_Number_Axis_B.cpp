/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-30 13:03:19 ms
 *
 * Problem: K. Points on the Number Axis B
 * Contest: Codeforces - SMU Spring 2024 Team Round 3(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/521164/problem/K
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * =========================================================
 */

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

bool check(int x) {
    for (int i = 2; i * i <= x; i ++) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<int> get(int x) {
    vector<int> num;
    for (int i = 2; i * i <= x; i ++) {
        if (x % i != 0) continue;
        while (x % i == 0) x /= i;
        num.push_back(i);
    }
    if (x > 1) num.push_back(x);
    return num;
}

void solve() {
    ll a, b; cin >> a >> b;
    if (!check(a) && !check(b)) cout << a * b << '\n';
    else if (__gcd(a, b) == 1) {
        vector<int> A, B;

    } else cout << a + b << '\n';
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