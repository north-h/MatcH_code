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
    string s;
    cin >> s;
    int p = -1;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '1') {
            p = i;
            break;
        }
    }
    if (p == -1) {
        cout << 0 << endl;
        return ;
    }
    vector<int> a(s.size() + 2);
    for (int i = s.size() - 1; i > p; i --) {
        if (s[i] == '1') {
            a[i] = 1;
            a[i] += a[i + 1];
        } else {
            a[i] = -1;
            a[i] += a[i + 1];
        }
    }
    int ans = 0;
    for (int i = s.size(); i > p; i --) {
        ans = max(ans, a[i]);
    }
    cout << ans + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}