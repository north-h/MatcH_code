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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    unordered_map<int, int> mp, p;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    int l = 1, r = n + 1;
    vector<int> vis(n + 1);
    int t = 1;
    while (true) {
        if (l + 1 == r) break;
        int mid = l + r >> 1;
        vis[mid] = t ++;
        if (a[mid] <= x) l = mid;
        else r = mid;
    }
    for (int i = 1; i <= n; i ++) p[vis[i]] = i;
    if (a[l] == x) {
        cout << 0 << endl;
        return ;
    }
    if (!vis[mp[x]]) {
        cout << 1 << endl;
        cout << l << ' ' << mp[x] << endl;
    } else {
        cout << 2 << endl;
        int b = mp[x];
        int c = p[vis[mp[x]] + 1];
        int lst;
        if (b > c) {
            for (int i = 1; i <= n; i ++) {
                if (vis[i] && a[i] > x) {
                    cout << i << ' ' << mp[x] << endl;
                    lst = i;
                    break;
                }
            }
        } else {
            for (int i = 1; i <= n; i ++) {
                if (vis[i] && a[i] < x) {
                    cout << i << ' ' << mp[x] << endl;
                    lst = i;
                    break;
                }
            }
        }
        cout << lst << ' ' << l << endl;
    }
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