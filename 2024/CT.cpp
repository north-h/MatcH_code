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
    map<int , vector<int>> mp;
    map<int, int> px, py;
    vector<int> X, Y;;
    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        mp[x].push_back(y);
        if (y == 0) X.push_back(x), px[x] ++;
        else  Y.push_back(x), py[x] ++;
    }
    int sum = 0;
    for (auto [x, y] : mp) {
        if (y.size() == 2) sum += (n - 2);
    }
    // debug1(sum);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (auto i : X) {
        if (py[i - 1] && py[i + 1]) sum ++;
    }
    for (auto i : Y) {
        if (px[i - 1] && px[i + 1]) sum ++;
    }
    cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}