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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & i : a) cin >> i;
    a[1] -= a[0] * 2;
    a[2] -= a[0];
    a[0] = 0;
    a[n - 2] -= a[n - 1] * 2;
    a[n - 3] -= a[n- 1];
    a[n - 1] = 0;
    // for (auto i : a) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    for (int i = 1; i < n - 2; i ++) {
        if (a[i] == 0) continue;
        if (a[i] < 0) {
            cout << "NO" <<  endl;
            return ;
        }
        a[i + 1] -= a[i] * 2;
        a[i + 2] -= a[i];
        a[i] = 0;
        // for (auto i : a) {
        //     cout << i << ' ';
        // }
        // cout << endl;
    }
    for (auto i : a) {
        if (i != 0) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}