#include<bits/stdc++.h>

using namespace std;
string s;
int lm;
string ans;

signed main() {
    getline(cin,s);
    string la ="ABC";
    for (int i = 0; i <s.length(); i++) {
        if(s[i] == ' ')continue;
        if(s[i] == '(') {
            i++;
            while (s[i] != ')' && i < s.length()) {
                if(s[i] == ' ') {
                    i++;   
                    continue;
                }
                la += s[i];
                i++;
            }
        }
        else if(s[i] == '{') {
            int j = i-1;
            i++;
            while(s[i] == ' ')i++;
            if('0' <= s[i] && s[i] <= '9'){
            while (s[i] != '}' && i < s.length()) {
                if(s[i] == '}')break;
                if(s[i] == ' ') {
                    i++;
                    continue;
                }
                lm = lm*10+(s[i]-'0');
                i++;
            }}
  //          cout << "LM" << lm << endl;
            while (s[j] == ' ')j--;
            if(s[j] == ')') {
                string ab[50];
                int ai = 0;
                for (int ii = 3; ii < la.length(); ii++) {
                    if('A' <= la[ii] && la[ii] <= 'Z') ai++;
                    ab[ai] += la[ii];
                }
                for (int ii = 0; ii <= ai; ii++) {
                    for (int jj = 1; jj <= lm; jj++) {
                        ans+=ab[ii];
                    }
                }
                la = "ZDS";
            }
            else {
                bool fl = true;
                string lp;
                while (fl && j >= 0) {
                    if(s[j] == ' ') {
                        j--;
                        continue;
                    }
                    lp = s[j]+lp;
                    if('A' <= s[j] && s[j] <='Z')fl = false;
                    j--;
                }
                for (int i = 1; i <= lm-1; i++) {ans+=lp;
                }
                if(lm == 0) {
                    string res;
                    for (int i = 0; i < ans.length()-lp.length(); i++) {
                        res += ans[i];
                    }
                    ans = res;
                }
 //               cout << "LP" << lp << endl;
            }
        }
        else ans+=s[i];
        lm = 0;
    }
    cout << ans << endl;
    return 0;
}