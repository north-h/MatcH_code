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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    vector<int> c= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    map<int, char> mp;
    mp[0] = '1';
    mp[1] = '0';
    mp[2] = 'x';
    mp[3] = '9';
    mp[4] = '8';
    mp[5] = '7';
    mp[6] = '6';
    mp[7] = '5';
    mp[8] = '4';
    mp[9] = '3';
    mp[10] = '2';
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        int res = 0;
        bool f = true;
        for (int j = 0; j < 17; j ++) {
            if (s[j] < '0' || s[j] > '9') {
                f = false;
            }
            res += (s[j] - '0') * c[j];
        }
        res %= 11;
        if (!f) {
            cout << s << endl;
            continue;
        }
        // debug1(res);
        if (mp[res] == s.back()) cnt ++;
        else cout << s << endl;
    }
    if (cnt == n) cout << "All passed" << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}