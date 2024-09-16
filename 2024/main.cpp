#include <bits/stdc++.h>
using namespace std;
#define int long long
//const int N = 2e5+10;
//int n, k;
//char ans[N];
int numofword[16];
int tongji[15];
bool vis[15];
int l; int ans;
int n, w;
int cnt = 1;

void dfs(int now, int days, int numw) { //共学了now个，在第days天，马上要学numw个
    //cout<<now<<" "<<days<<" "<<numw<<'\n';
    if (now == cnt) {
        ans = min(ans, days + (numw == 0 ? 0 : 1));
    }
    else {
        if (days + (numw == 0 ? 0 : 1) >= ans) return;
        bool flag = 1;
        for (int i = 1; i <= cnt; i++) {
            if (!vis[i]) {
                if (numw + tongji[i] <= w) {
                    vis[i] = 1;
                    if (numw + tongji[i] == w) {
                        dfs(now + 1, days + 1, 0);
                    }
                    else dfs(now + 1, days, numw + tongji[i]);
                    vis[i] = 0;
                    flag = 0;
                }
            }
        }
        if (flag) {
            for (int i = 1; i <= cnt; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    dfs(now + 1, days + 1, tongji[i]);
                    vis[i] = 0;
                    return ;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> l;
        numofword[l]++;
    }

    for (int i = 1; i < 14; i++) {
        if (numofword[i]) tongji[cnt++] = numofword[i];
    }
    //cout<<"cnt "<<cnt<<'\n';
    ans = 0x3f3f3f3f;
    dfs(0, 0, 0);
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}