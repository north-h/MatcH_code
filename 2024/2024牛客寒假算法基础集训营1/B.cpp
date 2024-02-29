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
    int ans = 3;
    vector<int> v1;
    set<int> v2;
    bool l = false, r = false;
    for (int i = 1; i <= n;  i++) {
        int x, y;
        cin >> x >> y;
        if (y <= 0) l = true;
        if (y >= 0) r = true;
        if (x == 2 && y == 0 ||x == 1 && y == -1 || x == 1 && y == 1) ans --;
        if (x == 2) v1.push_back(y);
        if (x == 1) v2.insert(y);
    }
    bool bl=false, br = false;
    for (auto i : v1) {
        if (i < 0) {
            if (v2.count(i + 1) || v2.count(i - 1) || v2.count(i)) {
                bl = true;
            }
        }
        if (i > 0) {
            if (v2.count(i + 1) || v2.count(i - 1) || v2.count(i)) {
                br = true;
            }
        }
    }
//     debug2(bl, br);
//     debug2(l, r);
    if (bl && br) ans = min(ans, 0);
    else if (!bl && !br) {
        int res = 4;
        if (l) res --;
        if (r) res --;
        ans = min(ans, res);
    }
    else {
        if (bl) {
            if (r) ans = min(ans, 1);
            else ans = min(ans, 2);
        } else {
            if (l) ans = min(ans, 1);
            else ans = min(ans, 2);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}