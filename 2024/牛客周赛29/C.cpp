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
    string s, s1, s2, s3;
    cin >> s;
    bool f1 = true, f2 = true;
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 4) == "xiao" && f1) {
            s1 = "xiao";
            i += 3;
            f1 = false;
        }else if(s.substr(i, 4) == "hong" && f2) {
            s2 = "hong";
            i += 3;
            f2 = false;
        }else s3 += s[i];
    }
    cout << s1 + s2 + s3 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}