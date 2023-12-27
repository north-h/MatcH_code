//
//  Author : north_h
//  File : G.cpp
//  Time : 2023/7/21/10:08
//                  _   _         _
// _ __   ___  _ __| |_| |__     | |__
//| '_ \ / _ \| '__| __| '_ \    | '_ \
//| | | | (_) | |  | |_| | | |   | | | |
//|_| |_|\___/|_|   \__|_| |_|___|_| |_|
//                          |_____|

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
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.begin(),a.end()
#define int128 __int128
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
    for (auto &i: a)cin >> i;
    stack<PII > stk;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (!stk.size()) {
            ans.push_back(0);
            stk.push({a[i], i});
        } else {
            while (stk.size() && stk.top().fi <= a[i])stk.pop();
            if (!stk.size())ans.push_back(0);
            else ans.push_back(stk.top().se + 1);
            stk.push({a[i], i});
        }
    }
    reverse(ALL(ans));
    for (auto i: ans)cout << i << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
