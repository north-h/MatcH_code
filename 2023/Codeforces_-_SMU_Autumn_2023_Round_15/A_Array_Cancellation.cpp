/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-26 13:30:27
 *
 * Problem: A. Array Cancellation
 * Contest: Codeforces - SMU Autumn 2023 Round 15
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/494765/problem/A
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<PII> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            sum += a[i];
            a[i] = 0;
        } else {
            if(sum >= abs(a[i]))sum += a[i], a[i] = 0;
            else a[i] -= sum, sum = 0;
        }
    }
    cout << sum << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}