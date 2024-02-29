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
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i ++) {
        int x = i;
        int s1 = 0, s2 = 0;
        // debug1(i);
        for (int j = 2; j < x / j; j ++) {
            if (x % j == 0) {
                s1 ++;
                int c = 0;
                while (x % j == 0) x /= j, c ++;
                if (c == 1) s2 ++;
                // debug2(x, j);
                // debug2(s1, s2);
            }
        }
        if (x > 1) s1 ++, s2 ++;
        if (s1 == 3 && s2 == 3) {
            cout << i << endl;
            return ;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}