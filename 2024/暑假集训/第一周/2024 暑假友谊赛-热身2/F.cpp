// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    int A = 0, B = 0, AB = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        string s; cin >> s;
        // debug2(s[0], s.back());
        if (s[0] == 'B' && s.back() == 'A') {
            AB ++;
            for (int j = 1; j < s.size() - 2; j ++) {
                ans += (s.substr(j, 2) == "AB");
            }
        } 
        else if (s[0] == 'A' && s.back() == 'B') {
            for (int j = 0; j < s.size() - 1; j ++) {
                ans += (s.substr(j, 2) == "AB");
            }
        } 
        else if (s[0] == 'B') {
            B ++;
            for (int j = 1; j < s.size() - 1; j ++) 
                ans += (s.substr(j, 2) == "AB");
        }
        else if (s.back() == 'A') {
            A ++;
            for (int j = 0; j < s.size() - 2; j ++) {
                ans += (s.substr(j, 2) == "AB");
            }
        }
        else {
            for (int j = 0; j < s.size() - 1; j ++) {
                ans += (s.substr(j, 2) == "AB");
            }
        }
    }
    // int mn = min({A, B, AB});
    // debug2(A, B);
    // debug2(AB, ans);
    // ans += max(0ll, AB - 1);
    if (AB) {
        ans += AB - 1;
        if (A) A --, ans ++;
        if (B) B --, ans ++;
    }
    ans += min(A, B);
    // debug2(ans, min(A, B));
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}