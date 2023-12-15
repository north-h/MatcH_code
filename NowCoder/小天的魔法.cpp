/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-15 22:33:09
 *
 * Problem: 小天的魔法
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/72041/B
 * MemoryL: 262144 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 110;

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), b(m);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    int cnt = 0;
    while(b.size()) {
        ans += b.back();
        // debug2(ans, cnt);
        cnt++;
        b.pop_back();
        if(ans >= x) {
            cout << cnt << endl;
            return ;
        } else if(a.size() && a.back()  >= 1) {
            ans *= a.back();
            cnt++;
            a.pop_back();
            if(ans >= x) {
                cout << cnt << endl;
                return ;
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}