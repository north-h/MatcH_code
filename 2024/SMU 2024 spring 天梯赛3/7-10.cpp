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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    string sans;
    stack<char> stk;
    vector<PII> ans;
    for (int i = 0, j = 0; i < a.size() && j < b.size(); i ++) {
        if (a[i] == b[j]) {
            sans += b[j];
            j ++;
            ans.push_back({1, 2});
        } else {
            // debug1(stk.top());
            while (stk.size() && stk.top() == b[j] && j < b.size()) {
                // debug2(stk.top(), b[j]);
                ans.push_back({3, 2});
                sans += b[j];
                stk.pop();
                j ++;
            }
            if (a[i] == b[j]) {
                sans += b[j ++];
                ans.push_back({1, 2});
            } else {
                stk.push(a[i]);
                ans.push_back({1, 3});
            }
        }
    }
    while (stk.size()) {
        sans += stk.top();
        ans.push_back({3, 2});
        stk.pop();
    }
    if (sans != b) cout << "Are you kidding me?" << endl;
    else {
        for (auto [x, y] :ans) cout << x << "->" << y << endl; 
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}