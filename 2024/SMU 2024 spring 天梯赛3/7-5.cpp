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
    vector<int> a(7);
    for (int i = 1; i <= 6; i ++) cin >> a[i];
    int n;
    cin >> n;
    auto b = a;
    for (int i = 1; i <= 6; i ++) {
        if (a[i] == 6) b[i] = 5;
        else b[i] = 6;
    }
    // for (int i = 1; i<= 6; i ++) cout << b[i] << ' ';
    // cout << endl;
    // cout << n << endl;
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j <= 6; j++) {
            b[j] --;
            if (b[j] == a[j]) b[j] --;
        }
        // for (int i = 1; i<= 6; i ++) cout << b[i] << ' ';
        // cout << endl;
    }
    for (int i = 1; i <= 6; i ++) cout << b[i] << " \n"[i == 6];
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