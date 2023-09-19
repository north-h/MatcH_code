#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    cout << "? ";
    for (char i = 'a'; i <= 'z'; i++) cout << i;
    cout << endl;
    int n;
    // cin >> n;
    // for (int i = 1, x; i <= n; i++) cin >> x;
    vector<int> a(n + 1);
    for (int i = 0, t; i < 5; i++) {
        cout << "? ";
        for (int j = 0; j < 26; j++) {
            if (j & (1 << i)) {
                // cout << j << ' ';
                cout << (char) ('a' + j);
            }
        }
        cout << endl;
        // cin >> t;
        for (int j = 1, x; j <= t; j++) {
            // cin >> x;
            // a[x] |= (1 << i);
        }
    }
    // cout << "! ";
    // for (int i = 1; i <= n; i++)
    //     cout << (char) ('a' + a[i]);
    cout << endl;
    return 0;
}
