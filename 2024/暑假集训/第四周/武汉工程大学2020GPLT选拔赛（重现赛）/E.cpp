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
    int l = 19 * 60 * 60, r = 21 * 60 * 60;
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[3] - '0') * 10 + (s[4] - '0');
    int c = (s[6] - '0') * 10 + (s[7] - '0');
    int sum = a * 60 * 60 + b * 60 + c;
    if (sum > r) {
        cout << "too late" << '\n';
        return ;
    }
    sum += 60 * 60 + 22 * 60 + 33;
    if (sum < l) cout << "arrive on time" << '\n';
    else if (sum >= l && sum <= r) cout << "arrive late" << '\n';
    else cout << "too late" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}