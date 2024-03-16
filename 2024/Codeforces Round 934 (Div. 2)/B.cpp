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
    int n, k;
    cin >> n >> k;
    map<int, int> mp1, mp2;
    for (int i = 1, x; i <= n * 2; i ++) {
        cin >> x;
        if (i <= n) mp1[x] ++;
        else mp2[x] ++;
    }
    vector<int> a, b;
    for (auto [x, y] : mp1) {
        if (y == 2) {
            a.push_back(x);
            a.push_back(x);
            if ((int)a.size() == k * 2) break;
        }
    }
    for (auto [x, y] : mp2) {
        if (y == 2) {
            b.push_back(x);
            b.push_back(x);
            if ((int)b.size() == k * 2) break;
        }
    }
    if ((int)a.size() < k) {
        for (auto [x, y] : mp1) {
            if(y == 2) continue;
            a.push_back(x);
            b.push_back(x);
            if ((int)a.size() == k * 2) break;
        }
    }
    for (auto i : a) cout << i << ' ';
    cout << endl;
    for (auto i : b) cout << i << ' ';
    cout << endl;
}
 
int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}