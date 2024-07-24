#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
string a;
string b;
int pr[N];
void solve()
{
    cin >> a >> b;
    if (b[0] == '0' || a[0] == '0') {
        cout << "0\n";
        return ;
    }
    reverse(a.begin(), a.end());
    vector<int>v;
    int p = 0;
    int x = b[0] - '0';
    for (int i = 0; i < a.length(); i++) {
        int now = p + (a[i] - '0') * x;
        v.push_back(now % 10);
        p = now / 10;
    }
    while (p) {
        v.push_back(p % 10);
        p /= 10;
    }
    reverse(v.begin(), v.end());
    // for (auto i : v) cout << i << ' ';
    // cout << '\n';
    for (int i = 1; i <= v.size(); i++) {
        // cout<<v[i-1];
        pr[i] = pr[i - 1] + v[i - 1];
    }
    int n = v.size(), m = b.size();
    vector<int>ans;
    p = 0;

    for (int i = 1; i <= n + m - 1; i++) {
        int r = min(n + m - 1 - i + 1, n);
        int l = max(0ll, n - i);
        int now = p + pr[r] - pr[l];
        // if(i==1)cout<<r<<":"<<l<<" ";
        ans.push_back(now % 10);
        p = now / 10;
    }
    while (p) {
        ans.push_back(p % 10);
        p /= 10;
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans)cout << it;
    cout << "\n";
    return ;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
