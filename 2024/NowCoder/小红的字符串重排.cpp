/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 20:15:35
 *
 * Problem: 小红的字符串重排
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/92662/E
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

void solve() {
    string s; cin >> s;
    map<char, int> mp;
    for (auto i : s) mp[i] ++;
    vector<char> ans;
    for (auto i : s) {
        for (auto j = 'a'; j < 'z'; j ++) {
            if (i == j || !mp[j]) continue;
            // debug2(i, j);
            ans.push_back(j);
            mp[j] --;
            break;
        }
    }
    if (ans.size() != s.size()) cout << -1 << '\n';
    else {
        for (auto i : ans) cout << i;
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}