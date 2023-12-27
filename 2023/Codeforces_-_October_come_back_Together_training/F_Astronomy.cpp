/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-13 19:00:46
 *
 * Problem: F. Astronomy
 * Contest: Codeforces - October come back. Together training
 * URL:     https://codeforces.com/gym/104678/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
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

string add(string a, string b) {
    if (a.size() < b.size())swap(a, b);
    vector<int> A, B, C;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += A[i];
        if (i < B.size())t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)C.push_back(t);
    string str;
    char op;
    for (int i = C.size() - 1; i >= 0; i--)op = C[i] + '0', str += op;
    return str;
}


void solve() {
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}

