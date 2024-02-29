// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        sum += x;
    }
    if (n == 1) {
        cout << 1 << endl;
        return ;
    }
    int ans = 0;
    for (int i = 1; i <= 2e5 + 10; i ++) {
        if (sum / i >= n && sum % i == 0) {
            debug1(i);
            ans ++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}