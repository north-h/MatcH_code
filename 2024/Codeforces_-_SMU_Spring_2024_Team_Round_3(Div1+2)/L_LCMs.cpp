/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-30 13:03:23 ms
 *
 * Problem: L. LCMs
 * Contest: Codeforces - SMU Spring 2024 Team Round 3(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/521164/problem/L
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

int get(int x) {
    for (int i = 2; i * i <= x; i ++) {
        if (x % i != 0) continue;
        return i;
    }
    if (x > 1) return x;
}

void solve() {
    ll a, b; cin >> a >> b;
    ll gc = __gcd(a, b);
    if (a > b) swap(a, b);
    ll ans = LLONG_MAX;
    if (a == b) ans = 0;
    else if (check(a) && check(b)) ans = min(a * b, (a + b) * 2);
    else if (b % a == 0) ans = b;
    else if (gc == 1) {
        int A, B;
        A = get(a); B = get(b);
        if (A == a) A = 0;
        if (B == b) B = 0;
        if (A && !B) {
            ans = min(ans, a + (ll)A * b);
            ans = min(ans, a + (ll)A * 2 + 2 * b);
        }
        if (B && !A) {
            ans = min(ans, b + (ll)B * a);
            ans = min(ans, b + (ll)B * 2 + 2 * a);
        }
        if (A && B) {
            ans = min(ans, a + b + A * 2 + 2 * B);
            ans = min(ans, a + b + A * B);
        }
    } else ans = a + b;
    cout << ans << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}