/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-09 14:27:53
 *
 * Problem: A. Load Balancing
 * Contest: Codeforces - SMU Autumn 2024 Trial 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548611/problem/A
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

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = 0;
    int lt = sum / n, rt = lt + 1, cl, cr;
    if (lt) {
        if (sum % n) cr = sum % n, cl = n - cr;
        else cl = n, cr = n, rt = lt;;
    } else {
        int cc = 0;
        for (int i = 1; i <= n; i ++) {
            if (a[i] != 0) cc ++;
        }
        cout << sum - cc << '\n';
        return;
    }
    int ok = 0;
    for (int i = 1, j = n; i < j;) {
        int vx = abs(a[i] - lt), vy = abs(a[j] - rt);
        if (vx < vy) {
            ans += vx;
            a[j] -= vx;
            a[i] += vx;
            i ++; 
            if (ok == 0) cl --;
            else cr --, cl --;
        } else if (vx > vy) {
            ans += vy;
            a[j] -= vy;
            a[i] += vy;
            j --;
            if (ok == 0) cr --;
            else cl --, cr --;
        } else {
            ans += vx;
            a[i] += vx;
            a[j] -= vx;
            i ++, j --;
            if (ok == 0) cl --, cr --;
            else cl -= 2, cr -= 2;
        }
        if (cl == 0) lt = rt, ok ++;
        else if (cr == 0) rt = lt, ok ++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}