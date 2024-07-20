// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int d; cin >> d;
    if (d == 0) {
        cout << "1 1\n2" << '\n';
        return ;
    }
    cout << 2 << ' ' << 3 << '\n';
    cout << (1 << 18) - 1 << ' ' << d << ' ' << 0 << '\n';
    cout << (1 << 17) << ' ' << (1 << 18) - 1 << ' ' << d << '\n';
    cout << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}