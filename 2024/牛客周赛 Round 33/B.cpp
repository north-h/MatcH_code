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
    int  n, k, x;
    cin >> n >> x >> k;
    vector<int> ans;
    int sum = 0, c = 0;
    for (int i = 1; i <= n; ) {
        if (sum >= k) {
            ans.push_back(c);
            c = 0;
            sum -= k;
        } else {
            sum += x;
            c ++;
            i ++;
        }
    }
    while (sum >= k) {
        sum -= k;
        ans.push_back(c);
        if (c)  c = 0;
    }
    cout << ans.size() << endl;
    for (auto i :ans) cout << i <<' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}