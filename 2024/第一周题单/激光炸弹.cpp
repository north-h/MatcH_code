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
    int n, r;
    cin >> n >> r;
    vector<vector<int>> a(5010, vector<int> (5010));
    for (int i = 1; i <= n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x ++;
        y ++;
        a[x][y] = v;
    }
    for (int i = 1; i < 5010; i++){
        for (int j = 1; j < 5010; j++){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = r; i < 5010; i++){
        for (int j = r; j < 5010; j++){
            // i - r + 1 - 1
            int res = a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r];
            ans = max(ans, res);
        }
    }
    cout << ans <<endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}