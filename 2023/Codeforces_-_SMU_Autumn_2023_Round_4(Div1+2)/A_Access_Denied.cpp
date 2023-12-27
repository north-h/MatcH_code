/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-16 12:08:51
 *
 * Problem: A. Access Denied
 * Contest: Codeforces - SMU Autumn 2023 Round 4(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/473585/problem/A
 * MemoryL: 512 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

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
// #define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int32_t main() {
    int ans = 0;
    for(int i = 1; i <= 20; i++) {
        string s = "";
        for(int j = 1; j <= i; j++)s += '1';
        cout << s << endl;
        int x = 0;
        // scanf("ACCESS DENIED (%d ms)", &x);
        // getchar();
        string temp;
        getline(cin, temp);
        // if(temp == "ACCESS GRANTED")return 0;
        // cout << temp << endl;
        for(auto &k : temp) {
            if(k >= '0' && k <= '9')x = x * 10 + (k - '0');
        }
        // cout << x << endl;
        if(x != 5) {
            ans = i;
            break;
        }
    }
    // cout << ans << endl;
    string sans = "";
    string ss = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789";
    for(int i = 1; i <= ans; i++) {
        for(int j = 0; j < 62; j++) {
            string s = sans;
            for(int k = 1; s.size() < ans ; k++)s += ss[j];
            cout << s << endl;
            int x = 0;
            string temp;
            // scanf("ACCESS DENIED (%d ms)", &x);
            getline(cin, temp);
            // if(temp == "ACCESS GRANTED")return 0;
            // cout << temp << endl;
            for(auto &k : temp) {
                if(k >= '0' && k <= '9')x = x * 10 + (k - '0');
            }
            // cout << x << endl;
            // getchar();
            if(i < ans) {
                if(x >= 5 + (i + 1) * 9 ) {
                    sans += ss[j];
                    break;
                }
            }
        }
    }
    // for(int i = 0; i < 62; i++) {
    //     string temp = sans + ss[i];
    //     cout << temp << endl;
    //     string s;
    //     getline(cin, s);
    //     if(s == "ACCESS GRANTED")break;
    // }
    // cout << sans << endl;
}
/*
bool CheckPassword(string pwd1, string pwd2) {
    if (pwd1.Length != pwd2.Length) {
        return false;
    }
    //4ms
    for (int i = 0; i < pwd1.Length; i++) {//for会消耗1ms
        //5ms
        if (pwd1[i] != pwd2[i]) {
            return false;
        }
    }
    return true;
}
//Hunter2
//HunFhun
//相同的每移动一位
*/