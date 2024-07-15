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
    int n, m, k; cin >> n >> m >> k;
    if (n * m / 2 < k) cout << "NO" << '\n';
    else if (n * m / 2 == k) {
        if (m & 1) cout << "NO" << '\n';
        else {
            
        }
    } else if (n & 1 && m % 2 == 0) {
        if (k < m / 2) cout << "NO" << '\n';
        else {
            int cnt = m / 2 - k;
            if (cnt % 2 == 0) {

            } else cout << "NO" << '\n';
        }
    } else if (m & 1 && n % 2 == 0) {
        if (k & 1 || (m - 1) / 2 * n < k) cout << "NO" << '\n';
        else {

        }
    } else {
        if (k % 2 == 0) {

        } else cout << "NO" << '\n';  
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}