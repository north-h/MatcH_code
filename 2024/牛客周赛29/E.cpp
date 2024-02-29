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

void solve() {
    int n;
    cin >> n;
    vector <PII> zys;
    int x = n;
    int c = 0;
    if (n == 1) {
        cout << -1 << endl;
        return ;
    }
    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                c++;
                x /= i;
            }
            zys.push_back({cnt, i});
        }
    }
    if (x > 1) {
        c++;
        zys.push_back({1, x});
    }
    sort(zys.begin(), zys.end(), [] (PII x, PII y) {
        return x.fi > y.fi;
    });
    // for (auto [x, y] : zys) debug2(x, y);
    vector <int> ans (c);
    if ((c + 1) / 2 < zys[0].fi) {
        cout << -1 << endl;
        return ;
    }
    for (int i = 0, p = 0; i < zys.size(); i++) {
        while (zys[i].fi > 0) {
            ans[p] = zys[i].se;
            zys[i].fi--;
            p += 2;
            if (p >= c) p = 1;
        }
    }
    cout << c << endl;
    for (auto i : ans) cout << i << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}