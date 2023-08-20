/*
Author : north_h
File : D.cpp
Time : 2023/8/4/19:47
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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    vector<int> ans;
    int goal = n;
    for (int i = 1; i <= n; i++) {
        int pos;
        for (int j = 1; j <= goal; j++) {
            if (a[j] == goal) {
                pos = j;
                break;
            }
        }
        vector<int> temp1, temp2;
        temp1.push_back(0);
        temp2.push_back(0);
        if (pos == goal)ans.push_back(0);
        else if (pos > goal) {
            ans.push_back(pos - goal);
            for (int j = 1; j <= pos - goal; j++)temp1.push_back(a[j]);
            for (int j = pos - goal + 1; j <= goal; j++)temp2.push_back(a[j]);
            for (int j = 1; j < temp2.size(); j++)a[j] = temp2[j];
            for (int j = temp2.size(), len = 1; len < temp1.size(); j++, len++)a[j] = temp1[len];
        } else {
            ans.push_back(pos);
            for (int j = 1; j <= pos; j++)temp1.push_back(a[j]);
            for (int j = pos + 1; j <= goal; j++)temp2.push_back(a[j]);
            for (int j = 1; j < temp2.size(); j++)a[j] = temp2[j];
            for (int j = temp2.size(), len = 1; len < temp1.size(); j++, len++)a[j] = temp1[len];
        }
        goal--;
    }
    reverse(ALL(ans));
    for (auto i: ans)cout << i << ' ';
    cout<<endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}

