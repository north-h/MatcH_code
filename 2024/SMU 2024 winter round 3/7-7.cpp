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

string s;

void solve() {
    getline(cin, s);
    // cout << s << endl;
    string x = "qiao ben zhong.";
    int n = s.size();
    if (s[n - 4] != 'o' || s[n - 3] != 'n' || s[n - 2] != 'g') {
        cout << "Skipped" << endl;
        return ;
    }
    int p;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == ',') {
            p = i;
            break;
        }
    }
    if (s[p - 3] != 'o' || s[p - 2] != 'n' || s[p - 1] != 'g') {
        cout << "Skipped" << endl;
        return ;
    }
    int sum = 0;
    for (int i = n - 1, j = 0; i >= 0; i --, j ++) {
        if (s[i] == ' ') sum ++;
        if (sum == 3) {
            cout << s.substr(0, n - j)  << x << endl;
            return ;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    getline(cin, s);
    while (h_h--)solve();
    return 0;
}