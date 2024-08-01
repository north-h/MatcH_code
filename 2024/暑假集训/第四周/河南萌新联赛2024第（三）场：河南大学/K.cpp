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
    for (int i = 1; i <= n; i ++) cin >> a[i];
    stack<int> stk;
    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i ++) {
        if (stk.size() == 0) stk.push(a[i]);
        else {
            while (stk.size() && stk.top() > a[i]) stk.pop();
            stk.push(a[i]);
        }
        pre[i] = stk.size() - 1;
    }
    while (stk.size()) stk.pop();
    for (int i = n; i >= 1; i --) {
        if (stk.size() == 0) stk.push(a[i]);
        else {
            while (stk.size() && stk.top() > a[i]) stk.pop();
            stk.push(a[i]);
        }
        suf[i] = stk.size() - 1;
    }
    for (int i = 1; i <= n; i ++) {
        cout << pre[i] + suf[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}