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

int ans;

bool check(int x) {
    int res = 0;
    while(x) {
        res += x % 10;
        x /= 10;
    }
    return ans == res;
}

void solve() {
    int n;
    cin >> n;
    int x = n;
    ans = 0;
    while(x) {
        ans += x % 10;
        x /= 10;
    }
    // debug1(ans);
    for (int i = 2; i <= 9; i ++) {
        if (!check(i * n)) {
            cout << "NO" << endl;
            return ;
        }
        // debug2(i * n, check(i * n));
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