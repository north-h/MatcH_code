/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-15 20:54:37
 *
 * Problem: C. Penchick and BBQ Buns
 * Contest: Codeforces - Codeforces Round 987 (Div. 2)
 * URL:     https://codeforces.com/contest/2031/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

vector<int> js;

void solve() {
    // for (int i = 0; i <= 10; i ++) cout << js[i] << ' ';
    // cout << '\n';
    int n; cin >> n;
    if (n < 27 && n % 2) {
        cout << -1 << '\n';
        return ;
    }
    int idx = 1, ans = 0;
    if (n & 1) {
        vector<int> a(n + 10, -1);
        a[1] = a[10] = a[26] = 1;
        a[23] = a[27] = 2;
        idx = 3;
        for (int i = 2; i <= n; i ++) {
            if (a[i] != -1) continue;
            a[i] = a[i + 1] = idx ++;
            i ++;
        }
        for (int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << idx << ' ' << idx << ' ';
            idx ++;
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i * i <= N; i += 2) js.push_back(i * i);
    for (int i = 1; i < js.size(); i ++) js[i] += js[i - 1];
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}