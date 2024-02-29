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
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a == 150) ans ++;
    else if (a == 200) ans += 2;
    if (b >= 34 && b <=40) ans ++;
    else if (b == 45) ans += 2;
    if (c >= 34 && c <=40) ans ++;
    else if (c == 45) ans += 2;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}