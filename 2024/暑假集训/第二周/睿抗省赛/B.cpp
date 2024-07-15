#include<bits/stdc++.h>

#define int long long

using namespace std;
    vector<int> sore(21);

void solve() {
    map<int, int> mp;
    for (int i = 1; i <= 20; i ++) {
        if (i == 1) mp[i] = 12;
        else if (i == 2) mp[i] = 9;
        else if (i == 3) mp[i] = 7;
        else if (i == 4) mp[i] = 5;
        else if (i == 5) mp[i] = 4;
        else if (i >= 6 && i <= 7) mp[i] = 3;
        else if (i >= 8 && i <= 10) mp[i] = 2;
        else if (i >= 11 && i <= 15) mp[i] = 1;
        else if (i == 4) mp[i] = 0;
    }
    for (int i = 1; i <= 20; i ++) {
        int p, k; cin >> p >> k;
        sore[i] +=  mp[p] + k;
    }
}

int32_t main() {
    // ios:snyc_stdio_sith(false);
    // cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
    for (int i = 1; i<= 20; i ++) {
        cout << i << ' ' << sore[i] << '\n';
    }
    return 0;
}

