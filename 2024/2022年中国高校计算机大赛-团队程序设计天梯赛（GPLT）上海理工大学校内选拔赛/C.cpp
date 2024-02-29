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

int get(string s) {
    int res = 0;
    for (auto i : s) res = res * 10 + (i - '0');
    return res;
}

void solve() {
    string s;
    getline(cin, s);
    map<string,int> mp;
    string t1, t2;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == ' ' && t1.size() && t2.size()) {
            mp[t2] += get(t1);
            t1.clear();
            t2.clear();
        }
        if (s[i] >= '0' && s[i] <= '9') t1 += s[i];
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') t2 += s[i];
    }
    mp[t2] += get(t1);
    int m;
    cin >> m;
    while ( m --) {
        string s;
        cin >> s;
        cout << mp[s] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}