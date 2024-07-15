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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    string s; cin >> s; s = " " + s;
    int ans = 0;
    for (int i = 1; i < s.size(); i ++) {
        auto op = s[i];
        int j = i;
        priority_queue<int> q;
        while (op == s[j] && j < s.size()) {
            q.push(a[j]);
            j ++;
        }
        int cnt = 0;
        while (cnt < k && q.size()) {
            ans += q.top();
            q.pop();
            cnt ++;
        }
        i = j - 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}