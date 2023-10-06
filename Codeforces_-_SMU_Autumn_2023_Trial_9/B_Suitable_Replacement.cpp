/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-05 10:26:49
 *
 * Problem: B. Suitable Replacement
 * Contest: Codeforces - SMU Autumn 2023 Trial 9
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475596/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    map<char, int> pa, pb;
    int sum = 0;
    for(auto i : a) {
        pa[i]++;
        if(i == '?')sum++;
    }
    for(auto i : b) {
        pb[i]++;
    }
    // for(auto [x, y] : pb)cout << x << ' ' << y << endl;
    vector<char> ans;
    // cout << endl;
    // for(auto [x, y] : pa)cout << x << ' ' << y << endl;
    // debug1(sum);
    if(sum == 0) {
        cout << a << endl;
        return ;
    }
    while(sum) {
        for(auto [x, y] : pb) {
            if(pa[x] >= y)pa[x] -= y;
            else {
                int res = y - pa[x];
                for(int i = 0; i < res; i++)ans.push_back(x);
                sum -= res;
                if(sum <= 0)break;
            }
        }
    }
    reverse(ALL(ans));
    for(auto i : a) {
        if(i != '?')cout << i;
        else {
            cout << ans.back();
            ans.pop_back();
        }
    }
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}