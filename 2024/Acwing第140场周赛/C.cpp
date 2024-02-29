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

struct edge {
    int x, y;
    double dis;
};

void solve() {
    int  n, d;
    cin >> n >> d;
    vector<edge> p(n + 1);
    auto get = [&](int  x, int y) -> double {
        return sqrt(x * x + y * y) * 1.0 - 7.5;
    };
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].x >> p[i].y;
        p[i].dis = get(p[i].x, p[i].y);
    }
    auto check = [&](int x, int y) -> bool {
        if (x - 50 <= d || x + 50 <= d || y - 50 <= d || y + 50 <= d) 
            return true;
        return false;
    };
    auto bfs = [&]() -> void {
        queue<edge> q;
        vector<int> vis(n + 1);
        for (int i = 1; i <= n; i ++) {
            if (p[i].dis <= d) {
                q.push(p[i]);
                vis[i] = 1;
            }
        }
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (check(t.x, t.y)) {
                cout << "Yes" << endl;
                return ;
            }
            for (int i = 1; i <= n; i ++) {
                if (vis[i]) continue;
                if (p[i].dis <= t.dis + d) {
                    q.push(p[i]);
                    vis[i] = 1;
                }
            }
        }
        cout << "No" << endl;
    };
    bfs();
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}