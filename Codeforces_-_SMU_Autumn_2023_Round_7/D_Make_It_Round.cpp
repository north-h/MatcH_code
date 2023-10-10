/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-10 13:00:44
 *
 * Problem: D. Make It Round
 * Contest: Codeforces - SMU Autumn 2023 Round 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478437/problem/D
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n & 1 && n % 10 != 5)cout << n *m << endl;
    else {
        int x = n;
        string s = to_string(m);
        int res;
        while(x % 10 == 0)x /= 10;
        res = x % 100;
        debug1(x);
        string ans;
        for(int i = 0; i < max((int)s.size() - 2, 0ll); i++)ans += '0';
        if(res == 25) {
            if(s.size() >= 2) {
                int x = (s[0] - '0') * 10 + (s[1] - '0');
                // debug1(x);
                if(x >= 80) {
                    ans += "08";
                } else if(x >= 40) {
                    ans += "04";
                } else {
                    for(int i = x; i >= 1; i--) {
                        if(i % 2 == 0) {
                            string s = to_string(i);
                            reverse(ALL(s));
                            ans += s;
                            break;
                        }
                    }
                }
            } else {
                for(int i = s[0] - '0'; i >= 1; i--) {
                    if(i % 2 == 0) {
                        string s = to_string(i);
                        reverse(ALL(s));
                        ans += s;
                        break;
                    }
                }
            }
        } else if(res == 5) {
            if(s.size() >= 2) {
                int x = (s[0] - '0') * 10 + (s[1] - '0');
                // debug1(x);
                if(x >= 80) {
                    ans += "08";
                } else if(x >= 60) {
                    ans += "06";
                } else if(x >= 40) {
                    ans += "04";
                } else if(x >= 20) {
                    ans += "02";
                } else {
                    for(int i = x; i >= 1; i--) {
                        if(i % 2 == 0) {
                            string s = to_string(i);
                            reverse(ALL(s));
                            ans += s;
                            break;
                        }
                    }
                }
            } else {
                for(int i = s[0] - '0'; i >= 1; i--) {
                    if(i % 2 == 0) {
                        string s = to_string(i);
                        reverse(ALL(s));
                        ans += s;
                        break;
                    }
                }
            }
        } else {
            if(s.size() >= 2) {
                int x = (s[0] - '0') * 10 + (s[1] - '0');
                if(x >= 50) {
                    ans += "05";
                } else if(x >= 25) {
                    ans += "52";
                } else {
                    for(int i = x - 1;; i--) {
                        if(i % 10 == 0 || i % 10 == 5) {
                            ans += to_string(i);
                            break;
                        }
                    }
                }
            } else {
                for(int i = s[0] - '0';; i--) {
                    if(i % 10 == 0 || i % 10 == 5) {
                        ans += to_string(i);
                        break;
                    }
                }
            }
        }
        reverse(ALL(ans));
        debug1(ans);
        cout << n *stoi(ans) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}