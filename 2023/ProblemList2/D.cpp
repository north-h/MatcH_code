//
//  Author : north_h
//  File : D.cpp
//  Time : 2023/7/18/11:46
//

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
#define endl '\n'
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const double EPS = 1e8;
const int INF = 0x3f3f3f3f;

using namespace std;


void solve() {
    int n;
    int sum = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i], sum += a[i];
    for (int i = 1; i <= n; i++)a.push_back(a[i]);
    //for (int i = 1; i <= a.size(); i++)a[i] += a[i - 1];
    //for (auto i: a)cout << i << ' ';
    int pos = sum / 2;
    int ans = 0;
    int lsum = 0;
    int rsum = 0;
    int l = 1;
    int r=0;
    for (int i = 1; i <= n; i++) {
        while (lsum < pos) {
            lsum += a[r++];
        }
        rsum = sum - lsum;
        ans = max(ans, min(lsum, rsum));
        lsum-=a[i];
    }
    cout << ans << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
