#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1, vector<int>(n + 1));
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> g[i][j];
                if(g[i][j] < 0)sum += g[i][j];
            }
        }
        int ans = INT_MAX;
        int res = 0;
        for(int i = 1; i <= n; i++) {
            int  mn = INT_MAX;
            for(int j = 1; j <= n; j++) {
                mn = min(mn, g[i][j]);
            }
            if(mn >= 0)res += mn;
        }
        ans = min(ans, res);
        res = 0;
        for(int i = 1; i <= n; i++) {
            int  mn = INT_MAX;
            for(int j = 1; j <= n; j++) {
                mn = min(mn, g[j][i]);
            }
            if(mn >= 0)res += mn;
        }
        ans = min(ans, res);
        cout << ans + sum << endl;
    }
    return 0;
}
