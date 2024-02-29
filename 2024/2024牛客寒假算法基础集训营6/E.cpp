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
    string a, b;
    cin >> a >> b;
    int op = 0;
    for (int i = 2; i < a.size(); i ++) {
        op = op * 10 + (a[i] - '0');
    }
    int h = 0, z = 0, ans = 0;
//     debug1(op);
    for (auto i : b) {
        if (i == 'R') h ++;
        else z ++;
//         debug2(h, z);
        if (h > op / 2) {
            cout << "kou!" << endl;
            cout << h + z << endl;
            return ;
        }
        if (z > op / 2) {
            cout << "yukari!" << endl;
            cout << h + z << endl;
            return ;
        }
    }
    cout << "to be continued." << endl;
    cout << h + z << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}