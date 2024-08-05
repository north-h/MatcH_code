// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) n --;
    cout << n / 2 << '\n';
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
    }
    for (int i = 1; i <= n / 2; i ++) {
        cout << i << ' ' << i + 2 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}