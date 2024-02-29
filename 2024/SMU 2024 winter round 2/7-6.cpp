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
    int n, m;
    cin >> n >> m;
    int c = 0;
    bool ok = true;
    string sans;
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i ++) {
        getline(cin, s);
        if (s.find("qiandao") != -1 || s.find("easy") != -1) continue;
        c ++;
        if (c == m + 1) {
            sans = s;
            ok = false;
        }
    }
    if (!ok) cout << sans << endl;
    else cout <<"Wo AK le" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}