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
    int n; cin >> n;
    map<int, int> mp;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    if (mp.size() == 1) {
        cout << "YES" << '\n';
        return ;
    }
    if (mp.count(1)) {
        if (mp.count(0)) {
            cout << "NO" << '\n';
            return ;
        }
        for (int i = 1; i <= n; i ++) {
            if (a[i] <= 1) continue;
            if (mp.count(a[i] - 1)) {
                cout << "NO" << '\n';
                return ;
            }
        }
        cout << "YES" << '\n';
    } else cout << "YES" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}