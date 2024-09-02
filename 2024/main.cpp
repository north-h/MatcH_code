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
     int l, r; cin >> l >> r;
     int x = r - l;
    //  debug1(x);
     int L = 1, R = 1e9, ans = 0;
     while (L <= R) {
        int mid = L + R >> 1;
        if ((mid + 1) * mid / 2 <= x) L = mid + 1, ans = mid;
        else R = mid - 1;
     }
     cout << ans + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}