/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-11 09:51:19
 * =====================================
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
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
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

bool huiwen(int x) {
    int h = x / 60;
    int m = x % 60;
    string s1 = to_string (h);
    if(s1.size() == 1)s1 = '0' + s1;
    string s2 = to_string(m);
    if(s2.size() == 1)s2 = '0' + s2;
    reverse(ALL(s1));
    if(s1 == s2) {
        // cout << s1 << ' ' << s2 << endl;
        return true;
    }
    return false;
}

void solve() {
    string s;
    cin >> s;
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    // cout << h << ' ' << m << endl;
    int x;
    cin >> x;
    int star = h * 60 + m;
    int ans = 0;
    int pos = star;
    set<int> st;
    for(int i = star; ; i += x, pos += x) {
        if(i >= 1440)i %= 1440;
        if(st.count(i))break;
        st.insert(i);
        if(huiwen(i))ans++;

    }
    // for(int i = pos % 1440; i < star ; i += x) {
    //     if(huiwen(i))ans++;
    // }
    cout << ans << endl;
    // cout << pos << endl << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}