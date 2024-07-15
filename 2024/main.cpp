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
    map<string, vector<string>> g;
    set<string> st;
    for (int i = 1; i <= n; i ++) {
        string a, b, c , d;
        cin >> a >> b >> c >> d;
        string s1 = a + b, s2 = c + d;
        g[s1].push_back(s2);
        // g[s2].push_back(s1);
        st.insert(s1);
        st.insert(s2);
    }
    // for (auto [x, y] : g) {
    //     cout << x << ':';
    //     for (auto j : y) cout << j << ' ';
    //     cout << '\n';
    // }
    bool ok;
    vector<string> ans;
    map<string, int> mp;
    vector<vector<string>> ca;
    auto dfs = [&](auto && dfs, string s) -> void {
        // debug1(ans.size());
        if (ans.size() > 1) {
            string s1 = ans.front(), s2 = ans.back();
            int n1 = s1.size(), n2 = s2.size();
            if (n1 == n2 && s1.substr(0, n1 - 1) == s2.substr(0, n2 - 1) && s1.back() != s2.back()) {
                ca.push_back(ans);
                return ;
            }
        }
        for (auto i : g[s]) {
            ans.push_back(i);
            mp[i] = 1;
            dfs(dfs, i);
            ans.pop_back();
            mp[i] = 0;
        }
    };
    for (auto i : st) {
        vector<string>().swap(ans);
        mp[i] = 1;
        ans.push_back(i);
        dfs(dfs, i);
        ans.pop_back();
        mp[i] = 0;
    }
    sort(ca.begin(), ca.end(), [&](vector<string> x, vector<string> y) {
        return x.size() < y.size();
    });
    for (int i = 0; i < ca[0].size(); i ++) {
        int n = ca[0].size() - 1;
        cout << ca[0][i].substr(0, n - 1) << ' ' << ca[0][i].back() << ' ';
    }
    cout << "= ";
    int nm = ca[0].front().size(), mn = ca[0].back().size();
    cout << ca[0].front().substr(0, nm- 1) << ' ' << ca[0].back().back() << ' ';
    cout << ca[0].back().substr(0, mn - 1) << ' ' << ca[0].back().back() << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}