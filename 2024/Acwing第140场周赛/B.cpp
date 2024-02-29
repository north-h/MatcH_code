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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int  n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout <<0 << endl;
        return ;
    }
    auto ask = [&](int x, int y) -> int {
        int c = 0;
        if (y != 0) c ++;
        if (x != 0) c ++;
        vector<int> b = a;
        b[1] += x;
        b[n] += y;
        int dd = b[n] - b[1];
        if (dd % (n - 1)) return INF;
        int d = dd / (n - 1);
        for (int i = 2; i <= n; i ++) {
            int t = b[i] - b[i - 1];
            if (abs(t - d) > 1) return INF;
            if (t != d) {
                if (t > d) b[i] --;
                else b[i] ++;
                c ++;
            }
        }
        return c;
    };
    int ans = INF;
    for (int i = -1; i <= 1; i ++) {
        for (int j = -1; j <= 1; j ++) {
            ans = min(ans, ask(i, j));
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}