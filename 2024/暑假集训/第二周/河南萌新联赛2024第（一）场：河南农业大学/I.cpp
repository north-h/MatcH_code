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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int pos = 0, mx = a[1];
    for (int i = n, cnt = 0; i >= 1; i ++) {
        cnt ++;
        if (mx < a[i]) {
            mx = a[i];
            pos = i;
        }
        if (cnt == k) break;
    }
    if (mx == a[1]) cout << 0 << '\n';
    else cout << n - pos + 1 << '\n'; 
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}