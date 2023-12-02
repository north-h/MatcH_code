/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-01 16:51:06
 *
 * Problem: C. Smilo and Monsters
 * Contest: Codeforces - Codeforces Round 907 (Div. 2)
 * URL:     https://codeforces.com/problemset/problem/1891/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

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
const int N = 10010;
const int M = 110;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0, cnt = 0;
    for(auto &i : a) {
        cin >> i;
        ans += i;
    }
    ans /= 2;
    // debug1(ans);
    sort(a.begin(), a.end());
    for(int i = n - 1; i >= 0; i--) {
        if(ans != 0)cnt++;
        if(ans >= a[i]) {
            ans -= a[i];
            a[i] = 0;
        } else {
            a[i] -= ans;
            break;
        }
    }
    // debug1(cnt);
    for(auto i : a)cnt += i;
    cout << cnt << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}