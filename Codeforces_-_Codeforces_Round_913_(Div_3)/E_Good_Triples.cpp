/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-05 22:45:43
 *
 * Problem: E. Good Triples
 * Contest: Codeforces - Codeforces Round 913 (Div. 3)
 * URL:     https://codeforces.com/contest/1907/problem/E
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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

vector<int> v(30);

void solve() {
    int n;
    cin >> n;
    int ans = 1;
    while(n) {
        ans *= v[n % 10];
        n /= 10;
    }
    cout << ans << endl;
}

int32_t main() {
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= 9; k++) {
                v[i + j + k]++;
            }
        }
    }
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}