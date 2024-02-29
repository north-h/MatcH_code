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
    vector<PII> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin() + 1, a.end());
    int t = 1;
    for (int i = 1; i <= n; i ++) {
        if (a[i].fi == t) t ++;
        else {
            cout << 0 << endl;
            return ;
        }
    }
    sort(a.begin() + 1, a.end(), [](PII x, PII y) {
        return x.se < y.se;
    });
    cout << 1 << endl;
    cout << 1 << ' ' << a[n].fi << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}