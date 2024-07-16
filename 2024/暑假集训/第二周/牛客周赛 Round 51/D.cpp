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
    string a; int b;
    cin >> a >> b;
    int sum = 0, i;
    for (i = 0; i + 9 < a.size(); i ++) {
        sum = (sum * 10 + (a[i] - '0')) % b;
    }
    for (; i < a.size(); i ++) {
        sum = sum * 10 + (a[i] - '0');
    }
    // debug1(sum);
    cout << __gcd(sum, b) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}