// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    // getline(cin, s);
    while (cin >> s) {
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == ' ') continue;
            map<char, int> mp;
            string str1, str2;
            int type = 0;
            int cnt = 0;
            if (s[i] >= 'A' && s[i] <= 'Z') {
                str1 += s[i];
                int j = i + 1;
                while (j < s.size() && s[j] >= 'a' && s[j] <= 'z') {
                    str1 += s[j];
                    j ++;
                }
                i = j - 1;
                int cnt = 0;
                if (i + 1 < s.size() && s[i + 1] == '{') {
                    j = i + 2;
                    while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
                        cnt = cnt * 10 + (s[j ++] - '0');
                    }
                    i = j;
                }
                for (int k = 1; k <= max(1ll, cnt); k ++) {
                    cout << str1;
                }
                str1.clear();
            } else if (s[i] == '(') {
                int j = i + 1;
                vector<string> st;
                string str = "";
                while (j < s.size() && s[j] != ')') {
                    if (s[j] >= 'A' && s[j] <= 'Z') {
                        str += s[j];
                        j ++;
                        while (j < s.size() && s[j] >= 'a' && s[j] <= 'z') {
                            str += s[j];
                            j ++;
                        }
                        st.push_back(str);
                        str.clear();
                    }
                }
                i = j;
                int cnt = 0;
                if (i + 1 < s.size() && s[i + 1] == '{') {
                    j = i + 2;
                    while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
                        cnt = cnt * 10 + (s[j ++] - '0');
                    }
                    i = j;
                }
                for (auto str : st) {
                    for (int k = 1; k <= max(0ll, cnt); k ++) {
                        cout << str;
                    }
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}