// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s; cin >> s;
    set<char> st;
    bool oo = false;
    for (int i = 0; i < s.size(); i ++) {
        bool o3 = false;
        if (i + 9 < s.size()) {
            for (int j = i; j <= i + 9; j ++) {
                if (s[j] != '3') o3 = true;
            }
        } else o3 = true;
        bool o5 = false;
        if (i + 89 < s.size()) {
            for (int j = i; j <= i + 89; j ++) {
                if (s[j] == '5') o5 = true;
            }
        } else o5 = true;
        bool ou = true;
        if (s[i] == '5') {
            if (!oo) oo = true;
            else {
                ou = st.count('U');
                st.clear();
            }
        } else if (oo) {
            st.insert(s[i]);
        }
        if (!o3 || !o5 || !ou) {
            cout << "invalid" << '\n';
            return ;
        }
    }
    cout << "valid" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}