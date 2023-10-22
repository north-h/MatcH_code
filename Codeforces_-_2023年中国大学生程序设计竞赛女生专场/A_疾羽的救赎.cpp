/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-22 18:03:18
 *
 * Problem: A. 疾羽的救赎
 * Contest: Codeforces - 2023年中国大学生程序设计竞赛女生专场
 * URL:     https://codeforces.com/gym/104725/problem/A
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
    PII a1, a2, a3;
    a1.fi = 1, a1.se = 2;
    a2.fi = 2, a2.se = 3;
    a3.fi = 3, a3.se = 4;
    for(int i=0;i<12;i++){
        int id,x;
        cin>>id>>x;
        if(x==1){
            if(id==1){
                int pos=a1.se+1;
                if(pos==a2.se){
                    a1.se=a2.se;
                    a1.fi=a2.fi;
                }else if(pos==a3.se){
                    a1.se=a3.se;
                    a1.fi=a3.fi;
                }else {
                    a1.se=pos;
                }
            }else if(id==2){
                int pos=a1.se+1;
                if(pos==a2.se){
                    a1.se=a2.se;
                    a1.fi=a2.fi;
                }else if(pos==a3.se){
                    a1.se=a3.se;
                    a1.fi=a3.fi;
                }else {
                    a1.se=pos;
                }
            }else {
                int pos=a1.se+1;
                if(pos==a2.se){
                    a1.se=a2.se;
                    a1.fi=a2.fi;
                }else if(pos==a3.se){
                    a1.se=a3.se;
                    a1.fi=a3.fi;
                }else {
                    a1.se=pos;
                }
            }
        }else {
            if(id==1){

            }else if(id==2){

            }else {
                
            }
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}