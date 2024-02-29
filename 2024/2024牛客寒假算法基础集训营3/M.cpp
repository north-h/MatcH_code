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

bool check(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    int c = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[check(a[i]) % 9] ++;
        string s = to_string(a[i]);
        if (s.size() < 2) continue;
        int res = (s[s.size() - 2] - '0') * 10 + (s[s.size() - 1] - '0');
        if (res % 4 == 0) c ++;
    }
    debug1(c);
    for (auto [x, y] : mp) cout << x << ' ' << y << endl;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        auto t = check(a[i]) % 9;
        // debug1(t);
        bool ok = false;
        string s = to_string(a[i]);
        int res = (s[s.size() - 2] - '0') * 10 + (s[s.size() - 1] - '0');
        if (res % 4 == 0) ok = true;
        if (!ok) continue;
        if (ok) {
            ans += mp[9 - t] * (c - 1);
        } else {
            ans += mp[9 - t] * c;
        }
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