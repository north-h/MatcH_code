// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
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

struct S {
    int a, b, c;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<S> c;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        c.push_back({a, b, b - a});
    }
    sort(c.begin(), c.end(), [](S x, S y) {
        if(x.c > 0 && y.c > 0)return x.a < y.a;
        else if(x.c < 0 && y.c < 0)return x.b > y.b;
        else return x.c > y.c;
    });
    for (int i = 0; i < c.size(); i++) {
        m -= c[i].a;
        if(m < 0) {
            cout <<  "No" << endl;
            return ;
        }
        m += c[i].b;
    }
    cout << "Yes" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}