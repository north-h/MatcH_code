//
//  Author : north_h
//  File : B.cpp
//  Time : 2023/7/21/11:51
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

inline int read() {
    int x = 0, f = 1, ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * f;
}

int aa[26],bb[26];
int vis[N];

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        aa[a[i] - 'a']++;
        bb[b[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (aa[i] != bb[i]) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans;
    string temp ;
    for (int i = 0, j = 0; i < n; i++, j++) {
        if (a[i] != b[j]) {
            for (int k = i + 1; k < n; k++) {
                if (a[k] == b[j]) {
                    for (int x = k; x >=i+1; x--) {
                        a[x] = a[x - 1];
                    }
                    a[i] = b[j];
                    for (int x = k - 1; x >= i; x--)
                        ans.push_back(x);
                    break;
                }
            }
            //cout<<a<<' '<<b<<endl;
        }
    }
    //cout<<a<<' '<<b<<endl;
    cout << ans.size() << endl;
    for (auto i: ans)cout << i + 1 << ' ';
    cout << endl;
}

int main() {
    //IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
