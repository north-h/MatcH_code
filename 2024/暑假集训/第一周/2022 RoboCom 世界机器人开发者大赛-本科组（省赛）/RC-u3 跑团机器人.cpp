// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

bool check(char op) {
    return (op < '0' || op > '9');
}

bool check1(string s, int p) {
    if (p == 0) return (s[p + 1] == '+' || s[p + 1] == '-');
    else if (p == s.size() - 1) return (s[p - 1] == '+' || s[p - 1] == '-');
    else {
        return (s[p + 1] == '+' || s[p + 1] == '-') && (s[p - 1] == '+' || s[p - 1] == '-');;
    }
}

bool check3(char op) {
    return (op >= '0' || op <= '9');
}

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size() - 1; i ++) {
        if (s[i] == 'd') {
            if (check(s[i + 1])) s.insert(i + 1, "1");
            if (check(s[i - 1])) s.insert(i, "1");
        }
    }
    if (s[0] == 'd') {
        if (s.size() == 1) {
            s += "1";
            s.insert(0, "1");
        } else {
            if (check(s[1])) s.insert(1, "1");
            s.insert(0, "1");
        }
    }
    if (s.back() == 'd' && s.size() > 1) {
        if (check(s.back())) s.insert(s.size() - 1, "1");
        s += "1";
    }
    map<int, int> mp;
    vector<array<int, 2>> D;
    vector<char> oo;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '+' || s[i] == '-') {
            oo.push_back(s[i]);
            continue;
        }
        int sum1 = 0, j = i;
        while (s[j] >= '0' && s[j] <= '9' && j < s.size()) {
            sum1 = sum1 * 10 + s[j] - '0';
            j ++;
        }
        if (j == s.size() || s[j] != 'd') {
            D.push_back({sum1, sum1}), i = j - 1;
        }
        else {
            int sum2 = 0;
            j ++;
            while (s[j] >= '0' && s[j] <= '9' && j < s.size()) {
                sum2 = sum2 * 10 + s[j] - '0';
                j ++;
            }
            D.push_back({sum1, sum1 * sum2});
            mp[sum2] += sum1;
            i = j - 1;
        }
    }
    int mx = D[0][1], mn = D[0][0];
    for (int i = 1; i < D.size(); i ++) {
        if (oo[i - 1] == '+') {
            mx += D[i][1];
            mn += D[i][0];
        } else {
            mx -= D[i][0];
            mn -= D[i][1];
        }
    }
    for (auto [x, y] : mp) cout << x << ' ' << y << '\n';
    cout << mn << ' ' << mx;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}