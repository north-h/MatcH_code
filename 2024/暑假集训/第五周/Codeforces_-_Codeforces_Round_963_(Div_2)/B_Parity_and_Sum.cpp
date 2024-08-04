/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-04 22:35:48
 *
 * Problem: B. Parity and Sum
 * Contest: Codeforces - Codeforces Round 963 (Div. 2)
 * URL:     https://codeforces.com/contest/1993/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
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

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), ji, ou;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] & 1) ji.push_back(a[i]);
        else ou.push_back(a[i]);
    }
    if (!ji.size() || !ou.size()) {
        cout << 0 << '\n';
        return ;
    }
    priority_queue<int> pq;
    for (auto i : ji) pq.push(i);
    int ans = 0;
    sort(ou.begin(), ou.end());
    for (auto i : ou) {
        while (true) {
            auto t = pq.top();
            pq.push(t + i);
            ans ++;
            if (t >= i) break;
        }
    }
    sort(ji.rbegin(), ji.rend());
    sort(ou.rbegin(), ou.rend());
    int res = 0;
    if (ou[0] > ji[0]) res += 2;
    else res ++;
    res += (int)ou.size() - 1;
    cout << min(ans, res) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}