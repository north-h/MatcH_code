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
    int n, m, p;
    cin >> n >> m >> p;
    if (n == 1) {
        cout << "YangQiShaoNian" << endl;
    } else if (m >= n) {
        cout << "XiaoNian" << endl;
    } else {
        if (n - m == 1||p == 0) cout << "XiaoNian" << endl;
        else cout << "YangQiShaoNian" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}