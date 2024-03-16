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
    map<int, int> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        mp[x] ++;
    }
    int p = 0;
    for (int i = 0; i < n; i ++) {
        if (mp[i] == 0) {
            cout << i << endl;
            return ;
        }
        if (mp[i] == 1) {
            p = i + 1;
            break;
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        return ;
    }
    for (int i = p; i < n; i ++) {
        if (mp[i] <= 1) {
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
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}