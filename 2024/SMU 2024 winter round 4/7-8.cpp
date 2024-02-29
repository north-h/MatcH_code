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
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++) {
            string s;
            cin >> s;
            if (k != 1) mp[s] ++;
        }
    }
    int m;
    cin >> m;
    set<string> st;
    vector<string> ans;
    while (m --) {
        string s;
        cin >> s;
        if (mp[s] == 0) {
            if (st.count(s)) continue;
            ans.push_back(s);
            st.insert(s);
        }
    }
    if (!ans.size()) cout << "No one is handsome" << endl;
    else {
        for (auto i : ans) cout << i << " \n"[i == ans.back()];
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}