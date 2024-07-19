// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 1010;
const int INF = 0x3f3f3f3f;

using namespace std;

int s[N][N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        string ss; cin >> ss; ss = " " + ss;
        for (int j = 1; j < ss.size(); j ++) {
            if (ss[j] == '#') s[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 6; j <= n; j ++) {
            int cnt = 0;
            for (int k = 0; k < 6; k ++) {
                cnt += s[i][j - k];
            }
            if (cnt >= 4) {
                cout << "Yes" << '\n';
                return ;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 6; j <= n; j ++) {
            int cnt = 0;
            for (int k = 0; k < 6; k ++) {
                cnt += s[j - k][i];
            }
            if (cnt >= 4) {
                cout << "Yes" << '\n';
                return ;
            }
        }
    }
    for (int i = 6; i <= n; i ++) {
        for (int j = 6; j <= n; j ++) {
            int cnt = 0;
            for (int k = 0; k < 6; k ++) {
                cnt += s[i - k][j - k];
            }
            if (cnt >= 4) {
                // debug2(i, j);
                cout << "Yes" << '\n';
                return ;
            }
        }
    }
    for (int i = 6; i <= n; i ++) {
        for (int j = 1; j + 6 - 1 <= n; j ++) {
            int cnt = 0;
            for (int k = 0; k < 6; k ++) {
                cnt += s[i - k][j + k];
            }
            if (cnt >= 4) {
                cout << "Yes" << '\n';
                return ;
            }
        }
    }
    cout << "No" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}