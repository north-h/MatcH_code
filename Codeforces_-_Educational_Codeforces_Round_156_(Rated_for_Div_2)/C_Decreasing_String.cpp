/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-10 01:14:34
 *
 * Problem: C. Decreasing String
 * Contest: Codeforces - Educational Codeforces Round 156 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1886/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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
    string s;
    int n;
    cin >> s >> n;
    int pos, len;
    int x = n;
    for(int i = 1, k = s.size(); i <= n; i++, k--) {
        if(x - k <= 0) {
            len = k;
            pos = x;
            break;
        }
        x -= k;
    }
    // debug2(pos, len);
    int res = (int)s.size() - len;
    unordered_map<int, int> mp;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] < s[i - 1]) {
            int j = i - 1;
            while(j >= 0 && s[j] > s[i] && res) {
                mp[j]++;
                j--;
                if(!mp.count(j))res--;
            }
            if(res == 0)break;
        }
    }
    string sans;
    for(int i = 0; i < s.size(); i++) {
        if(!mp.count(i))sans += s[i];
    }
    cout << sans[pos - 1];
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}