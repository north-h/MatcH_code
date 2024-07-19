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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a, b;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        if (s[i] == '1') b.push_back(x);
        else a.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int ans = 0;
    for (int i = 0; i < b.size(); i ++) {
        int l = 0, r = a.size() - 1, res = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[mid] < b[i]) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        // debug2(b[i], res);
        // if (res != -1) {
        ans = max(ans, i + 1 + res + 1);
        // } else ans = max(ans, i + 1 + (int)a.size());
    }
    if (!b.size()) ans = n;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}