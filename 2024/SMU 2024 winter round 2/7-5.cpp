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
    string s;
    // getline(cin, s);
    int ans = 0, sum = 0, res = 0;
    bool ok = false;
    while (true) {
        getline(cin, s);
        // debug1(s);
        if (s == ".") break;
        sum ++;
        int c = 0;
        if (s.size() < 14) continue;
        for (int i = 0; i < (int)s.size(); i ++) {
            if (s[i] == ' ') c ++;
            if (s.substr(i, 14) == "chi1 huo3 guo1") {
                // debug1(s);
               if (!ok) ans = sum, ok = true; 
               ok = true;
               res ++;
               break;
            }
        }
    }
    cout << sum << endl;
    if (!res) cout << "-_-#" << endl;
    else cout << ans <<' ' << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}