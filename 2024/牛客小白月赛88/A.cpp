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
    int x;
    cin >> x;
    int n;
    cin >> n;
    int ans = 0;
    char op;
    for (int i = 1; i <= n; i ++) {
        int a1;
        char a2;
        cin >> a2 >> a1;
        if (a1 > ans) {
            ans = a1;
            op = a2;
        }
    }
    if (ans * 1000 < x) cout << -1 << endl;
    else {
        for (int i = 1; i <= (x + ans - 1) / ans; i ++) cout << op;
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