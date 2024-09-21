/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-21 13:18:48
 *
 * Problem: I. Strange Sorting
 * Contest: Codeforces - SMU Autumn 2024 Team Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551542/problem/I
 * MemoryL: 1024 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int n, sz;
int a[N];
vector<array<int, 2>> ans;
bool ok;

void op () {
    int l = 1, r = n;
    for (int i = 1; i <= n; i ++) {
        l = i;
        if (a[i] != i) {
            break;
        }
    }
    // debug2(l, r);
    if (l == n) {
        ok = true;
        return ;
    }
    for (int i = n; i >= l; i --) {
        r = i;
        if (a[i] != i) {
            break;
        }
    }
    if (a[l] > a[r]) {
        ans.push_back({l, r});
        ok = true;
        return ;
    }
    for (int i = l; i <= r; i ++) {
        if (a[i] == l) {
            ans.push_back({l, i});
            if ((int)ans.size() == sz) return ;
            sort(a + l, a + i + 1);
            break;
        }
    }
    for (int i = 1; i <= n; i ++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = r; i >= 1; i --) {
        if (a[i] == a[r] + 1) {
            ans.push_back({i, r});
            if ((int)ans.size() == sz) return ;
            sort(a + i, a + r + 1);
        }
    }
    for (int i = 1; i <= n; i ++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    ans.clear();
    ok = false;
    cin >> n;
    sz = n / 2;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    while (ans.size() < sz && !ok) op();
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}