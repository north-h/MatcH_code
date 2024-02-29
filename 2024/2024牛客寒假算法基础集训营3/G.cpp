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

struct edge{
    int a, b, c;
};

void solve() {
    int n;
    cin >> n;
    vector<edge> s(n);
    for (auto &[a, b, c] : s) cin >> a >> b >> c;
    auto check = [&] (int a, int b, int c) -> bool {
        vector<int> T;
        T.push_back(a);
        T.push_back(b);
        T.push_back(c);
        for (auto [x, y, z] : s) {
            if ((T[x - 1] < T[y - 1]) != z) return false;
        }
        return true;
    };
    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= 3; j ++) {
            for (int k = 1; k <= 3; k ++) {
                if (check(i, j, k)) {
                    cout << "Yes" << endl;
                    return ;
                }
            }
        }
    }
    cout << "No" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}