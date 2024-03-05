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
    map<int, int> mp;
    vector<int> a(n + 1);
    for (int i = 1, x; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    vector<int> v, e;
    for (int i = 1; i <= n; i ++) {
        if (mp[i] > 0) mp[i] --;
        else v.push_back(i);
    }
    for (int i = 1; i <= n; i ++) {
        if(mp[a[i]] > 0) {
            e.push_back(i);
            mp[a[i]] --;
        }
    }
    cout << v.size() << endl;
    for (int i = 0, j = 0; i < v.size(); i ++, j ++) {
        cout << e[j] << ' ' << v[i] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}