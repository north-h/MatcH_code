/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-10 12:12:10
 *
 * Problem: H. Hardcore Hangman
 * Contest: Codeforces - SMU Autumn 2023 Round 2(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/472110/problem/H
 * MemoryL: 512 MB
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
// #define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    cout << "? ";
    for(auto i = 'a'; i <= 'z'; i++)cout << i;
    cout << endl;
    int n;
    cin >> n;
    vector<char> a(n + 1);
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
    }
    for(int i = 4, t; i >= 0; i--) {
        cout << "? ";
        for(int j = 0; j < 26; j++) {
            if((j >> i) & 1) {
                // cout << j << ' ';
                cout << (char)('a' + j);
            }
        }
        cout << endl;
        cin >> t;
        for(int j = 0, x; j < t; j++) {
            cin >> x;
            a[x] |= (1 << i);
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++)cout << (char)('a' + a[i]);
    // cout << endl;
}

int32_t main() {
    // IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}