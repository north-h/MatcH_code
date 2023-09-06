//
//  Author : north_h
//  File : C.cpp
//  Time : 2023/7/18/11:56
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

map<int,int> l,r;
int a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    int pos;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > m)a[i] = 1;
        else if (x < m)a[i] = -1;
        else a[i] = 0, pos = i;
    }
    for (int i = pos + 1; i <= n; i++) {
        a[i] += a[i - 1];
        r[a[i]]++;
    }
    for (int i = pos - 1; i >= 1; i--) {
        a[i] += a[i + 1];
        l[a[i]]++;
    }
    int ans = 2;
    int cnt = 0;
    for (int i = 1; i < pos; i++) {
        if (a[i] == 0)cnt++;
        ans += r[-a[i]];
    }
    for (int i = pos + 1; i <= n; i++) {
        if (a[i] == 0)cnt++;
        ans += l[-a[i]];
    }
    cout << ans / 2 + cnt << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
