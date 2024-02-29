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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= m; j += 2) {
            if (a[i][j] & 1) a[i][j] ++;
        }
        for (int j = 2; j <= m; j += 2) {
            if (a[i][j] % 2 == 0) a[i][j] ++;
        }
    }
    for (int i = 2; i <= n; i +=2 ) {
        for (int j = 2; j <= m; j += 2) {
            if (a[i][j] & 1) a[i][j] ++;
        }
        for (int j = 1; j <= m; j += 2) {
            if (a[i][j] % 2 == 0) a[i][j] ++;
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << a[i][j] <<' ';
        }
        cout << endl;
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}