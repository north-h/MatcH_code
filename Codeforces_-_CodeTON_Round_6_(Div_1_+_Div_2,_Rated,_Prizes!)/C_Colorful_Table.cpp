/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-18 22:36:22
 *
 * Problem: C. Colorful Table
 * Contest: Codeforces - CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!)
 * URL:     https://codeforces.com/contest/1870/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug(a,b) cout << (string)a << '=' << b << endl;
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> st;
    vector<int> a(n + 1), l(k + 1, n + 1), r(k + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    vector<int> ans, T;
    for(int i = k; i >= 1; i--) {
        if(!st.count(i)) {
            ans.push_back(0);
            continue;
        }
        if(!T.size())T.push_back(i);
        l[i] = min(l[T.back()], l[i]);
        r[i] = max(r[T.back()], r[i]);
        ans.push_back(2 * (r[i] - l[i] + 1));
        T.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}