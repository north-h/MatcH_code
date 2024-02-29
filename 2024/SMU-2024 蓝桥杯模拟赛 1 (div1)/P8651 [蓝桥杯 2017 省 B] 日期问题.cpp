// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

bool judge(int x){
    if(x % 400 == 0 || x % 100 != 0 && x % 4 == 0)
        return true;
    else return false;
}

string get(string s){
    int y1, y2, m, d;
    y1 = 1900 + (s[0] - '0') * 10 + (s[1] - '0');
    y2 = 2000 + (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    d = (s[6] - '0') * 10 + (s[7] - '0');
    // debug2(y1, y2);
    // debug2(m, d);
    if(m >= 1 && m <= 12){
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
            if(d >= 1 && d <= 31){
                if(y1 >= 1960 && y1 <= 2059){
                    string yy, mm, dd;
                    yy = to_string(y1);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
                if(y2 >= 1960 && y2 <= 2059){
                    string yy, mm, dd;
                    yy = to_string(y2);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
            }
        }else if(m == 2){
            if(y1 >= 1960 && y1 <= 2059){
                if(judge(y1) && d >= 1 && d <= 29){
                    string yy, mm, dd;
                    yy = to_string(y1);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
                if(!judge(y1) && d >= 1 && d <= 28){
                    string yy, mm, dd;
                    yy = to_string(y1);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
            }
            if(y2 >= 1960 && y2 <= 2059){
                if(judge(y2) && d >= 1 && d <= 29){
                    string yy, mm, dd;
                    yy = to_string(y2);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
                if(!judge(y2) && d >= 1 && d <= 28){
                    string yy, mm, dd;
                    yy = to_string(y2);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
            }
        }else {
            if(d >= 1&& d <= 30){
                if(y1 >= 1960 && y1 <= 2059){
                    string yy, mm, dd;
                    yy = to_string(y1);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
                if(y2 >= 1960 && y2 <= 2059){
                    string yy, mm, dd;
                    yy = to_string(y2);
                    mm = to_string(m);
                    dd = to_string(d);
                    if(mm.size() == 1) mm = '0' + mm;
                    if(dd.size() == 1) dd = '0' + dd;
                    return yy + '-' + mm + '-' + dd;
                }
            }
        }
    }
    return "NO";
}

void solve() {
    string s;
    cin >> s;
    string sans = get(s);
    // debug1(s);
    set<string> ans;
    if(sans != "NO") {
        ans.insert(sans);
    }
    swap(s[0], s[6]);
    swap(s[1], s[7]);
    sans = get(s);
    if(sans != "NO") {
        ans.insert(sans);
    }
    swap(s[6], s[3]);
    swap(s[7], s[4]);
    // debug1(s);
    sans = get(s);
    if(sans != "NO") {
        ans.insert(sans);
    }
    for(auto i : ans)cout << i << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}