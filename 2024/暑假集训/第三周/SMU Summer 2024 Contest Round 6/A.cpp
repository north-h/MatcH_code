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
    string s; cin >> s;
    int n = s.size() - 1;
    int ans = 0;
    for (int i = 0; i < (1 << n); i ++) {
        string str = s;
        // debug1(i);
        int c = 0;
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) {
                str = str.substr(0, j + 1 + c) + '+' + str.substr(j + 1 + c);
                c ++;
            }
        }
        // debug1(str);
        stack<int> stk;
        bool ok = false;
        for (int j = 0; j < str.size(); j ++) {
            int k = j;
            // debug1(j);
            int sum = 0;
            if (str[j] >= '0' && str[j] <= '9') {
                while (str[k] >= '0' && str[k] <= '9' && k < str.size()) {
                    sum = sum * 10 + (str[k] - '0');
                    k ++;
                }
                j = k - 1;
                // debug1(sum);
                stk.push(sum);
            }
            if (!ok) {
                if (str[j] == '+') ok = true;
            } else {
                int x = stk.top(); stk.pop();
                int y = stk.top(); stk.pop();
                // debug2(x, y);
                stk.push(x + y);
                ok = false;
            }
        }
        // debug1(stk.top());
        ans += stk.top();
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