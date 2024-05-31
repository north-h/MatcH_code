#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N = 998244353;
#define PII pair<int,int>
void solve() {
    int n, mi = INT_MAX, mi1 = INT_MAX;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i], mi1 = min(mi1, a[i]);
    for (int i = 0; i < n + 1; i++) cin >> b[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    for (int i = 0; i < n; i++) {
        mi = min(mi, abs(a[i] - b[n]));
    }
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        if ((b[i] >= b[n] && a[i] <= b[n]) || (a[i] >= b[n] && b[i] <= b[n])) {
            ok = 1;
            break;
        }
        mi = min(abs(b[i] - b[n]), mi);
    }
    if (ok) ans++;
    if (!ok) ans += mi + 1;
    cout << ans << endl;
}
signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}