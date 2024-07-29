// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    vector<double> a(7);
    for (int i = 0; i < 7; i ++) {
        scanf("%lf%%", &a[i]);
    }
    int c, f; cin >> c >> f;
    if (f == 1) {
        printf("%.2f%%", a[c] * 0.01);
    } else {
        printf("%.2f%%", a[c] * 0.99);
    }
}

int32_t main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}