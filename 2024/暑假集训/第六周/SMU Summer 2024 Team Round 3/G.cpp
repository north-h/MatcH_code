// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 20;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int x; string s; cin >> s >> x;
    int sum = 0;
    for (int i = 0; i < s.size() - 1; i ++) {
        int res = (s[i] - '0');
        if (res >= x) res --;
        for (int j = i + 1; j < s.size(); j ++) res *= 9;
        sum += res;
        // debug1(sum);
        res = 1;
        for (int j = i + 1; j < s.size(); j ++) {
            int c = s[j] - '0';
            if (c < x) c ++;
            res *= c;
        }
        // debug1(res);
        sum += res;
    }
    cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}