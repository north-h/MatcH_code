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
    string s1, s2;
    cin >> s1;
    s2 = s1;
    s1 = " " + s1;
    reverse(s2.begin(), s2.end());
    s2 = " " + s2;
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 1; i < s1.size(); i++){
        for (int j = 1; j < s2.size(); j++){
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << s1.size() - dp[s1.size() - 1][s2.size() - 1] - 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}