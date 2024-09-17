/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-07 12:07:02
 *
 * Problem: C. Mystic Permutation
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548070/problem/C
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
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pq.push(a[i]);
    }
    if (n == 1) {
        cout << -1 << '\n';
        return ;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        auto t = pq.top(); pq.pop();
        if (t != a[i]) {
            if (pq.top() == a[n] && pq.size() == 1) {
                cout << pq.top() << ' ';
                pq.pop();
                pq.push(t);
            } else {
                cout << t << ' ';
            }
        } else {
            auto T = pq.top(); pq.pop();
            cout << T << ' ';
            pq.push(t);
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}