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
    int n;
    cin >> n;
    stack<int> a, b;
    vector<int> q(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> q[i];
    }
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (a.empty() || a.top() > q[i]) a.push(q[i]);
        else {
            if (b.empty() || b.top() < q[i]) b.push(q[i]);
            else {
                sum++;
                ans = max(ans, (int)a.size());
                while (a.size()) a.pop();
                while (b.size() && b.top() > q[i]) {
                    a.push(b.top());
                    b.pop();
                }
                a.push(q[i]);
            }
        }
    }
    // debug2(a.size(), b.size());
    ans = max(ans, max((int)a.size(), (int)b.size()));
    if (a.size()) sum ++;
    if (b.size()) sum ++;
    cout << sum << ' ' << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}