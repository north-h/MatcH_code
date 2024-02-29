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
    int n;
    cin >> n;
    vector<PII> a;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            char op;
            cin >> op;
            if (op == '1') a.push_back({i, j}), sum ++;
        }
    }
    debug1(a.size());
    debug2(a.back().fi, a.back().se);
    debug2(a[0].fi, a[0].se);
    if (abs(a.back().se - a[0].se) == abs(a.back().fi - a[0].fi)) cout << "SQUARE" << endl;
    else cout << "TRIANGLE" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}