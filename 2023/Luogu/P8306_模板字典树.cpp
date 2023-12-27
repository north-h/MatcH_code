/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-15 15:06:33
 *
 * Problem: P8306 【模板】字典树
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8306
 * MemoryL: 1 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 3000010;
const int M = 110;

using namespace std;


int getnum(char ch) {
    if(ch >= 'A' && ch <= 'Z')return ch - 'A' + 1;
    if(ch >= 'a' && ch <= 'z')return ch - 'a' + 1 + 26;
    if(ch >= '0' && ch <= '9')return ch - '0' + 1 + 26 + 26;
}

struct trie2 {//常规
    int nex[3000010][65], cnt, val[3000010];
    bool exist[3000010];

    void insert(string s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = getnum(s[i]);
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
            val[p]++;
        }
        exist[p] = 1;
    }

    int find(string s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = getnum(s[i]);
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return val[p];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    // for(int i = 0; i <= idx; i++) {
    //     cnt[i] = 0;
    //     for(int j = 0; j <= 65; j++) {
    //         s[i][j] = 0;
    //     }
    // }
    // idx = 0;
    trie2 trie;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        // trie.insert(s);
    }
    while(q--) {
        string s;
        cin >> s;
        // cout << trie.find(s) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}