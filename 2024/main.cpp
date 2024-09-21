//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;

const int N = 3e5 + 10, M = 210;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
ll n;
int a[N], b[N];
void solve() {
    string t; cin >> t;
    string s;
    for (auto i : t) {
        if (i == ')' || i == '(') s.append("o");
        else s.append("x");
    }
    if (s == "ooxx" || s == "xxoo") {cout << "Yes\n"; return ;}
    if (s == "oxxoxoox" || s == "xooxoxxo") {cout << "Yes\n"; return ;}
    n = s.size(); s = " " + s;
    stack<char>sk;
    map<char, int>mp;
    char op = '#';
    for (int i = 1; i <= n; i++) {
        if (sk.empty() || sk.top() != s[i]) sk.push(s[i]);
        else if (sk.size() == 1) {
            mp[s[i]]++, sk.pop();
            if (op == '#') op = s[i];
            else if (op == s[i]) {cout << "No\n"; return ;}
            else op = s[i];
        } else {
            if (op == '#') op = s[i];
            else if (op == s[i]) {cout << "No\n"; return ;}
            else op = s[i];
            sk.pop();
        }
    }
    for (auto [c, cnt] : mp) if (cnt > 1) {cout << "No\n"; return ;}
    cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mt19937 rand(time(0));
    int O_o = 1;
    // cin >> O_o;
    while (O_o--) solve();
    return 0;
}
//make it count
//开ll plz