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

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<queue<char>> q(n + 1);
    vector<char> op;
    stack<char> lz;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            char b;
            cin >> b;
            q[i].push(b);
        }
    }
    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;
        if (x == 0) {
            if (lz.size()) {
                op.push_back(lz.top());
                lz.pop();
            }
        } else {
            if (q[x].size()) {
                if ((int)lz.size() == s) {
                    op.push_back(lz.top());
                    lz.pop();
                }
                lz.push(q[x].front());
                q[x].pop();
            }
        }
    }
    for (auto i : op) cout << i;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}