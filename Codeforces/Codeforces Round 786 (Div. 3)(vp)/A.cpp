//
//  Author : north_h
//  File : A.cpp
//  Time : 2023/7/18/12:56
//

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
#define endl '\n'
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;


void solve() {
    int x, y;
    cin >> x >> y;
    if (y % x != 0 || x > y)cout << "0 0" << endl;
    else if (x == y)cout << "1 1" << endl;
    else {
        int xx = y / x;
        for (int i = 2; i <= xx; i++) {
            int sum = 1;
            int b = 0;
            while (sum < xx)sum *= i, b++;
            if (sum == xx) {
                cout << b << ' ' << i << endl;
                return;
            }
        }
    }
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
