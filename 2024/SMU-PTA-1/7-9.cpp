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
    int n, m, k;
    cin >> n >> m >> k;
    stack <int> hezi;
    queue <int> q;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        q.push(x);
    }
    while (q.size() || hezi.size()) {
        vector <int> zhigan;
        if (hezi.size()) {
            zhigan.push_back(hezi.top());
            hezi.pop();
        } else {
            zhigan.push_back(q.front());
            q.pop();
        }

        while (true) {
            if (hezi.size()) {
                if (zhigan.back() >= hezi.top()){
                    zhigan.push_back(hezi.top());
                    hezi.pop();
                } else { 
                    if (q.size()) {
                        if (zhigan.back() >= q.front()) {
                            zhigan.push_back(q.front());
                            q.pop();
                        } else {
                            if ((int)hezi.size() < m) {
                                hezi.push(q.front());
                                q.pop();
                            } else break;
                        }
                    } else break;
                }
            } else {
                if (q.size()) {
                    if (zhigan.back() >= q.front()) {
                        zhigan.push_back(q.front());
                        q.pop();
                    } else {
                        if ((int)hezi.size() < m) {
                            hezi.push(q.front());
                            q.pop();
                        } else break;
                    }
                } else break;
            }
            if ((int)zhigan.size() == k) break;
        }
        // for (auto i : zhigan) cout << i << " \n"[i == zhigan.back()];
        for (int i = 0; i < zhigan.size(); i ++) {
            cout << zhigan[i] << " \n"[i == zhigan.size() - 1];
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}