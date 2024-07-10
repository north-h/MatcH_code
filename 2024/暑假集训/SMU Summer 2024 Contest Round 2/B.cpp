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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> sa(n + 1);
    s = " " + s;
    for (int i = 1; i < s.size() - 1; i ++) {
        if (s[i] == s[i + 1]) sa[i] = 1;
    }
    for (int i = 1; i <= n; i ++) sa[i] += sa[i - 1];
    while (q --) {
        int l, r; cin >> l >> r;
        int x = sa[r] - sa[l - 1];
        if (r < s.size() && s[r] == s[r + 1]) x --;
        cout << x << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}