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
    int n, m;
    cin >> n >> m;
    if (n > 0 && m > 0) {
        cout << max(n, m) << ' ' << n + m << endl;
        cout << "^_^" << endl;
    }else if (n < 0 && m < 0) {
        cout << 0 << ' ' << 0 << endl;
        cout << "-_-" << endl;
    } else {
        cout << max(n, m) << ' ' << max(0, n + m) << endl;
        cout << "T_T" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}