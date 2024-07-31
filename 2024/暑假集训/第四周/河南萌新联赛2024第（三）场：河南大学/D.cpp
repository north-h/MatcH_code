// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return ;
    }
    int lst = -1, ans = 0;
    for (int i = n; i >= 2; i --) {
        if (a[i] == 0) continue;
        int j = i;
        while (a[j] == a[j - 1] && j >= 2) j --;
        ans ++;
        i = j;
    }
    if (a[0] != a[1]) ans ++;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}