// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define lf(x) fixed << setprecision(x)
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

bool isprim(int x) {
    for (int i = 2; i * i <= x; i ++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    if (isprim(n)) {
        cout << 1 << endl;
        cout << n << endl;
        return ;
    }
    int ans = 0, l = 0, r = 0;
    for (int i = 2; i <= n; i ++) {
        if (n % i == 0) {
            int j = i;
            int x = n;
            while (x % j == 0) j ++, x /= i;
            if (ans > j - i) {
                ans = j - i;
                l = i;
                r = j;
            }
        }
    }
    cout << ans << endl;
    for (int i = l; i < r; i ++) {
        if (i == l) cout << i;
        else cout << '*' << i;
    }
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