/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-09 16:33:49
 *
 * Problem: D. Circular Dance
 * Contest: Codeforces - SMU Autumn 2023 Round 1(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470092/problem/D
 * MemoryL: 256 MB
 * TimeL:   3000 ms
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
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl;
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), ans;
    for(int i = 1; i <= n; i++)cin >> a[i] >> b[i];
    if(n == 3) {
        cout << "1 2 3" << endl;
        return ;
    }
    set<int> st;
    st.insert(1);
    ans.push_back(1);
    for(int i = 0; ans.size() < n; i++) {
        int x = a[ans[i]], y = b[ans[i]];
        // debug2(x, y);
        if(a[x] != y && b[x] != y) {
            if(!st.count(y))ans.push_back(y);
            if(!st.count(x))ans.push_back(x);
        } else {
            if(!st.count(x))ans.push_back(x);
            if(!st.count(y))ans.push_back(y);
        }
        st.insert(x);
        st.insert(y);
    }
    for(auto i : ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}