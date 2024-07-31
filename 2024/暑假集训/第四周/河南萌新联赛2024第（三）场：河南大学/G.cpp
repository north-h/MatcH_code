// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int a, b, c, n, w;
    cin >> a >> b >> c >> n >> w;
    int ans = 1e15;
    auto check = [&](int x, int y, int z) -> int {
        return abs(x * a + y * b + z * c - w);
    };
    for (int x = 0; x <= n; x ++) {
        int l = 0, r = n - x;
        while (l < r) {
            int midl = l + (r - l) / 3;
            int midr = r - (r - l) / 3;
            int mid = l + r >> 1;
            int ls = check(x, midl, n - x - midl);
            int rs = check(x, midr, n - x - midr);
            if (ls >= rs) l = midl + 1;
            else r = midr - 1;
        }
        ans = min(ans, abs(x * a + l * b + (n - x - l) * c - w));
        ans = min(ans, abs(x * a + r * b + (n - x - r) * c - w));
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}