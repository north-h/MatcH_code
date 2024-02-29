// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
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
    int op, x, y;
};

void solve() {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    vector <edge> ans;
    int g = __gcd(x, y);
    int res = x * y / g;
    if (res == y || res == x) {
        cout << 0 << endl;
        return ;
    }
    res /= g;
    ans.push_back({1, x, y});
    ans.push_back({1, x, y});
    int c = 0, s = 1;
    while (s <= res) s <<= 1, c ++;
    for (int i = 1, j = g; i < c; i ++, j *= 2) {
        ans.push_back({2, j, j});
        ans.push_back({2, j, j});
    }
    vector <int> r;
    for(int i = 0; i <= 60; i ++){
        if((res >> i) & 1){
            r.push_back(1ll << i);
        }
    }
    int sum = r[0] * g;
    for (int i = 1; i < r.size(); i ++) {
        ans.push_back({2, sum, r[i] * g});
        sum += r[i] * g;
    }
    cout << ans.size() << endl;
    for (auto [op, x, y] : ans) cout << op << ' ' << x << ' ' << y << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}