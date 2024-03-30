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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    map<int, int> mp;
    for (auto i : s) mp[i - '0'] ++;
    vector<int> arr;
    for (auto [x, y] : mp) arr.push_back(x);
    sort(arr.rbegin(), arr.rend());
    map<int, int> p;
    for (int i = 0; i < arr.size(); i ++) {
        p[arr[i]] = i;
    }
    vector<int> index(s.size());
    for (int i = 0; i < s.size(); i ++) {
        index[i] = p[s[i] - '0'];
    }
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < arr.size(); i ++) {
        if (i == arr.size() - 1) cout << arr[i];
        else cout << arr[i] << ',';
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (int i = 0; i < index.size(); i ++) {
        if (i == index.size() - 1) cout << index[i];
        else cout << index[i] << ',';
    }
    cout << "};";
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}