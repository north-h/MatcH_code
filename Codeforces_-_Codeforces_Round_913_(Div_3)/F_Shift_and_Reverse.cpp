/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-05 22:45:43
 *
 * Problem: F. Shift and Reverse
 * Contest: Codeforces - Codeforces Round 913 (Div. 3)
 * URL:     https://codeforces.com/contest/1907/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

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
const int N = 10010;
const int M = 110;

using namespace std;

int get1(vector<int> &a, int n) {
    vector<int> b;
    int pos = -1;
    int res = 0;
    b.push_back(a[0]);
    for(int i = n - 1; i > 0; i--) {
        if(a[i] <= b.back()) {
            res++;
            b.push_back(a[i]);
        } else {
            pos = i;
            break;
        }
    }
    reverse(b.begin(), b.end());
    if(pos != -1) {
        for(int i = 1; i <= pos; i++) {
            b.push_back(a[i]);
        }
    }
    if(is_sorted(b.begin(), b.end())) {
        return res;
    } else return INT_MAX;
}

int get2(vector<int> &a, int n) {
    vector<int> b;
    int pos = -1;
    int res = 0;
    b.push_back(a[0]);
    for(int i = n - 1; i > 0; i--) {
        if(a[i] >= b.back()) {
            res++;
            b.push_back(a[i]);
        } else {
            pos = i;
            break;
        }
    }
    reverse(b.begin(), b.end());
    if(pos != -1) {
        for(int i = 1; i <= pos; i++) {
            b.push_back(a[i]);
        }
    }
    reverse(b.begin(), b.end());
    if(is_sorted(b.begin(), b.end())) {
        return res + 1;
    } else return INT_MAX;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    if(is_sorted(a.begin(), a.end())) {
        cout << 0 << endl;
        return ;
    }
    reverse(a.begin(), a.end());
    if(is_sorted(a.begin(), a.end())) {
        cout << 1 << endl;
        return ;
    }
    int ans = INT_MAX;
    if(a[n - 1] <= a[0])ans = min(ans, get1(a, n) + 1);
    reverse(a.begin(), a.end());
    if(a[n - 1] <= a[0])ans = min(ans, get1(a, n));
    if(a[n - 1] >= a[0])ans = min(ans, get2(a, n));
    reverse(a.begin(), a.end());
    if(a[n - 1] >= a[0])ans = min(ans, get2(a, n) + 1);
    if(ans == INT_MAX)ans = -1;
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}