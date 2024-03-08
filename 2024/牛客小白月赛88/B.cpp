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
    vector<string> s(6);
    for (int i = 1; i <= 5; i ++) {
        getline(cin, s[i]);
    }
    if (s[3][5] == '&') {
        cout << ((s[2][0] - '0') & (s[4][0] - '0')) << endl;
    } else if (s[3][5] == '=') {
        cout << ((s[2][0] - '0') | (s[4][0] - '0')) << endl;
    } else {
        cout << !(s[3][0] - '0') << endl;
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