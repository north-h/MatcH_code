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
    string sans;
    vector<string> v;
    for (auto i : s) {
        sans += i;
        if ((sans.back() - '0') % 2 == 0) {
//             cout << sans << endl;
            v.push_back(sans);
            sans.clear();
        }
    }
    sort(v.begin(), v.end(), [](string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    for (auto i : v) cout << i << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}