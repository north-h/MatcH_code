// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

unordered_map<int, int> mp;
int vis[N];


void solve() {
    int n; cin >> n;
    mp.clear();
    int mx = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        // mp[x] = 1;
        vis[x] = 1;
        mx = max(mx, x);
    }
    if (n == 1) {
        cout << "Haitang\n";
        return ;
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
    for (int i = 1; i <= mx; i ++) vis[i] = 0;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}