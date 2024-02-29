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
    vector<string> tg = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
    vector<string> dz = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
    vector<string> ans;
    map<string, int> mp;
    for (int i = 0, j = 0; ans.size() < 60; i ++, j ++) {
        i %= 10;
        j %= 12;
        ans.push_back(tg[i] + dz[j]);
    }
    // int t= 1;
    // for (auto i : ans) cout << i << ' ' << t ++ << endl;
    // cout << endl;
    // cout << ans.size() << endl;
    int n;
    cin >> n;
    n %= 60;
    cout << ans[(n - 4 + 60) % 60] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}