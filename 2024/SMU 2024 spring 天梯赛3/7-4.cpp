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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool f = false;
    if (c > d) {
        swap(c, d);
        f = true;
    }
    if (c < a && d >= b) {
        if (f) {
            cout << d << "-Y " << c << "-Y" << endl;
            cout << "qing " << 1 << " zhao gu hao " << 2 << endl;
        } else {
            cout << c << "-Y " << d << "-Y" << endl;
            cout << "qing " << 2 << " zhao gu hao " << 1 << endl;
        }
    } else if (c >= a && d >= a) {
        if (f) {
            cout << d << "-Y " << c << "-Y" << endl;
        } else {
            cout << c << "-Y " << d << "-Y" << endl;
        }
        cout << "huan ying ru guan" << endl;
    } else if (c < a && d < a) {
        if (f) {
            cout << d << "-N " << c << "-N" << endl;
        } else {
            cout << c << "-N " << d << "-N" << endl;
        }
        cout << "zhang da zai lai ba" << endl;
    } else {
        if (f) {
            cout << d << "-Y " << c << "-N" << endl;
            cout << 1 << ": huan ying ru guan" << endl;
        } else {
            cout << c << "-N " << d << "-Y" << endl;
            cout << 2 << ": huan ying ru guan" << endl;
        }
    }
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