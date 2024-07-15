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
    int x, y, z, k; cin >> x >> y >> z >> k;
    vector<int> a(x + 1), b(y + 1), c(z + 1);
    for (int i = 1; i <= x; i ++) cin >> a[i];
    for (int i = 1; i <= y; i ++) cin >> b[i];
    for (int i = 1; i <= z; i ++) cin >> c[i];
    vector<int> t;
    for (int i = 1; i <= x; i ++) {
        for (int j = 1; j <= y; j ++) {
            t.push_back(a[i] + b[j]);
        }
    }    
    sort(t.rbegin(), t.rend());
    while(t.size() > k) t.pop_back();
    int n = t.size();
    for (int i = 1; i <= z; i ++) {
        for (int j = 0; j < n; j ++) {
            t.push_back(c[i] + t[j]);
        }
    }
    reverse(t.begin(), t.end());
    for (int i = 1; i <= n; i ++) t.pop_back();
    sort(t.rbegin(), t.rend());
    for (int i = 0; i < k; i ++) cout << t[i] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}