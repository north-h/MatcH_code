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
int g[6][6], mp[6][6], idx = -1;
pair<int, int> up[20];


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
    // for (int i = 1; i < 100; i ++) {
    //     cout << a[i] << ':';
    //     for (int j = 18; j >= 0; j --) {
    //         cout << (a[i] >> j & 1);
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= 5; i ++) {
        for (int j = 1; j <= 5; j ++) {
            if (!check(i, j)) continue;
            cin >> g[i][j];
            mp[i][j] = ++idx;
            up[idx] = {i, j};
        }
    }
    vector<int> dp(M + 10, -INF);
    dp[0] = 0;
    // for (int i = 0; i < 19; i ++) {
    //     cout << i << ':' << up[i].first << ' ' << up[i].second << '\n';
    // }
    // for (int i = 1; i <= 5; i ++) {
    //     for (int j = 1; j <= 5; j ++) {
    //         if (!check(i, j)) continue;
    //         cout << i << ' ' << j << ':' << mp[i][j] << '\n';
    //     }
    // }

    for (int i = 1; i < M; i ++) {
        for (int j = 0; j < 19; j ++) {
            if (!(a[i] >> j & 1)) continue;
            for (int k = 0; k < 6; k ++) {
                auto [x, y] = up[j];
                int tx = x + dx[k], ty = y + dy[k];
                int Tx = x + qx[k], Ty = y + qy[k];
                dp[a[i]] = max(dp[a[i]], dp[a[i] ^ (1 << j)]);
                if (check(tx, ty) && check(Tx, Ty)) {
                    auto idx = mp[tx][ty], IDX = mp[Tx][Ty];
                    if ((a[i] >> idx & 1) && !(a[i] >> IDX & 1)) continue;
                    int ni = a[i] ^ (1 << IDX) ^ (1 << idx) ^ (1 << j);
                    dp[a[i]] = max(dp[ni] + g[tx][ty], dp[a[i]]);
                }
            }
        }
    }
    int n; cin >> n;
    while (n --) {
        int st = 0;
        for (int i = 0; i < 19; i ++) {
            char op; cin >> op;
            if (op == '#') st += (1 << i);
        }
        cout << st << '\n';
        // cout << st << ' ' << (M - 1) << '\n';
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