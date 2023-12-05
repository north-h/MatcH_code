/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-03 22:35:34
 *
 * Problem: E. Collapsing Strings
 * Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1902/problem/E
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 1000010;
const int M = 110;

using namespace std;

template<class T>
struct Trie {
    T idx = 0;
    vector<vector<T>> s;
    vector<T>cnt;
    Trie(T n): cnt(n, 0), s(n, vector<T>(26, 0)) {}
    void insert(string &str) {
        T p = 0;
        for (int i = 0; i < str.size(); i++) {
            T u = str[i] - 'a';
            if (!s[p][u]) s[p][u] = ++idx;
            p = s[p][u];
            cnt[p]++;
        }
    }

    T query(string &str) {
        T p = 0;
        for (int i = 0; i < str.size(); i++) {
            T u = str[i] - 'a';
            if (!s[p][u]) return 0;
            p = s[p][u];
        }
        return cnt[p];
    }
};


void solve() {
    Trie<int> trie(N);
    int n;
    cin >> n;
    vector<string> s(n);
    ll ans = 0;
    for(auto &i : s) {
        cin >> i;
        trie.insert(i);
        ans += 2ll * (int)i.size() * n;
    }
    for(auto &i : s) {
        reverse(i.begin(), i.end());
        int p = 0;
        for(auto j : i) {
            int x = j - 'a';
            int cnt = trie.s[p][x];
            if(!cnt)break;
            p = trie.s[p][x];
            ans -= 2ll * trie.cnt[p];
        }
        // string str = "";
        // for(auto j : i) {
        //     str += j;
        //     // debug1(str);
        //     int cnt = trie.query(str);
        //     if(!cnt)break;
        //     ans -= cnt * 2ll;
        // }
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}