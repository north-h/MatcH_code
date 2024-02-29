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

struct edge{
    int a, b, c;
};

void solve() {
    vector<int> v(2);
    v[0] = 0, v[1] = 1;
    for (int i = 2; v.back() < 1e9 + 10; i ++) {
        int n = v.size();
        v.push_back(v[n - 1] + v[n - 2]);
    }
    // for (auto i : v) cout << i << ' ';
    // cout << endl;
    map<int, edge> mp;
    for (auto i : v) {
        for (auto j : v) {
            for (auto k : v) {
                mp[i + j + k] = {i, j, k};
            }
        }
    }
    int q;
    cin >> q;
    while (q --) {
        int n;
        cin >> n;
        if (mp.count(n)) cout << mp[n].a << ' ' << mp[n].b << ' ' << mp[n].c << endl;
        else cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}