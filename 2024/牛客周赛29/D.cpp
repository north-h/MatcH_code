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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    double mv;
    int mk;
    if (n & 1) {
        mk = (n + 1) / 2;
        mv = b[mk];
        for (int i = 1; i <= n; i++) {
            if (a[i] < mv) cout << lf(1) << (b[mk] + b[mk + 1]) * 1.0 / 2 << endl;
            else if(a[i] == mv) cout << lf(1) << (b[mk - 1] + b[mk + 1]) * 1.0 / 2 << endl;
            else cout << lf(1) << (b[mk] + b[mk - 1]) * 1.0 / 2 << endl;
        }
    } else {
        mv = (b[n / 2] + b[n / 2 + 1]) * 1.0 / 2;
        for (int i = 1; i <= n; i++) {
            if (a[i] < mv) cout << lf(1) << b[n / 2 + 1] * 1.0 << endl;
            else cout << lf(1) << b[n / 2] * 1.0 << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}