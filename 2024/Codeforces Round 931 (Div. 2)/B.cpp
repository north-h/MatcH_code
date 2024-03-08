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
    vector<int> a(n + 1);
    set<int> s1, s2;
    for (int i = 0; i <= n; i ++) {
        s1.insert(i);
        s2.insert(i);
    }
    map<int, int> mp;
    for (int i = 1; i<= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
        s1.erase(a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        mp[a[i]] --;
        if (mp[a[i]] == 0) s1.insert(a[i]);
        s2.erase(a[i]);
        if (*s1.begin() == *s2.begin()) {
            cout << 2 << endl;
            cout << 1 << ' ' << i << endl;
            cout << i + 1 << ' ' << n << endl;
            return ;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}