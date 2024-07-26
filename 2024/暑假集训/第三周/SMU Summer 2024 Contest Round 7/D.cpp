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
    int Q; cin >> Q;
    vector<char> f, b;
    int t = 1;
    while (Q --) {
        int op; cin >> op;
        if (op == 1) {
            t ^= 1;
        } else {
            int x; char c; cin >> x >> c;
            if (t == 1) {
                if (x == 1) f.push_back(c);
                else b.push_back(c);
            } else {
                if (x == 1) b.push_back(c);
                else f.push_back(c);
            }
        }
    }
    if (t == 1) {
        reverse(f.begin(), f.end());
        for (auto i : f) cout << i;
        for (auto i : s) cout << i;
        for (auto i : b) cout << i;
    } else {
        reverse(b.begin(), b.end());
        for (auto i : b) cout << i;
        reverse(s.begin(), s.end());
        for (auto i : s) cout << i;
        for (auto i : f) cout << i;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}