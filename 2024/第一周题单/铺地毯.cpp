// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct S {
    int a, b, c, d;
};

void solve() {
    int n;
    cin >> n;
    vector<S> edge;
    for (int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edge.push_back({a, b, c, d});
    }
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x1 = edge[i].a;
        int y1 = edge[i].b;
        int x2 = edge[i].c + x1;
        int y2 = edge[i].d + y1;
        if(x >= x1 && y >= y1 && x <= x2 && y <= y2) {
            ans = max(ans, i + 1);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}