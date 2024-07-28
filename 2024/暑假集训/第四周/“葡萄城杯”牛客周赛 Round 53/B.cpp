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
    int l = 0, r = s.size() - 1;
    int ans = 0;
    while (l < r) {
        char o1 = s[l], o2 = s[r];
        if (o1 > o2) {
            swap(o1, o2);
        }
        int c1 = o2 - o1;
        int c2 = 'z' - o2 + o1 - 'a' + 1;
        ans += min(c1, c2);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}