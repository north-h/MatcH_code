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
    vector<int> a;
    map<int, PII> mp;
    for (int i = 0; i * i <= n; i ++) {
        for (int j = 0; j * j + i * i <= n; j ++) {
            int t = i * i + j * j;
            if (mp.count(t)) continue;
            mp[t] = {i, j};
        }
    }
    for (int i = 0; i * i <= n; i ++) {
        for (int j = 0; j * j + i * i <= n; j ++) {
            int t = n - i * i - j * j;
            if (mp.count(t)) {
                cout << i << ' ' << j << ' ' << mp[t].fi << ' ' << mp[t].se << endl;
                return ;
            }
        }
    }    
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}