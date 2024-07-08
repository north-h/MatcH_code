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
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N], b[N], n, t[N];

int inversion(int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    int res = inversion(l, mid) + inversion(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (b[i] <= b[j]) t[k ++] = b[i ++];
        else {
            res += mid - i + 1;
            t[k ++] = b[j ++];
        }
    }
    while (i <= mid) t[k ++] = b[i ++];
    while (j <= r) t[k ++] = b[j ++];
    for (int i = l, j = 0; i <= r; i++, j++) b[i] = t[j];
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j ++) {
        cin >> b[j];
    }
    a[0] = b[0] = 0;
    sort(a + 1, a + n + 1);
    int cnt = inversion(1, n);
    debug1(cnt);
    for (int i = 1; i <= n; i ++) cout << b[i] << ' ';
    cout << '\n';
    bool f = true;
    for (int i = 1; i <= n; i ++) {
        if (a[i] != b[i]) f = false;
    }
    if (!f || cnt % 2) cout << "NO\n";
    else cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}