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
    vector<string> s(n + 1);
    vector<int> sum(n + 1);
    vector<array<int, 2>> cv(110);
    auto get = [&] (string s) -> int {
        int res = 0;
        for (auto i : s) {
            res += (i - '0');
        }
        return res;
    };
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        sum[i] = get(s[i]);
        cv[sum[i]][s[i].size() & 1] ++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int ls = 0;
        for (auto j : s[i]) {
            ls += (j - '0');
            int rs = ls * 2 - sum[i];
            if (rs < 0) continue;
            ans += cv[rs][s[i].size() & 1];
        }
    }
    for (int j = 1; j <= n; j ++) {
        int rs = 0;
        for (int i = s[j].size() -1 ; i >= 1; i --) {
            rs += (s[j][i] - '0');
            int ls = rs * 2 - sum[j];
            if (ls < 0) continue;
            ans += cv[ls][s[j].size() & 1];
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