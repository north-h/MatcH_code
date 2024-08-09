#include<bits/stdc++.h>
#define int long long
#define debug(x) cout<<"LINE"<<__LINE__<<":"<<#x<<"="<<x<<endl;
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    char t;
    cin >> x >> y >> t;
    int delta = y - 1 + x - 1;
    int cor = 0;
    if (((delta & 1) and t == 'B') or (delta % 2 == 0 and t == 'A')) {
        cor = 1;
    }
    int minn = n + m;
    int maxx = (cor == 1 ? (((n - 1) * (m - 1) + 1) / 2) : (((n - 1) * (m - 1)) / 2)) + minn;
    cout << minn << ' ' << maxx << '\n';
    vector g(n + 1, vector<char>(m + 1));
    if (k < minn || k > maxx) {
        cout << "No\n";
    } else {
        //     cout << "Yes\n";
        //     int dem = k - minn;
        //     if(cor) {
        //         for(int i = 1; i <= n; ++i) {
        //             for(int j = 1; j <= m; ++j) {
        //                 if(dem == 0) {
        //                     g[i][j] = t;
        //                     continue;
        //                 }
        //                 int inx = i - 1 + j - 1;
        //                 g[i][j] = ((inx & 1) ? 'B' : 'A');
        //                 if(i >= 2 and j >= 2 and g[i][j] == 'A' and g[i][j - 1] == 'B' and g[i - 1][j] == 'B' and g[i - 1][j - 1] == 'A') {
        //                     dem--;
        //                 }
        //             }
        //         }
        //     } else {
        //         for(int i = 1; i <= n; ++i) {
        //             for(int j = 1; j <= m; ++j) {
        //                 if(dem == 0) {
        //                     g[i][j] = t;
        //                     continue;
        //                 }
        //                 int inx = i - 1 + j - 1;
        //                 g[i][j] = ((inx & 1) ? 'A' : 'B');
        //                 if(i >= 2 and j >= 2 and g[i][j] == 'A' and g[i][j - 1] == 'B' and g[i - 1][j] == 'B' and g[i - 1][j - 1] == 'A') {
        //                     dem--;
        //                 }
        //             }
        //         }
        //     }
        //     for(int i = 1; i <= n; ++i) {
        //         for(int j = 1; j <= m; ++j) {
        //             cout << g[i][j];
        //         }
        //         cout << '\n';
        //     }
        cout << 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cn = 1;
    // cin >> cn;

    while (cn--)
        solve();

    return 0;
}
