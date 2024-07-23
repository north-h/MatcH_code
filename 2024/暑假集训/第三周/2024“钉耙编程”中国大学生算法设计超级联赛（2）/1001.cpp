// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1 2\n";
    } else if (n == 2) {
        cout << "1 2\n1 3\n";
    } else if (n == 3) {
        cout << "1 2\n1 3\n1 4\n";
    } else if (n == 4) {
        cout << "1 2\n1 3\n1 4\n1 5\n";
    } else if (n == 5) {
        cout << "1 2\n1 3\n1 4\n1 5\n1 6\n";
    } else if (n == 6) {
        cout << "1 2\n1 3\n1 4\n1 5\n2 3\n2 4\n";
    } else {
        vector<array<int, 2>> ans;
        int x = n / 3, y = n % 3;
        int idx = 0;
        for (int i = x; i >= 1; i --) {
            if (i > 3) {
                ans.push_back({2, i});
                ans.push_back({3, i});
                ans.push_back({1, i});
            } else if (i == 3) {
                ans.push_back({i, x + 1});
                ans.push_back({2, 3});
                ans.push_back({1, 3});
            } else if (i == 2) {
                ans.push_back({2, x + 1});
                ans.push_back({2, x + 2});
                ans.push_back({1, 2});
            } else {
                ans.push_back({1, x + 1});
                ans.push_back({1, x + 2});
                ans.push_back({1, x + 3});
                idx = x + 3;
            }
        }
        while (y --) {
            ans.push_back({1, ++ idx});
        }
        sort(ans.begin(), ans.end());
        for (auto [x, y] : ans) cout << x << ' ' << y << '\n';

    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}