// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

bool check(string a, string b) {
    // debug2(a, b);
    if (a.size() > b.size()) return false;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0, j = 0; i < a.size(); i ++, j ++) {
        if (a[i] != b[j]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    map<string, set<string>> mp;
    for (int i = 1; i <= n; i ++) {
        string id; cin >> id;
        int k; cin >> k;
        for (int j = 1; j <= k; j ++) {
            string s; cin >> s;
            mp[id].insert(s);
        }
    }
    map<string, set<string>> ans;
    for (auto &[x, y] : mp) {
        if (y.size() == 1) {
            ans[x].insert(*y.begin());
            continue;

        }
        for (auto i : y) {
            bool ok = false;
            for (auto j : y) {
                if (i == j) continue;
                if (check(i, j)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) ans[x].insert(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) {
        cout << x << ' '  << y.size() << ' ';
        for (auto i : y) cout << i << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}