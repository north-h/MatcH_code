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
    s = " " + s;
    int L;
    cin >> L;
    for (int i = 1; i <= L; i ++) {
        int n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        // debug1(s);
        string s1, s2, s3;
        s1 = s.substr(1, n - 1);
        s2 = s.substr(n, m - n + 1);
        s3 = s.substr(m + 1);
        // debug1(s1 + s2 + s3);
        string str = s1 + s3;
        // debug1(str);
        int la = (int)a.size();
        int lb = (int)b.size();
        bool f = false;
        for (int j = 0; j < (int)str.size(); j ++) {
            if (str.substr(j, la) == a && str.substr(j + la, lb) == b) {
                string ss1, ss2, ss3;
                ss1 = str.substr(0, j + la);
                ss3 = str.substr(j + la);
                s = " " + ss1 + s2 + ss3;
                f = true;
                break;
            }
        }
        if (!f) s = " " + str + s2; 
    }
    for (int i = 1; i < s.size(); i ++) cout << s[i];
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}