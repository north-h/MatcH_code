/*************************************************************
 *  > File Name        : d.cpp
 *  > Author           : omemi
 *  > Created Time     : 2024/4/7 19:36:04
 *************************************************************/

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define endl (char)10

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, p;
    cin >> n >> p;
    set<int> st;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        st.emplace(x % p);
    }

    vector<int> vis(p, INT_MAX / 2);
    for (const int &i : st) {
        vis[i] = 1;
    }
    for (int t = 0; t < 1e8 / p / st.size(); t++) {
        for (int i = 1; i < p; i++) {
            if (vis[i] != -1) {
                for (const int &j : st) {
                    vis[(i + j) % p] = min(vis[(i + j) % p], vis[i] + 1);
                }
            }
        }
    }
    cout << vis[0] << endl;

    return 0;
}