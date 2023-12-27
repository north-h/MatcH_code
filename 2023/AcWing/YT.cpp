// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 100010;
const int M = 110;

using namespace std;


void solve() {
    vector<double> s(1010);
    int  n, m, t;
    double p, k;
    cin >> n >> m >> p >> k >> t;
    p /= 1000;
    k /= 1000;
    n = min(n, m - 1);
    s[0] = 1;
    for(int i = 1; i <= 1000; i++) {
        if(i <= n + 1)s[i] = s[i - 1] * (1 - p);
        else s[i] = s[i - 1] * (1 - (p + (i - n - 1) * k));
    }
    while(t--) {
        int a, b;
        cin >> a >> b;
        double aa, bb;
        if(a > n + 1) {
            aa = s[a - 1] * (p + (a - n - 1) * k);
        } else aa = s[a - 1] * p;
        if(b > n + 1) {
            bb = s[b - 1] * (p + (b - n - 1) * k);
        } else bb = s[b - 1] * p;
        if(a == m)aa = s[a - 1];
        if(b == m)bb = s[b - 1];
        if(aa <= bb)cout << "Joler" << endl;
        else cout << "omemi" << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}