/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-12 19:18:18
 *
 * Problem: C. Manhattan Subarrays
 * Contest: Codeforces - SMU Autumn 2024 Trial 3
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549249/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int mdis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool judge(int x1, int y1, int x2, int y2, int x3, int y3) {
    int a = mdis(x1, y1, x2, y2);
    int b = mdis(x1, y1, x3, y3);
    int c = mdis(x2, y2, x3, y3);
    // cout << a << ' ' << b << ' ' << c << '\n';
    if (a + b == c || a + c == b || b + c == a) return true;
    return false;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    if (n <= 2) {
        cout << n * (n + 1) / 2 << '\n';
        return ;
    }
    if (n == 3) {
        if (judge(a[1], 1, a[2], 2, a[3], 3)) cout << n * (n + 1) / 2 - 1 << '\n';
        else cout << n * (n + 1) / 2 << '\n';
        return ;
    }
    int cv = (n + 1) * n / 2 - (n - 4) * (n - 3) / 2;
    // debug1(cv);
    for (int i = 3; i <= n; i ++) {
        if (judge(a[i - 2], i - 2, a[i - 1], i - 1, a[i], i)) cv --;
    }
    // debug1(cv);
    for (int i = 4; i <= n; i ++) {
        bool ok = false;
        if (judge(a[i - 3], i - 3, a[i - 2], i - 2, a[i - 1], i - 1)) ok = true;
        if (judge(a[i], i, a[i - 3], i - 3, a[i - 1], i - 1)) ok = true;
        if (judge(a[i - 3], i - 3, a[i - 2], i - 2, a[i], i)) ok = true;
        if (judge(a[i - 2], i - 2, a[i - 1], i - 1, a[i], i)) ok = true;
        // debug1(ok);
        if (ok) cv --;
    }
    cout << cv << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}