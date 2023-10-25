/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-24 22:17:07
 *
 * Problem: D. Another Problem About Dividing Numbers
 * Contest: Codeforces - SMU Autumn 2023 Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481465/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ===========================================================================
 */
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 40010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;
vector<int> prime;
int vis[N];

int get(int x) {
    int ans = 0;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            while(x % i == 0) {
                x /= i;
                ans++;
            }
        }
    }
    if(x > 1)ans++;
    return ans;
}

int get1(int x) {
    int ans = 0;
    for(auto i : prime) {
        if(x % i == 0) {
            // debug1(i);
            while(x % i == 0) {
                x /= i;
                ans++;
            }
        }
    }
    if(x > 1)ans++;
    // debug1(x);
    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if(n > m)swap(n, m);
    int cnt = get1(n) + get1(m);
    if(m % n == 0) {
        if(m == n) {
            if(k == 0 || k > 1 && k <= cnt)cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if(k >= 1 && k <= cnt)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    } else {
        if(k >= 2 && k <= cnt)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int32_t main() {
    for(int i = 2; i < N; i++) {
        if(!vis[i]) {
            prime.push_back(i);
            for(int j = i + i; j < N; j += i) {
                vis[j] = 1;
            }
        }
    }
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}