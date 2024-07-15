// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int N; cin >> N;
    for (int h = 1; h <= 3500; h ++) {
        for (int w = 1; w <= 3500; w ++) {
            int c1 = h * w * N;
            int c2 = 4 * h * w - w * N - h * N;
            // debug2(h, w);
            // debug2(c1, c2);
            if (c2 > 0 && c1 % c2 == 0) {
                cout << h << ' ' << c1 / c2 << ' ' << w << '\n';
                // if (4.0 / N == 1.0 / h + 1.0 / (c1 / c2) + 1.0 / w) cout << "YES" << '\n';
                return ;
            }
        }
    }
    cout << "NO" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}