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
    int t, a, k;
    cin >> t >> a >> k;
    if (t > 0 && a < 0 || t < 0 && a > 0) {
        if (abs(a) <= k) cout << abs(t) + abs(a) << endl;
        else abs(t) * 3 + abs(a) << endl;
    }
    else {
        if (abs(a) <= abs(t)) cout << t << endl;
        else cout << abs(a) + abs(t) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}