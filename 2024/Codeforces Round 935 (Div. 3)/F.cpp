// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1, x; i <= n; i ++) {
       cin >> x;
       b[i] = a[x];
    }
    priority_queue<int, vector<int> , greater<int>> pq;
    int ans = 0, sum = 0;
    for (int i = n; i >= 1; i --) {
        pq.push(b[i]);
        if (n - (i - 1) < i) continue;
        while ((int)pq.size() > i) pq.pop();
        if (ans <= pq.top() * i) {
            ans = pq.top() * i;
            sum = i;
        }
    }
    cout << ans << ' ' << sum << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}