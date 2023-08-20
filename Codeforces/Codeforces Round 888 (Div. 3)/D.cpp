/*
    Author : north_h
    File : D.cpp
    Time : 2023/7/26/13:29
                    _   _         _     
   _ __   ___  _ __| |_| |__     | |__  
  | '_ \ / _ \| '__| __| '_ \    | '_ \ 
  | | | | (_) | |  | |_| | | |   | | | |
  |_| |_|\___/|_|   \__|_| |_|___|_| |_|
                            |_____|     
*/
#pragma GCC optimize(3)

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
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
    vector<int> vis(n + 1);
    vector<int> a(n + 1);
    vector<int> s(n + 1);
    for (int i = 1; i <= n - 1; i++)cin >> s[i];
    if (n == 2) {
        if (s[1] == 1 || s[1] == 3 || s[1] == 2)cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    set<int> st;
    vector<int> ans;
    for (int i = 1; i <= n - 1; i++) {
        int x = s[i] - s[i - 1];
        if (x <= n) {
            if(st.count(x))ans.push_back(x);
            else st.insert(x);
        } else ans.push_back(x);
    }
    if (!ans.size())cout << "YES" << endl;
    else if (ans.size() > 1 || ans[0] > 2 * n)cout << "NO" << endl;
    else {
        for (int i = 1, j = ans[0] - 1; i < j; i++, j--) {
            if (!st.count(i) && !st.count(j) && i <= n && j <= n) {
                cout <<   "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
