#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5 + 7;

string s[N];
int pre[90][9];
int suf[90][9];
int add[N];
int t[10][N];

int get(string ss){
    int res = 0;
    for (auto x : ss) {
            res += x - '0';
        }
    return res;
}

bool cmp(string a,string b){
    return get(a) > get(b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin >> n;

    for (int i = 1;i <= n;i++){
        cin >> s[i];
    }  
    sort(s + 1,s + 1 + n,cmp);
    for (int i = 1;i <= n;i++){
        t[s[i].size()][get(s[i])]++;
        add[i] = get(s[i]);
    }
    ll res = 0;

    for (int i = 1;i <= n;i++){
        for (int len = s[i].size() + 1;len <= 18;len++){
            if (len % 2) continue;
            if (len - s[i].size() > 9) continue;
            int cur = 0;
            for (int j = 0;j < s[i].size();j++){
                
                cur += s[i][j] - '0';
                int lst = add[i] - cur;
                if (cur - lst <= 0) continue;
                res += t[len - s[i].size()][cur - lst];

            }
        }
        for (int len = s[i].size() + 1;len <= 18;len++){
            if (len % 2) continue;
            if (len - s[i].size() > 9) continue;
            int cur = 0;
            for (int j = s[i].size() - 1;j >= 0;j—){
                cur += s[i][j] - '0';
                int lst = add[i] - cur;
                if (cur - lst <= 0) continue;
                res += t[len - s[i].size()][cur - lst];
            }
        }
        res --;
        t[s[i].size()][add[i]] --;
    }

    cout << res << endl;


    return 0;
}
