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
    string ss = s;
    map<char, int> mp;
    char os = s[0];
    for (int i = 1, j = s.size() - 2; i < j; i ++, j --) {
        if (s[0] != s[i]) {
            swap(s[0], s[i]);
            swap(s[s.size() - 1], s[j]);
            break;
        }
    }
    if (s == ss) cout << -1 << endl;
    else cout << s << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}