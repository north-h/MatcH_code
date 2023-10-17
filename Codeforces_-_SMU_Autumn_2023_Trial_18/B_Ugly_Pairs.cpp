/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-17 17:57:25
 *
 * Problem: B. Ugly Pairs
 * Contest: Codeforces - SMU Autumn 2023 Trial 18
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/479352/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto i : s)mp[i]++;
    vector<char> a;
    for(auto [x, y] : mp) {
        a.push_back(x);
    }
    string sans1;
    for(int i = 0; i < a.size(); i += 2) {
        for(int j = 0; j < mp[a[i]]; j++)sans1 += a[i];
    }
    for(int i = 1; i < a.size(); i += 2) {
        for(int j = 0; j < mp[a[i]]; j++)sans1 += a[i];
    }
    string sans2;
    for(int i = 1; i < a.size(); i += 2) {
        for(int j = 0; j < mp[a[i]]; j++)sans2 += a[i];
    }
    for(int i = 0; i < a.size(); i += 2) {
        for(int j = 0; j < mp[a[i]]; j++)sans2 += a[i];
    }
    // debug2(sans1, sans2);
    bool ok1 = true, ok2 = true;;
    for(int i = 1; i < sans1.size(); i++) {
        if(abs(sans1[i] - sans1[i - 1]) == 1) {
            ok1 = false;
        }
    }
    for(int i = 1; i < sans2.size(); i++) {
        if(abs(sans2[i] - sans2[i - 1]) == 1) {
            ok2 = false;
        }
    }
    if(!ok1 && !ok2)cout << "No answer" << endl;
    else if(ok1)cout << sans1 << endl;
    else if(ok2)cout << sans2 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}