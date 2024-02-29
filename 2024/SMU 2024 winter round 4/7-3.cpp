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

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int x = m % 2;
    int y = m / 2;
    cout << x << ' ' << n * ksm(2, y) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}