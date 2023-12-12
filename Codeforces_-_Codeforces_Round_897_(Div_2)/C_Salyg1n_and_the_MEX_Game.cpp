/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-12 08:47:23
 *
 * Problem: C. Salyg1n and the MEX Game
 * Contest: Codeforces - Codeforces Round 897 (Div. 2)
 * URL:     https://codeforces.com/contest/1867/problem/C
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
// #define endl '\n'
const int N = 10010;
const int M = 1910;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    set<int> st;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int k = 0;
    for(auto i : st) {
        if(!st.count(k))break;
        k++;
    }
    cout << k << endl;
    for(int i = 1; i <= n * 2; i++) {
        int x;
        cin >> x;
        if(x == -1)return ;
        cout << x << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}