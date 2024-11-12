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

int dx[] = {0, 1, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1};
int qx[] = {0, 2, 0, -2, -2, -2};
int qy[] = {2, 0, -2, 0, 2, -2};

bool check(int x, int y) {
    if (x < 1 || y < 1 || x > 5) return false;
    if (x == 1 && y > 3) return false;
    if (x == 2 && y > 4) return false;
    if (x == 3 && y > 5) return false;
    if (x == 4 && y > 4) return false;
    if (x == 5 && y > 3) return false;
    return true;
}

void solve() {
    vector g(6, vector<char>(6));
    vector mp(6, vector<int>(6));
    vector<pair<int, int>> up(19);
    int idx = -1;
    for (int i = 1; i <= 5; i ++) {
        for (int j = 1; j <= 5; j ++) {
            if (!check(i, j)) continue;
            cin >> g[i][j];
            mp[i][j] = ++idx;
            up[idx] = {i, j};
        }
    }
    vector<int> dp(M);
    // for (int i = 0; i < 19; i ++) {
    //     cout << i << ':' << up[i].first << ' ' << up[i].second << '\n';
    // }
    // for (int i = 1; i <= 5; i ++) {
    //     for (int j = 1; j <= 5; j ++) {
    //         if (!check(i, j)) continue;
    //         cout << i << ' ' << j << ':' << mp[i][j] << '\n';
    //     }
    // }
    for (int i = M - 1; i >= 0; i --) {
        for (int j = 0; j < 19; j ++) {
            if (i >> j & 1) continue;
            for (int k = 0; k < 6; k ++) {
                auto [x, y] = up[j];
                // debug2(x, y);
                int tx = x + dx[k], ty = y + dy[k];
                int Tx = x + qx[k], Ty = y + qy[k];
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
                if (check(tx, ty) && check(Tx, Ty)) {
                    auto idx = mp[tx][ty], IDX = mp[Tx][Ty];
                    if (!(i >> idx & 1) && (i >> IDX & 1)) continue;
                    // debug2(tx, ty);
                    // debug2(Tx, Ty);
                    // debug1(g[tx][ty]);
                    int ni = i ^ (1 << IDX) ^ (1 << idx) ^ (1 << j);
                    dp[i] = max(dp[ni] + g[tx][ty], dp[i]);
                }
            }
        }
    }
    int n; cin >> n;
    while (n --) {
        int st = 0;
        for (int i = 1; i <= 19; i ++) {
            char op; cin >> op;
            if (op == '.') st *= 2;
            else st = st * 2 + 1;
        }
        // cout << st << ' ' << (M - 1) << '\n';
        cout << dp[st ^ (M - 1)] << '\n'; 
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}