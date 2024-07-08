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

void solve() {
    srand((unsigned int)time(0));
    string s;
    // cin >> s;
    int n = rand() % 3 + 2;
    int x = (rand() % 3 + 1);
    int y = (rand() % 3 + 1);
    int sx = x, sy = y * x;
    s += (x + '0');
    s += 'd';
    s += (y + '0');
    for (int i = 1; i < n; i ++) {
        int xx = rand() % 2 + 1;
        if (xx == 1) s += '+';
        else s += '-';
        x = (rand() % 3 + 1);
        y = (rand() % 3 + 1);
        s += (x + '0');
        s += 'd';
        s += (y + '0');
        // debug1(xx);
        if (xx == 1) sx = min(x + sx, y * x + sx), sy = max(x + sy, y * x + sy);
        else sx = min(sx - x, sx - y * x), sy = max(sy - x, sy -  y * x);
    }
    debug1(s);
    // debug2(sx, sy);
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
    // cout << s << '\n';
    map<int, int> mp;
    int cnt = count(s.begin(), s.end(), 'd');
    vector<array<int, 2>> D;
    vector<char> oo;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'd' && i != 0 && i != s.size() - 1) {
            int ln = s[i - 1] - '0', rn = s[i + 1] - '0';
            // debug2(ln, rn);
            mp[rn] += ln;
            D.push_back({ln, ln * rn});
            i ++;
        }
        else if (s[i] >= '0' && s[i] <= '9' && check1(s, i)) D.push_back({s[i] - '0', s[i] - '0'});
        else if (s[i] == '+' || s[i] == '-') oo.push_back(s[i]);
    }
    // for (auto [x, y] : D) cout << x << ' ' << y << '\n';
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
    // for (auto [x, y] : mp) cout << x << ' ' << y << '\n';
    // cout << mn << ' ' << mx << '\n';
    if (sx == mn && sy == mx) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    cout << "-------------" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}