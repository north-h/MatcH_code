/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-26 13:30:36
 *
 * Problem: F. All the Vowels Please
 * Contest: Codeforces - SMU Autumn 2023 Round 15
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/494765/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 100010;
const int M = 110;

using namespace std;

char a[6] = ['0', 'a', 'e', 'i', 'o', 'u'];

void solve() {
    int n;
    cin >> n;
    if(n & 1 || n / 5 < 5)cout << -1 << endl;
    else {
        for(int i = 1, j = 1; i <= n; i++, j++) {
            for(int k = j; k <= n; k++) {

            }
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}