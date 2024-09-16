//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;

const int N = 1e5 + 10, M = 210;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
ll n;
int a[16];
int s[N], idx, ned[N];
ll dp[N], lef[N];
void solve() {
    ll w; cin >> n >> w;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int len; cin >> len;
        a[len - 1]++;
        mp[len - 1] ++;
    }
    const int mm = 1 << (int)mp.size();
    for (int mask = 0; mask < mm; mask++) {
        int sum = 0;
        for (int i = 0; i < (int)mp.size(); i++) if (mask & 1 << i) sum += a[i];
        if (sum <= w) s[++idx] = mask, ned[idx] = sum;
    }
    memset(dp, 0x3f, sizeof dp);
    for (int mask = 0; mask < mm; mask++) lef[mask] = w;
    dp[0] = 1;
    for (int mask = 0; mask < mm; mask++) {
        for (int i = 1; i <= idx; i++) {              //1<<13 < 1e4
            int nmask = mask | s[i];
//          dp[nmask]=min(dp[mask]+cnt[i],dp[nmask]);
            if (ned[i] <= lef[mask]) {
//              if(dp[nmask]>dp[mask]) dp[nmask]=dp[mask],lef[nmask]-=ned[i];
                if (dp[nmask] > dp[mask]) dp[nmask] = dp[mask], lef[nmask] = lef[mask] - ned[i];
                else if (dp[nmask] == dp[mask]) lef[nmask] = max(lef[mask] - ned[i], lef[nmask]);
            } else {
                if (dp[nmask] > dp[mask] + 1) dp[nmask] = dp[mask] + 1, lef[nmask] = w - ned[i];
                else if (dp[nmask] == dp[mask] + 1) lef[nmask] = max(w - ned[i], lef[nmask]);
            }
        }
    }
    cout << dp[mm - 1];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(0));
    int O_o = 1;
//  cin >> O_o;
    while (O_o--) solve();
    return 0;
}
//make it count
//开ll plz