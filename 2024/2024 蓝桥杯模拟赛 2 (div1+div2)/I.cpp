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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    while (m --) {
        int l, r;
        cin >> l >> r;
        bool f = false;
        map<int,int> vis;
        for (int i = l; i <= r; i ++) {
            vis[a[i]] = 1;
        }
        bool ok = false;
        for (int i = l; i <= r; i ++) {
            int aj = (a[i] ^ x);
            if (vis[aj]) {
                ok = true;
                break;
            }
            
        }
        if (ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}