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
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    stack<int> hz, jzt;
    vector<int> lsx, r;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        lsx.push_back(x);
    }
    while (hz.size() || lsx.size()) {
        if (lsx.size() == 0) {
            if (jzt.size() >= 2) {
                while (jzt.size()) {
                    cout << jzt.top() << ' ';
                    jzt.pop();
                }
                cout << endl;
            } else {
                while (jzt.size()) {
                    r.push_back(jzt.top());
                    jzt.pop();
                }
            }
            while (hz.size()) {
                lsx.push_back(hz.top());
                hz.pop();
            }
            reverse(lsx.begin(), lsx.end());
        } else {
            if (jzt.size() == 0) {
                jzt.push(lsx.back());
            } else {
                int y = lsx.back(), x = jzt.top();
                if (abs(y -  x) <= k && y > x) {
                    jzt.push(y);
                } else {
                    if (hz.size()) {
                        int z = hz.top();
                        if (abs(z - x) <= k && z > x) {
                            jzt.push(z);
                            hz.pop();
                        }
                    }
                    hz.push(y);
                }
            }
            lsx.pop_back();
        }
    }
    if (jzt.size() >= 2) {
        while (jzt.size()) {
            cout << jzt.top() << ' ';
            jzt.pop();
        }
        cout << endl;
    } else {
        while (jzt.size()) {
            r.push_back(jzt.top());
            jzt.pop();
        }
    }
    for (auto i : r) cout << i << ' ';
    cout << endl;
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