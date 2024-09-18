// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    map<int, int> cnt;
    for (int i = 1; i <= n; i ++) {
        int x = log(1e16) / log(k) + 1;
        for (int j = x; j >= 0; j --) {
            if (ksm(k, j) <= a[i]) {
                a[i] -= ksm(k, j);
                cnt[j] ++;
            }
        }
        if (a[i]) {
            cout << "NO\n";
            return ;
        }
    }
    for (auto [x, y] : cnt) {
        if (y > 1) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}