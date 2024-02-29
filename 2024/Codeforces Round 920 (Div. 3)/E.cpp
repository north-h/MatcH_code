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
    int  n, m, xa, ya, xb, yb;
    cin  >> n >> m >> xa >> ya >> xb >> yb;
    if (xa >= xb) {
        cout << "Draw" << endl;
        return ;
    }
    int d = xb - xa - 1, dd;
    if (d & 1) {
        if (abs(ya - yb) == 0) {
            cout << "Bob" << endl;
            return ;
        }
        if (yb > ya) dd = yb - 2;
        else dd = m - yb - 1;
        if (d >= dd * 2) cout << "Bob" << endl;
        else cout << "Draw" << endl;
        
    } else {
        if (abs(ya - yb) <= 1) {
            cout << "Alice" << endl;
            return ;
        }
        if (yb > ya) dd = m - ya - 1;
        else dd = ya - 2;
        if (d >= dd * 2) cout << "Alice" << endl;
        else cout << "Draw" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}