#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int flag4=10, flag5=90, flagu=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='3'){
            flag4--;
            flag5--;
        }
        else if(s[i]=='4'){
            flag4=10;
            flag5--;
        }
        else{
            if(s[i]=='5'){
                if(flagu==0){
                    cout << "invalid" << endl;
                    return;
                }
                else{
                    flagu=0;
                    flag5=90;
                    flag4=10;
                }
            }
            else{
                flagu=1;
                flag5=90;
                flag4=10;
            }
        }
        if(flag5<=0 || flag4<=0){
            cout << "invalid" << endl;
            return;
        }
    }
    cout << "valid" << endl;
    return;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}