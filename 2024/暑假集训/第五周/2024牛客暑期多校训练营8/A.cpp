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
    vector<int> vis(N);
    int mx = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        vis[x] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= 1e5; i ++) {
        int gc = 0;
        if (vis[i]) continue;
        for (int j = i + i; j <= 1e5; j += i) {
            if (vis[j]) gc = __gcd(j, gc);
        }
        if (gc == i) cnt ++;
    }
    if (cnt & 1) cout << "dXqwq\n";
    else cout << "Haitang\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}