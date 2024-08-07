// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s; cin >> s;
    vector<int> a;
    int sum = 0, res = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
        } else {
            a.push_back(res);
            res = 0;
        }
    }
    if (res) a.push_back(res);
    sort(a.rbegin(), a.rend());
    cout << a[0];
    sum += a[0];
    for (int i = 1; i < a.size(); i ++) {
        cout << '+' << a[i];
        sum += a[i];
    }
    cout << '\n';
    cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}