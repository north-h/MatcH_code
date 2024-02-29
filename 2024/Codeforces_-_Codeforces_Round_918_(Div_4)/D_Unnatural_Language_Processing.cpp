/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-01-15 16:49:44
 *
 * Problem: D. Unnatural Language Processing
 * Contest: Codeforces - Codeforces Round 918 (Div. 4)
 * URL:     https://codeforces.com/contest/1915/problem/D
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int  n;
    string s;
    cin >> n >> s;
    set<char> st;
    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');
    for(int i = 0; i < n; i++) {
        if(st.count(s[i])) {
            if(i == n - 2) {
                cout << s[i - 1] << s[i] << s[i + 1];
                break ;
            } else if(i == n - 1) {
                cout << s[i - 1] << s[i];
                break ;
            } else if(st.count(s[i + 2])) {
                cout << s[i - 1] << s[i] << '.';
            } else {
                cout << s[i - 1] << s[i] << s[i + 1] << '.';
            }
        }
    }
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}