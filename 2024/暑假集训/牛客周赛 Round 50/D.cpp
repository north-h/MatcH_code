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
    int a, b, c; cin >> a >> b >> c;
    for (int a1 = -10000; a1 <= 10000; a1 ++) {
        if (a1 == 0) continue;
        if (a % a1 == 0) {
            int a2 = a / a1;
            for (int b1 = -10000; b1 <= 10000; b1 ++) {
                if (b1 == 0) continue;
                if (c % b1 == 0) {
                    int b2 = c / b1;
                    if (a1 * b2 + b1 * a2 == b) {
                        cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << '\n';
                        return ;
                    }
                }
            }
        }
    }
    cout << "NO" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}