// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int ans, n;
string sans, t, s;

bool check(string s) {
    stack<int> stk;
    for (auto i : s) {
        if (stk.empty() || i == '(' || i == '[') stk.push(i);
        else {
            if (i == ']') {
                if (stk.top() != '[') return false;
                else stk.pop();
            } else {
                if (stk.top() != '(') return false;
                else stk.pop();
            }
        }
    }
    if (stk.empty()) return true;
    return false;
}

void dfs(int u) {
    if (u == n) {
        // debug1(sans);
        if (check(sans)) ans ++;
        return ;
    }

    if (s[u] == 'o') {
        sans += '(';
        dfs(u + 1);
        sans.pop_back();
        sans += ')';
        dfs(u + 1);
        sans.pop_back();
    } else {
        sans += '[';
        dfs(u + 1);
        sans.pop_back();
        sans += ']';
        dfs(u + 1);
        sans.pop_back();
    }
}

void solve() {
    sans.clear();
    s.clear();
    ans = 0;
    cin >> t;
    for (auto i : t) {
        if (i == ')' || i == '(') s.append("o");
        else s.append("x");
    }
    // cout << s << '\n';
    s = " " + s;
    n = (int)s.size();
    dfs(1);
    // debug1(ans);
    if (ans == 1) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}