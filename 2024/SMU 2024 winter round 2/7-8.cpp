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
    int n;
    getline(cin, s);
    cin >>  n;
    // debug1(s);
    string xx = "abcdefghijklmnopqrstuvwxyz";
    string dx = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    auto get1 = [&](char op, string s) -> char{
        for (int i = 0; i < (int)s.size(); i ++) {
            if (s[i] == op) {
                int j = i;
                for (int x = 1; x <= n; x ++, j ++) {
                    if (j > 25) j = 0;
                }
                if (j > 25) j = 0;
                return s[j];
            }
        }
    };
    auto get2 = [&](char op, string s) -> char{
        for (int i = 0; i < (int)s.size(); i ++) {
            if (s[i] == op) {
                // debug1(i);
                int j = i;
                for (int x = 1; x <= abs(n); x ++, j --) {
                    if (j < 0) j = 25;
                }
                if (j < 0) j = 25;
                // debug1(j);
                return s[j];
            }
        }
    };
    for (auto &i : s) {
        if (i >= 'a' && i <= 'z') {
            if (n > 0) {
                i = get1(i, xx);
            } else {
                i = get2(i, xx);
            }
        }
        if (i >= 'A' && i <= 'Z') {
            if (n > 0) {
                i = get1(i, dx);
            } else {
                i = get2(i, dx);
            }
        }
    }
    cout << s << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}