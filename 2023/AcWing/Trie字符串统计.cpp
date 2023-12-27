/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-15 14:46:47
 *
 * Problem: Trie字符串统计
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/description/837/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 100010;
const int M = 110;

using namespace std;


template<class T>
struct Trie {
    T idx = 0;
    vector<vector<T>> s;
    vector<T>cnt;
    Trie(T n): cnt(n, 0), s(n, vector<T>(26, 0)) {}
    void insert(string str) {
        T p = 0;
        for (int i = 0; i < str.size(); i++) {
            T u = str[i] - 'a';
            if (!s[p][u]) s[p][u] = ++idx;
            p = s[p][u];
        }
        cnt[p]++;
    }

    T query(string str) {
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
    int n;
    cin >> n;
    Trie<int> trie(N);
    while (n--) {
        char op;
        string s;
        cin >> op >> s;
        if (op == 'I')trie.insert(s);
        else cout << trie.query(s) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}