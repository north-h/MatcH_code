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
    string ans;
    for (auto i : s) {
        int x = (i - '0');
        string str;
        while (x) {
            if (x % 2) str += '1';
            else str += '0';
            x /= 2;
        }
        while (str.size() < 3) str += '0';
        reverse(str.begin(), str.end());
        // debug2(i, str);
        if (str[0] == '1') str[0] = 'r';
        else str[0] = '-';
        if (str[1] == '1') str[1] = 'w';
        else str[1] = '-';
        if (str[2] == '1') str[2] = 'x';
        else str[2] = '-';
        ans += str;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}