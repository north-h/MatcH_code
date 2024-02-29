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
    string a, b, sa, sb;
    cin >> a >> b;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] % 2 == a[i-1] % 2) {
            sa += max(a[i], a[i-1]);
        }
    }
    for (int i = 1; i < b.size(); i++) {
        if (b[i] % 2 == b[i-1] % 2) {
            sb += max(b[i], b[i-1]);
        }
    }
    if (sa == sb) cout << sa << endl;
    else cout << sa << endl << sb << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
 //   cin >> h_h;
    while (h_h--)solve();
    return 0;
}