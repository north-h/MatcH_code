//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;
mt19937_64 rnd(time(0));

const int N = 1e6 + 10, M = 210;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
ll n;
ll a[N];
void solve() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        // for (int j = 4; j >= 0; j --) {
        //     cout << (a[i] >> j & 1);
        // }
        // cout << '\n';
    }
    // cout << sum << '\n';
    // cout << '\n';
    int x;
    if (sum % n == 0) x = sum / n;
    else x = ((sum / n) | (sum / n + 1));
    // cout << '\n';
    int ans = INF;
    int avg = sum / n;
    // if (sum % n == 0) {
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 4; j >= 0; j --) {
    //             cout << (avg >> j & 1);
    //         }
    //         cout << '\n';
    //     }
    // } else {
    //     for (int i = 1; i <= n - sum % n; i++) {
    //         for (int j = 4; j >= 0; j --) {
    //             cout << ((avg) >> j & 1);
    //         }
    //         cout << '\n';
    //     }
    //     for (int i = 1; i <= sum % n; i++) {
    //         for (int j = 4; j >= 0; j --) {
    //             cout << ((avg + 1) >> j & 1);
    //         }
    //         cout << '\n';
    //     }
    // }
    // cout << '\n';
    vector<int> ve;
    int tans = INF;
    // cout << sum << '\n';
    for (int i1 = 0; i1 <= 20; i1++) {
        for (int i2 = 0; i2 <= 20; i2++) {
            if (i1 + i2 > sum) break;
            for (int i3 = 0; i3 <= 20; i3++) {
                if (i1 + i2 + i3 > sum) break;
                for (int i4 = 0; i4 <= 20; i4++) {
                    if (i1 + i2 + i3 + i4 > sum) break;
                    for (int i5 = 0; i5 <= 20; i5++) {
                        if (i1 + i2 + i3 + i4 + i5 > sum) break;
                        for (int i6 = 0; i6 <= 20; i6 ++) {
                            if (i1 + i2 + i3 + i4 + i5 + i6 > sum) break;
                            if (i1 + i2 + i3 + i4 + i5 + i6 == sum) {
                                tans = i1 | i2 | i3 | i4 | i5 | i6;
                                if (ans > tans) {
                                    // cout << i1 << ' '<< i2 << ' ' << i3 << ' ' << i4 << ' ' << i5 << ' ' << i6 << '\n';
                                    ve.clear();
                                    ve.push_back(i1);
                                    ve.push_back(i2);
                                    ve.push_back(i3);
                                    ve.push_back(i4);
                                    ve.push_back(i5);
                                    ve.push_back(i6);
                                    ans = tans;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (auto i : ve) {
        // for (int j = 4; j >= 0; j --) {
        //     cout << (i >> j & 1);
        //     cout <<
        // }
        // cout << '\n';
        // cout << i << ' ';
    }
    // cout << '\n';
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int O_o = 1;
//  cin >> O_o;
    while (O_o--) solve();
    return 0;
}
//make it count
//开ll plz