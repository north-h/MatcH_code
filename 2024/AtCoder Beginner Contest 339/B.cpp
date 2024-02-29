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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<char>> g(N + 1, vector<char>(W + 1, '.'));
    int d = 1, x = 1, y = 1;
    for (int i = 1; i <= N; i ++) {
        if (g[x][y] == '.') {
            g[x][y] = '#';
            d ++;
            if (d > 4) d = 1;
            if (d == 1) x --;
            else if (d == 2) y ++;
            else if (d == 3) x ++;
            else y --;
            if (x < 1) x = H;
            if (x > H) x = 1;
            if (y < 1) y = W;
            if (y > W) y = 1;
        } else {
            g[x][y] = '.';
            d --;
            if (d < 1) d = 4;
            if (d == 1) x --;
            else if (d == 2) y ++;
            else if (d == 3) x ++;
            else y --;
            if (x < 1) x = H;
            if (x > H) x = 1;
            if (y < 1) y = W;
            if (y > W) y = 1;

        }
    }
    for (int i = 1; i <= H; i ++) {
        for (int j = 1; j <= W; j ++) {
            cout << g[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}