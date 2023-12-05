/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-01 00:40:25
 *
 * Problem: E. Geo Game
 * Contest: Codeforces - Codeforces Round 912 (Div. 2)
 * URL:     https://codeforces.com/contest/1903/problem/E
 * MemoryL: 256 MB
 * TimeL:   2500 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
// #define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 110;

using namespace std;

void solve() {
    int n, sx, sy;;
    cin >> n >> sx >> sy;
    set<int> odd, even;
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        int dis = abs(x - sx) + abs(y - sy);
        if(dis & 1)odd.insert(i);
        else even.insert(i);
    }
    if(odd.size() <= even.size()) {
        cout << "First" << endl;
        while(odd.size() || even.size()) {
            if(odd.size()) {
                cout << *odd.begin() << endl;
                odd.erase(*odd.begin());
            } else {
                cout << *even.begin() << endl;
                even.erase(*even.begin());
            }
            if(!odd.size() && !even.size())break;
            int x;
            cin >> x;
            if(odd.find(x) != odd.end())odd.erase(x);
            else even.erase(x);
        }
    } else {
        cout << "Second" << endl;
        while(odd.size() || even.size()) {
            int x;
            cin >> x;
            if(odd.find(x) != odd.end())odd.erase(x);
            else even.erase(x);
            if(!odd.size() && !even.size())break;
            if(even.size()) {
                cout << *even.begin() << endl;
                even.erase(*even.begin());
            } else {
                cout << *odd.begin() << endl;
                odd.erase(*odd.begin());
            }
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}