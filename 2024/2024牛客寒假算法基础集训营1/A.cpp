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
    string s;
    cin >> n >> s;
    string s1 = "DFS", s2 = "dfs";
    int j = 0, k = 0;
    for (int i = 0; i <s.size(); i ++) {
        if (s[i] == s[j]) j ++;
        if (s[i] == s[k]) k ++;
    }
    if (j == 2) {
        cout << 1 << ' ';
    } else cout << 0 << ' ';
    if (k == 2) {
        cout << 1 << endl;
    } else cout << 0 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}