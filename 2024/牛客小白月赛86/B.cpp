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
    string s, f;
    cin >> s >> f;
    if (f.size() == 1 && s != f || s.size() > f.size() ) cout << 0 << endl;
    else {
        for (int i = 0; i < s.size(); i++) {
            if (f.find(s[i]) == -1) {
                cout << 0 << endl;
                return ;
            }
        }
        cout << 10 << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}