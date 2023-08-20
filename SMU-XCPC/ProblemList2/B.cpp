//
//  Author : north_h
//  File : B.cpp
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
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace  std;

struct S{
    int a, b,c,d;
}a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> a[i].a >> a[i].b >> x >> y;
        a[i].c = a[i].a + x;
        a[i].d = a[i].b + y;
    }
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        //cout << a[i].a << ' ' << a[i].c << ' ' << a[i].b << ' ' << a[i].d << endl;
        if (x >= a[i].a && x <= a[i].c && y >= a[i].b && y <= a[i].d) {
            ans = i + 1;
            break;
        }
    }
    if (!ans)ans = -1;
    cout << ans << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}