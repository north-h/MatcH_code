//
//  Author : north_h
//  File : A.cpp
//  Time : 2023/7/20/12:45
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
const int N = 100010;
const int M = 30;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[M][N];

int lowbit(int x){
    return x&(-x);
}

int get(int x){
    int res=0;
    while(x)res++,x-=lowbit(x);
    return res;
}


void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    set<int> st;
    for (int op = 0; op < (1 << n); op++) {
        int cnt = get(op);
        if (cnt > a)continue;
        st.clear();
        for (int i = 0; i < n; i++) {
            if (!(op >> i & 1)) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == '*')st.insert(j);
                }
            }
        }
        if (st.size() <= b) {
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
1