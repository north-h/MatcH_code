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
    ll n;
    cin >> n;
    if (n % 495 == 0) {
        cout << -1 << endl;
        return ;
    }
    n %= 495;
    n *= 10;
    for (int i = 0; i <= 9; i ++) {
        if ((n + i) % 495 == 0) {
            int s = to_string(i).size();
            while (s < 1) s ++, cout << '0';
            cout << i << endl;
            return ;
        }
    }
    n *= 10;
    for (int i = 0; i <= 99; i ++) {
        if ((n + i) % 495 == 0) {
            int s = to_string(i).size();
            while (s < 2) s ++, cout << '0';
            cout << i << endl;
            return ;
        }
    }
    n *= 10;
    for (int i = 0; i <= 999; i ++) {
        if ((n + i) % 495 == 0) {
            int s = to_string(i).size();
            while (s < 3) s ++, cout << '0';
            cout << i << endl;
            return ;
        }
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