/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-26 15:11:20
 *
 * Problem: D. Add Modulo 10
 * Contest: Codeforces - SMU Autumn 2023 Round 5
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475398/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int goal = -1;
    set<int> st;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    st.insert(4);
    st.insert(8);
    st.insert(6);
    for(int i = 0; i < n; i++) {
        int res = a[i] % 10;
        if(res == 1 || res == 2) {
            goal = 1;
            st.insert(1);
            st.insert(2);
            break;
        } else if(res == 3) {
            goal = 3;
            st.insert(3);
            break;
        } else if(res == 7) {
            goal = 7;
            st.insert(7);
            break;
        } else if(res == 5 || res == 10) {
            goal = 5;
            st.insert(5);
            st.insert(10);
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(!st.count(a[i] % 10)) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}