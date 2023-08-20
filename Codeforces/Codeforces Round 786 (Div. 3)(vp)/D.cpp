//
//  Author : north_h
//  File : D.cpp
//  Time : 2023/7/18/14:45
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
#define se seco1nd
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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a)cin >>i;
    int last = 0;
    if (n % 2 != 0)last = a[0];
    //cout<<last<<endl;
    for (int i = (n % 2 != 0); i < n; i += 2) {
        if (min(a[i], a[i + 1]) >= last)last = max(a[i], a[i + 1]);
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
