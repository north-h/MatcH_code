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
    string s; cin >> s;
    map<char, vector<int>> mp;
    for (int i = 0; i < s.size(); i ++) {
        mp[s[i]].push_back(i);
    }
    int j = n - 1;
    for (int i = 0; i < s.size(); i ++) {
        for (auto c = 'a'; c <= 'z' && c < s[i]; c ++) {
            while (mp[c].size() && mp[c].back() > j) mp[c].pop_back();
            if (mp[c].size() && mp[c].back() > i) {
                swap(s[i], s[mp[c].back()]);
                j = mp[c].back() - 1;
                mp[c].pop_back();
                break;
            }
        }
    }
    cout << s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}