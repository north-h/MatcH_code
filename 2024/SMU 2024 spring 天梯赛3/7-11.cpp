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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct DSU {
    vector<int> fa;
 
    DSU(int n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i ++) fa[i] = i;
    }
 
    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
 
    bool same(int x, int y) {
        int px = find(x);
        int py = find(y);
        return px == py;
    }
 
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            fa[px] = py;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    DSU d(n + 1);
    while (true) {
        char s;
        cin >> s;
        if (s == 'S') {
            int cnt = 0;
            set<int> st;
            for (int i = 1; i <= n; i ++) {
                int pi = d.find(i);
                if (!st.count(pi)) {
                    st.insert(pi);
                    cnt ++;
                } 
            }
            if (cnt == 1) cout << "The network is connected." << endl;
            else cout << "There are " << cnt <<" components." << endl;
            break;
        }
        int x, y;
        cin >> x >> y;
        if (s == 'C') {
            if (d.same(x, y)) cout << "yes" << endl;
            else cout << "no" << endl;
        } else {
            d.merge(x, y);
        }
    }
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