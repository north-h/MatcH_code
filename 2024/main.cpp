#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int p, m;
    cin >> p >> m;
    priority_queue<int , vector<int>, less<int>>q; //大到小 xiao
    priority_queue<int, vector<int>, greater<int>>g; //小到大 da
    int tt = 0;
    int a[10000];
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (!q.size() || x <= q.top()) q.push(x);
        else g.push(x);
        // cout << q.size() << " " << g.size() << endl;
        while ((int)q.size() - (int)g.size() > 1 && q.size()) {
            // cout << q.top() << '\n';
            g.push(q.top());
            q.pop();
        }
        while ((int)g.size() - (int)q.size() > 1 && g.size()) {
            q.push(g.top());
            g.pop();
        }
        if (x % 2 != 0) {
            // tt++;
            if (i == 1) a[tt++] = x;
            else {
                if (q.size() == g.size()) a[tt++] = (q.top() + g.top()) / 2;
                else if (q.size() > g.size()) a[tt++] = q.top();
                else a[tt++] = g.top();
            }
        }
    }
    cout << p << " " << tt << endl;
    for (int i = 0; i < tt; i++) {
        if (a[i] == 0) continue;
        cout << a[i] << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}