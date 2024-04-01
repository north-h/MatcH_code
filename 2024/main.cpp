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
const int N = 10000010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    debug2(n, s);
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    int sum = h * 60 + m + (n - 1) * 1440;
    // debug2(h, m);
    // debug1(sum);
    if (n == 0) printf("%d %02d:%02d\n", n, h, m);
    else printf("%d %02d:%02d\n", sum / 2880 + 1, sum % 2880 / 120, sum % 2880 % 120);

}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}