/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-25 16:03:10
 *
 * Problem: E. Expanding STACKS!
 * Contest: Codeforces - SMU Autumn 2024 Team Round 3（成都）
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/552299/problem/E
 * MemoryL: 1024 MB
 * TimeL:   300 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int get(string s) {
    int res = 0;
    for (auto i : s) res = res * 10 + (i - '0');
    return res;
}

void solve() {
    int n; cin >> n;
    vector g(n + 1, vector<int>());
    vector<string> ss(n * 2 + 1);
    map<int, int> s, e;
    int idx = 0;
    for (int i = 1; i <= n * 2; i ++) {
        cin >> ss[i];
        int num = get(ss[i].substr(1));
        if (ss[i][0] == '+') s[num] = ++ idx;
        else e[num] = ++ idx;
    }
    for (int i = 1; i <= n * 2; i ++) {
        int num = get(ss[i].substr(1));
        if (ss[i][0] == '-') continue;
        int st = s[num], ed = e[num];
        for (int j = i + 1; j <= n * 2; j ++) {
            if (ss[j][0] == '-') continue;
            int tnum = get(ss[j].substr(1));
            int sst = s[tnum], eed = e[tnum];
            if (sst > st && sst < ed && eed > ed) {
                g[num].push_back(tnum);
                g[tnum].push_back(num);
            }
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << ":";
    //     for (auto j : g[i]) cout << j << " ";
    //     cout << '\n';
    // }
    vector<int> color(n + 1, -1);
    auto bfs = [&](int x) -> bool {
        queue<int> q;
        q.push(x);
        color[x] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (auto v : g[t]) {
                if (color[v] == -1) {
                    color[v] = color[t] ^ 1;
                    q.push(v);
                    continue;
                }
                if (color[v] == color[t])
                    return false;
            }
        }
        return true;
    };
    int f = 1;
    for (int i = 1; i <= n; i ++) {
        if (color[i] == -1) f &= bfs(i);
    }
    // for (int i = 1; i <= n; i ++) cout << color[i] << ' ';
    // cout << '\n';
    if (!f) cout << "*" << '\n';
    else {
        for (int i = 1; i <= n; i ++) {
            if (color[i]) cout << "S";
            else cout << "G";
        }
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