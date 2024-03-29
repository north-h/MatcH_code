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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
//     debug1(sum);
    if (n == 1) {
        cout << 1 << endl;
        return ;
    }
    if (n == 2 && a[1] == a[2]) {
        cout << 0 << ' ' << 0 << endl;
        return ;
    }
    int p = -1, res;
    if (sum & 1) res = (sum + 1) / 2;
    else res  = sum / 2;
    for (int i = 1; i <= n; i ++) {
        if (res  <= a[i]) {
            p = i;
            break;
        }
    }
    // debug1(p);
    if (p != -1) {
        if (sum % 2 == 0 && res = a[p]) {
            for (int i = 1; i <= n; i ++) cout << 0 << ' ';
            cout << endl;
            return ;
        }
        for (int i = 1; i <= n; i ++) {
            if (i == p) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i ++) {
            cout << 1 << ' ';
        }
        cout << endl;
    }
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
