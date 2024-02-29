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
    vector <int> mp(3e5 + 10);
    vector <int > a(n + 1), ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == -1) {
            ans.push_back(i);
        }else mp[a[i]] = i;
    };
    while((int)ans.size() < n) {
        ans.push_back(mp[ans.back()]);
    }
    for (auto i : ans) cout << i << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}