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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= m; i ++) cin >> b[i];
    int mna = INF, mxa = -INF, mnb = INF, mxb = -INF;
    int san = a[1], sbn = b[1], sax = a[1], sbx = b[1];
    for (int i = 2; i <= n; i ++) {
        sax = max(sax + a[i], a[i]);
        mxa = max(sax, mxa);
        san = min(san + a[i], a[i]);
        mna = min(san, mna);
    }
    for (int i = 2; i <= m; i ++) {
        sbx = max(sbx + b[i], b[i]);
        mxb = max(sbx, mxb);
        sbn = min(sbn + b[i], b[i]);
        mnb = min(sbn, mnb);
    }
    // debug2(mxa, mna);
    // debug2(mxb, mnb);
    cout << max({mna * mnb, mxa * mxb, mxa * mnb, mna * mxb}) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}