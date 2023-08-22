/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-22 20:19:11
 * Problem :
 * =====================================
 *                   _   _         _
 *  _ __   ___  _ __| |_| |__     | |__
 * | '_ \ / _ \| '__| __| '_ \    | '_ \
 * | | | | (_) | |  | |_| | | |   | | | |
 * |_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                           |_____|
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
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

string sub(string a, string b) {
    vector<int> A, B, C;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = A[i] + t;
        if (i < B.size())t -= B[i];
        if (t < 0)C.push_back(t + 10), t = -1;
        else C.push_back(t), t = 0;
    }
    while (C.size() > 1 && C.back() == 0)C.pop_back();
    string s;
    for (int i = C.size() - 1; i >= 0; i--)s += (C[i] + '0');
    return s;
}

bool cmp(string a, string b) {
    if (a.size() != b.size())return a.size() > b.size();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])return a[i] > b[i];
    }
    return true;
}


string add(string a, string b) {
    if (a.size() < b.size())swap(a, b);
    vector<int> A, B, C;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += A[i];
        if (i < B.size())t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)C.push_back(t);
    string str;
    char op;
    for (int i = C.size() - 1; i >= 0; i--)op = C[i] + '0', str += op;
    return str;
}

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    if(!cmp(b, c))cout << -1 << endl;
    else cout << add(sub(a, b), "1") << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}