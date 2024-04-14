// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    string sans;
    int ans = 0, cnt = 0, f = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '$') break;
        if (s[i] == 'T') {
            cnt ++;
            ans += 10;
            sans += 'D';
            if (!f) {
                sans += '-';
                sans += '-';
                i += 2;
            } else {
                f --;
                if (f == 0) {
                    sans += '-';
                    sans += '-';
                    i += 2;
                }
            }
        } else if (s[i] == 'C') {
            cnt ++;
            sans += '!';
            f += 2;

        
            if (f == 0) f += 2;

        } else {
            if (!f) {
                sans += 'U';
                sans += '-';
                i ++;
            } else {
                f --;
                if (f == 0) {
                    sans += 'U';
                    sans += '-';
                    i ++;
                }
            }
        }
    }
    cout << sans.substr(0, s.size() - 1) << '\n';
    cout << ans - cnt * 3 << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}