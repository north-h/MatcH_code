//
//  Author : north_h
//  File : A.cpp
//  Time : 2023/7/18/11:54
//

#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a,b) memcopy(a,sizeof b,b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define endl '\n'
const int N = 200010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace  std;

void solve() {
    int n;
    cin >> n;
    for (int i = 1, j = n; i <= n + 1 ;i++, j--) {
        int y;
        cin >> y;
        if (i == 1) {
            if (y == 0)continue;
            else if (y == 1)cout << "x^" << j;
            else if (y == -1)cout << "-x^" << j;
            else if (y < 0)cout << y << "x^" << j;
            else cout << y << "x^" << j;
        } else if (i > 1 && i <= n) {
            if (j != 1) {
                if (y == 0)continue;
                else if (y == 1)cout << "+x^" << j;
                else if (y == -1)cout << "-x^" << j;
                else if (y < 0)cout << y << "x^" << j;
                else cout << '+' << y << "x^" << j;
            } else {
                if (y == 0)continue;
                else if (y == 1)cout << "+x" ;
                else if (y == -1)cout << "-x" ;
                else if (y < 0)cout << y << "x" ;
                else cout << '+' << y << "x";
            }
        } else {
            if (y == 0)continue;
            else if (y < 0)cout << y;
            else cout << '+' << y;
        }
    }
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
