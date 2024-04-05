/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:14 ms
 *
 * Problem: B3911 [语言月赛 202312] 铅球杯
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/B3911?contestId=165469
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<string, int> mp;
    string s;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> s >> x;
        mp[s] = x;
    }
    getline(cin, s);
    for (int i = 1; i <= k; i ++) {
        getline(cin, s);
        for (int j = 0; j < s.size(); j ++) {
            if (s[j] == '{') {
                int k = j + 1;
                string sans;
                while (s[k] != '}' && k < s.size()) {
                    sans += s[k];
                    k ++;
                }
                cout << mp[sans];
                j = k;
            } else cout << s[j];
        }
        cout << endl;
    }
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