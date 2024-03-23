// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
	int n, w;
    cin >> n >> w;
    int num = n * 8 / w, len = w / 8;
    int x = n % len;
    debug2(num, len);
    int t = 0;
    string s;
    for (int i = 1; i <= len; i ++) s += 'a';
    auto dfs = [&](auto self, int p, int c) -> void {
        if (c > num) exit(0);
        for (char i = 'a'; i <= 'z'; i ++) {
            char op = s[p];
            s[p] = i;
            cout << s;
            self(self, p + 1, c + 1);
            s = op;
        }
    };
    dfs(dfs, 0, 0);
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}