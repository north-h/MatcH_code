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
double  n;

void solve() {
    int x;
    cin >> x;
    vector<pair<double, string>> a;
    for (int i = 0; i < x; i ++) {
        getline(cin, s);
        getline(cin, s);
        cin >> n;
        a.push_back({n, s});
    }
    sort(a.begin(), a.end());
    cout << lf(2) << a.back().fi * 1.0 << ", " << a.back().se << endl;
    cout << lf(2) << a.front().fi * 1.0 << ", " << a.front().se << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}