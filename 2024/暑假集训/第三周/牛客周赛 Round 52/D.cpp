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
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    priority_queue<string> Q;
    for (int i = 1; i <= n; i ++) {
        Q.push(a[i]);
    }
    string s = "";
    while (Q.size()) {
        auto t = Q.top();
        Q.pop();
        s += t[0];
        if (t.size() > 1) {
            Q.push(t.substr(1));
        }
    }
    cout << s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}