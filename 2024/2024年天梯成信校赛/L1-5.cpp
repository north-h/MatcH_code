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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        int x = s.back() - '0';
        int res = 0;
        if (x & 1) {
            for (int i = 0, j = s.size() - 1; j >= 0; i ++, j --) {
                if (i & 1) s[j] = '0';
            }
        } else {
            for (int i = 0, j = s.size() - 1; j >= 0 ; i ++, j --) {
                if (i % 2 == 0) s[j] = '0';
            }
        }
        for (auto i : s) res = res * 10 + (i - '0');
        // cout << s << endl;
        ans += res;
    }
    cout << ans << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}