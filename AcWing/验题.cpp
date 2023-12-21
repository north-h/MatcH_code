// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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

string mul(string a, int b) {
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        B.push_back(t % 10);
        t /= 10;
    }
    while (t)B.push_back(t % 10), t /= 10;
    while (B.size() > 1 && B.back() == 0)B.pop_back();
    string s1;
    char op;
    for (int i = B.size() - 1; i >= 0; i--)s1 += (B[i] + '0');
    return s1;
}


bool check(string a, string b, int ax, int bx) {
    ax *= 3;
    bx *= 3;
    // debug2(ax, bx);
    // debug2(a.size(), b.size());
    if(a.size() < ax) {
        reverse(a.begin(), a.end());
        int cnt = abs(ax - (int)a.size());
        // debug1(abs(ax - (int)a.size()));
        for(int i = 1; i <= cnt; i++) {
            a.push_back('0');
        }
        reverse(a.begin(), a.end());
    }
    if(b.size() < bx) {
        int cnt = abs(bx - (int)b.size());
        reverse(b.begin(), b.end());
        for(int i = 1; i <= cnt; i++) {
            b.push_back('0');
        }
        reverse(b.begin(), b.end());
    }
    // debug2(a, b);
    // debug2(a.size(), b.size());
    while(a.back() == '0')a.pop_back();
    while(b.back() == '0')b.pop_back();
    return a <= b;
}

string s[1010];

void solve() {
    int n, m, p, k, t;
    cin >> n >> m >> p >> k >> t;
    n = min(n, m - 1);
    s[0] = "1000";
    for(int i = 1; i <= 1000; i++) {
        if(i <= n + 1)s[i] = mul(s[i - 1], (1000 - p));
        else s[i] = mul(s[i - 1], (1000 - (i - n - 1) * k));
    }
    while(t--) {
        int a, b;
        cin >> a >> b;
        string aa, bb;
        if(a > n + 1) {
            aa = mul(s[a - 1], (p + (a - n - 1) * k));
        } else aa = mul(s[a - 1], p);
        if(b > n + 1) {
            bb = mul(s[b - 1], (p + (b - n - 1) * k));
        } else bb = mul(s[b - 1], p);
        // debug2(aa, bb);
        if(check(aa, bb, a, b))cout << "Joler" << endl;
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