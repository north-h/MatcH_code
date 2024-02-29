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
    map<string,int> mp;
    int n;
    cin  >> n;
    for (int i = 1; i <= n; i ++) {
        string a, b;
        cin >> a>> b;
        mp[a] ++;
        mp[b] ++;
    }
    string sans;
    int c = 0;
    for (auto [x, y] : mp) {
        if (y > c) {
            sans = x;
            c = y;
        }
    }
    int sum = 0;
    for (auto [x, y] : mp) {
        if (y == c) {
            sum ++;
            sans = min(sans, x);
        }
    }
    cout << sans << ' ' << c; 
    if (sum > 1) cout << ' ' << sum;
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}