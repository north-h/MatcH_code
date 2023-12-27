/*
Author : north_h
File : A.cpp
Time : 2023/8/1/11:56
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
    vector<PII > a;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        a.push_back({r, l});
    }
    int ans = 0;
    sort(a.begin(), a.end());
    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = a[i].se; j <= a[i].fi; j++) {
            if (!st.count(j)) {
                st.insert(j);
                break;
            }
        }
//        int l = a[i].se, r = a[i].fi;
//        while (l < r) {
//            //cout<<l<<' '<<r<<endl;
//            int mid = l + r>> 1;
//            if (st.count(mid))l = mid + 1;
//            else r = mid;
//        }
//        if (!st.count(l))st.insert(l);
//    }
        cout << st.size() << endl;
    }
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}