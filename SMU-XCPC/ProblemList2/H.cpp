//
//  Author : north_h
//  File : H.cpp
//  Time : 2023/7/18/16:28
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
const int N = 100;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

string a,b;//a->中序  b->后序
map<char,int> mp;
vector<char> level[N];

void build(int al,int ar,int bl,int br) {
    if (bl > br)return;
    char val = b[br];
    cout << val;
    int k = mp[val];
    build(al, k - 1, bl, bl + k - 1 - al);
    build(k + 1, ar, bl + k - al, br - 1);
}

void solve() {
    cin >> a >> b;
    int n = a.size();
    for (int i = 0; i < n; i++)mp[a[i]]=i;
    //for (auto [x, y]: mp)cout << x << ' ' << y << endl;
    build(0, n - 1, 0, n - 1);
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
