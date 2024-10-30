// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    auto b = a;
    vector<array<int, 2>> v(m + 1);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    for (int i = 1; i <= m; i ++) {
        cin >> v[i][0] >> v[i][1];
        pq.push({v[i][0], v[i][1]});
    }
    for(int i = 1; i <= m; i ++) {
        
    }    
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}