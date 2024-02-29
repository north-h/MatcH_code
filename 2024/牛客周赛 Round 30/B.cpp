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
    map<int,int> mp;
    for (auto i : s) {
        mp[(i - '0')] ++;
    }
    sort(s.begin(), s.end());
    int p;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] != '0') {
            p = i;
            break;
        }
    }
    cout << s[p];
    for (int i = 0; i < mp[0]; i ++) cout << 0;
    for (int i = p + 1; i < s.size(); i ++) cout << s[i];
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}