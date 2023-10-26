#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<double, string>> a;
    for(int i = 1; i <= n; i++) {
        string s;
        double x;
        // getline(cin, s);
        cin >> s;
        // cout << s << endl;
        cin >> x;
        cout << x << endl;
        a.push_back({x, s});
    }
    // for(auto [x, y] : a)cout << x << ' ' << y << endl;
    // sort(a.begin(), a.end());
    // cout << a[n - 1].first << ' ' << a[n - 1].second << endl;
    // cout << a[0].first << ' ' << a[0].second << endl;
    return 0;
}