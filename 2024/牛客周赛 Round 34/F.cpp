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
    int n, m, x;
    cin >> n >> m >> x;
    if (x == 2) {
        cout << -1 << endl;
        return ;
    }
    vector<vector<int>> mart(n + 1, vector<int>(m + 1));
    if (x % 4 == 0) {
        int t = x / 4;
        mart[1][1] = mart[1][m] = mart[n][1] = mart[n][m] = t;
    } else {
        int t = (x - 6) / 4;
//         debug1(t);
        mart[1][1] = mart[1][m] = mart[n][1] = mart[n][m] = t;
        mart[1][2] = mart[1][3] = mart[2][1] = mart[2][2] = mart[3][1] = mart[3][3] = 1;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << mart[i][j] << ' ';
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