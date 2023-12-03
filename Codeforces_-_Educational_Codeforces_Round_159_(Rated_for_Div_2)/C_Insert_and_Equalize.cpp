/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-03 22:35:25
 *
 * Problem: C. Insert and Equalize
 * Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1902/problem/C
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for(auto &i : a) {
        cin >> i;
        st.insert(i);
    }
    vector<int> ans;
    sort(a.begin(), a.end());
    int mx = a.back();
    for(auto i : a) {
        if(mx - i != 0)
            ans.push_back(mx - i);
    }
    if(!ans.size()) {
        cout << 1 << endl;
        return ;
    }
    int gc = ans[0];
    for(int i = 1; i < ans.size(); i++) {
        gc = __gcd(gc, ans[i]);
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(!st.count(mx - gc * i)) {
            res = i;
            break;
        }
    }
    if(res == 0)res = n;
    for(auto i : ans) {
        res += i / gc;
    }
    cout << res << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}