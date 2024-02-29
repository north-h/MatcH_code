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
    int n, x;
    cin >> n >> x;
    if (x == 0) {
        if (n & 1) cout << -1 << endl;
        else cout << n / 2 << ' ' << n / 2 << endl;
    } else if ( x < 0) {
        int y = n - abs(x);
        if (y & 1) cout << -1 << endl;
        else cout << y / 2 << ' ' << abs(x) + y / 2 << endl;
    } else {
        int y = n - x;
        if (y & 1) cout << -1 << endl;
        else cout << y / 2 + x << ' ' << y / 2 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}