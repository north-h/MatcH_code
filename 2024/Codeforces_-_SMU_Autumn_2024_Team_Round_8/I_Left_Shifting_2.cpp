/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-19 13:49:01
 *
 * Problem: I. Left Shifting 2
 * Contest: Codeforces - SMU Autumn 2024 Team Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/559336/problem/I
 * MemoryL: 1024 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s; cin >> s;
    deque<int> t;
    deque<char> ts;
    for (auto i : s) ts.push_back(i);
    int cc = 1;
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] == s[i - 1]) cc ++;
        else {
            t.push_back(cc);
            cc = 1;
        }
    }
    t.push_back(cc);
    string ss = s;
    int ans = 0;
    for (int i = 1; i < ss.size(); i ++) {
        if (ss[i] == ss[i - 1]) {
            ss[i] = '#';
            ans ++;
        }
    }
    int sz = s.size();
    int res = ans;
    for (int i = 1; i < s.size(); i ++) {
        int s0 = ts.front();
        ts.pop_front();
        int s1 = ts.front();
        ts.pop_front();
        ts.push_front(s1);
        ts.push_front(s0);
        if (s0 == s1 && t.front() % 2 == 0) ans --;
        ts.push_back(ts.front());
        ts.pop_front();
        t.front() --;
        int sn = ts.back();
        ts.pop_back();
        int sm = ts.back();
        ts.pop_back();
        ts.push_back(sm);
        ts.push_back(sn);
        if (t.front() == 0) t.pop_front();
        if (sn != sm)t.push_back(1);
        else t.back() ++;
        if (sn == sm && t.back() % 2 == 0) ans ++;
        res = min(res, ans);
    }
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}