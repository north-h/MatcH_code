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
    int n, a, b;
    cin >> n >> a>> b;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> sa(n + 1), sb(n + 1);
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] == '0') {
            sa[i] = sa[i - 1] + 1;
            sb[i] = sb[i - 1];
        } else {
            sb[i] = sb[i - 1] + 1;
            sa[i] = sa[i - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int l = i, r = n, res = n + 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (sa[mid] - sa[i - 1] >= a and sb[mid] - sb[i - 1] >= b) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        ans += (n - res + 1);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}