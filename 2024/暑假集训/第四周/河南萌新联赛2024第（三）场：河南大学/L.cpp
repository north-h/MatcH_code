// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    map<string, string> gs;
    for (int i = 1; i <= n; i ++) {
        string pub, pri; cin >> pub >> pri;
        gs[pri] = pub;
    }
    map<string, map<string, set<string>>> ip;
    for (int i = 1; i <= m; i ++) {
        string IP; int x;
        cin >> IP >> x;
        for (int j = 1; j <= x; j ++) {
            string s; cin >> s; int y; cin >> y;
            for (int k = 1; k <= y; k ++) {
                string str; cin >> str;
                ip[IP][s].insert(str);
            }
        }
    }
    for (int i = 1; i <= q; i ++) {
        string mc, IP, pri; cin >> mc >> IP >> pri;
        string pub = gs[pri];
        // debug2(IP, mc);
        if (ip[IP][mc].count(pub)) {
            cout << "Yes" << '\n';
        } else cout << "No" << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}