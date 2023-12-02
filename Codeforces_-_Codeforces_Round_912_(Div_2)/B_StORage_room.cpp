/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-01 00:40:08
 *
 * Problem: B. StORage room
 * Contest: Codeforces - Codeforces Round 912 (Div. 2)
 * URL:     https://codeforces.com/contest/1903/problem/B
 * MemoryL: 256 MB
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
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        int x = (1 << 30) - 1;
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(i == j)continue;
            else x &= a[i][j];
        }
        ans.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)continue;
            else if((ans[i] | ans[j]) != a[i + 1][j + 1]) {
                cout << "NO" << endl;
                return ;
            }
        }
    }
    cout << "YES" << endl;
    for(auto i : ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}