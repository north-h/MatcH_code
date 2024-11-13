/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-12 21:33:02
 *
 * Problem: D. Sternhalma
 * Contest: Codeforces - SMU Autumn 2024 Team Round 13
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/565855/problem/D
 * MemoryL: 512 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f, M = (1 << 19);

using namespace std;

int dx[] = {0, 0, 1, -1, 1, -1};
int dy[] = {2, -2, -1, 1, 1, -1};
int g[10][10], mp[10][10];
pair<int, int> up[20] = {
    {1, 3}, {1, 5}, {1, 7},
    {2, 2}, {2, 4}, {2, 6}, {2, 8},
    {3, 1}, {3, 3}, {3, 5}, {3, 7}, {3, 9},
    {4, 2}, {4, 4}, {4, 6}, {4, 8},
    {5, 3}, {5, 5}, {5, 7}
};

bool check(int x, int y) {
    if (x < 1 || y < 1 || mp[x][y] == -1) return false;
    return true;
}

void solve() {
    vector<int> a;
    for (int i = 0; i < M; i ++) a.push_back(i);
    sort(a.begin(), a.end(), [](int x, int y) {
        int cx = 0, cy = 0;
        for (int i = 0; i < 19; i ++) {
            if (x >> i & 1) cx ++;
            if (y >> i & 1) cy ++;
        }
        if (cx == cy) return x < y;
        return cx < cy;
    });
    memset(mp, -1, sizeof mp);
    for (int i = 0; i < 19; i ++) {
        auto [x, y] = up[i];
        mp[x][y] = i;
        cin >> g[x][y];
    }
    vector<int> dp(M + 10, -INF);
    dp[0] = 0;
    for (int i = 1; i < 1 << 19; i ++) {
        for (int j = 0; j < 19; j ++) {
            if (!(a[i] >> j & 1)) continue;
            auto [x, y] = up[j];
            for (int k = 0; k < 6; k ++) {
                int tx = x + dx[k], ty = y + dy[k], Tx = tx + dx[k], Ty = ty + dy[k];
                dp[a[i]] = max(dp[a[i]], dp[a[i] ^ (1 << j)]);
                if (!check(tx, ty) || !check(Tx, Ty)) continue;
                auto idx = mp[tx][ty], IDX = mp[Tx][Ty];
                if (!(a[i] >> idx & 1) || (a[i] >> IDX & 1)) continue;
                int ni = a[i] ^ (1 << IDX) ^ (1 << idx) ^ (1 << j);
                dp[a[i]] = max(dp[ni] + g[tx][ty], dp[a[i]]);
            }
        }
    }
    int n;
    cin >> n;
    while (n --) {
        int st = 0;
        for (int i = 0; i < 19; i ++) {
            char op;
            cin >> op;
            if (op == '#') st += (1 << i);
        }
        cout << dp[st] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}