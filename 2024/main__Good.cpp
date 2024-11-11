/*
    Problem: 2024 CCPC Liaoning Provincial Contest/M
    Author: Core_65536
    Last_Update: 2024-11-5
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const pair<int, int> loc[11] = {  // 每一号宫格的坐标
    {0, 0},  {2, 2}, {1, 1}, {1, 2},
    {1, 3}, {2, 1}, {2, 3},
    {3, 1}, {3, 2}, {3, 3}
};

map<pair<int, int>, int> col = { // 每个坐标的宫格号
    {{2, 2}, 1},  {{1, 1}, 2},  {{1, 2}, 3},
    {{1, 3}, 4},  {{2, 1}, 5},  {{2, 3}, 6},
    {{3, 1}, 7},  {{3, 2}, 8},  {{3, 3}, 9}
};

const vector<vector<pair<int , int>>> dir = { // 已经排好序的8种情况的比较坐标
    {{1, 1}, {2, 2}, {3, 3}}, //1 2 9
    {{1, 2}, {2, 2}, {3, 2}}, //1 3 8
    {{1, 3}, {2, 2}, {3, 1}}, //1 4 7
    {{2, 1}, {2, 2}, {2, 3}}, //1 5 6
    {{1, 1}, {1, 2}, {1, 3}}, //2 3 4
    {{1, 1}, {2, 1}, {3, 1}}, //2 5 7
    {{1, 3}, {2, 3}, {3, 3}}, //4 6 9
    {{3, 1}, {3, 2}, {3, 3}} //7 8 9
};


void solve() {
    // t:luck
    int n, m, k, t;    cin >> n >> m >> k >> t;
    int id = 0, cc = n;
    queue<int> a;       // 沸羊羊的盲盒队列
    queue<int>  got;    // 美羊羊获得的盲盒队列
    int chess[4][4];    memset(chess, -1, sizeof(chess)); // 棋盘
    map<int, int>  ans; // 每个盲盒获得的数量
    int res = 0;        // 缺少的盲盒数量

    for (int i = 1; i <= k; i++) { // 输入沸羊羊的盲盒队列
        int x;  cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) { // 初始化美羊羊的盲盒队列
        got.push(a.front());
        a.pop();
    }
    while (1) { //游戏循环
        cout << "id=" << id << ' ' << "cc=" << cc << '\n';
        cout << got.size() << '\n';
        cout << "-----------------------" << '\n';
        //Step 1 放置盲盒
        int ok = 0, DidSth = 0; // ok:是否拆出隐藏款 DidSth:是否有操作
        for (int i = 1; i <= 9 && (!got.empty()); i++) { // 遍历每一个宫格
            if (chess[loc[i].first][loc[i].second] != -1) { // 如果宫格已经有盲盒则跳过
                continue;
            }
            DidSth = 1; // 有操作
            int x = got.front();    got.pop();  // 美羊羊取出一个盲盒
            chess[loc[i].first][loc[i].second] = x; // 放入宫格
            id ++;
            if (x == t) { // 如果是幸运款
                if (!a.empty()) { // 如果沸羊羊还有盲盒
                    got.push(a.front());    // 奖励一个盲盒
                    a.pop();
                    cc ++;
                } else { // 沸羊羊没有盲盒
                    res ++; // 缺少的盲盒数量+1
                    cc ++;
                }
            } else if (x == 0) { // 如果是隐藏款
                if (!a.empty()) {
                    got.push(a.front());
                    a.pop();
                    cc ++;
                } else {
                    res ++;
                    cc ++;
                }
                ans[x] ++ ; // 更新答案
                chess[loc[i].first][loc[i].second] = -1;
                ok = 1;
                break;
            }
        }
        if (ok) { // 如果拆出隐藏款则跳过后面的步骤
            continue;
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                cout << chess[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        //Step 2 判断是否9个盲盒均不同
        unordered_map<int , int> count;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (chess[i][j] != -1)  // 排除空格
                    count[chess[i][j]] ++ ;
        if (count.size() == 9) { // 9个盲盒均不同
            DidSth = 1;
            ans[chess[loc[1].first][loc[1].second]] ++; // 更新答案
            chess[loc[1].first][loc[1].second] = -1;
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                cout << chess[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        //Step 3 按顺序检查8种三连珠情况
        int UseSpeFlag = 0; // 是否利用到特殊格
        vector<vector<int>> process;  // 存储有几种三连珠情况 & 每一种情况的三个盲盒的宫格号
        for (int i = 0; i < 8; i++) {
            int x1[3], y1[3];
            for (int j = 0; j < 3; j++) { // 存入当前需要比较的坐标
                x1[j] = dir[i][j].first;
                y1[j] = dir[i][j].second;
            }
            // 比较三个盲盒是否相同 & 排除空格
            if (chess[x1[0]][y1[0]] == chess[x1[1]][y1[1]] && chess[x1[1]][y1[1]] == chess[x1[2]][y1[2]] && chess[x1[0]][y1[0]] != -1) {
                DidSth = 1;
                vector<int> cnt;
                for (int j = 0; j < 3; j++) {
                    cnt.push_back(col[ {x1[j], y1[j]}]); // 存入宫格号
                }
                process.push_back(cnt); // 存入当前三连珠情况
            }
        }
        //Start Process
        for (auto i : process) { // 遍历每一种三连珠情况
            int x1[3], y1[3];
            for (int j = 0; j < 3; j++) { // 存入当前需要处理的坐标
                x1[j] = loc[i[j]].first;
                y1[j] = loc[i[j]].second;
            }
            // 排除已经处理过变成空格的宫格
            if (chess[x1[0]][y1[0]] != -1 && chess[x1[1]][y1[1]] != -1 && chess[x1[2]][y1[2]] != -1) {
                for (int j = 0; j < 5; j++) { // 发放奖励盲盒
                    if (!a.empty()) {
                        got.push(a.front());
                        a.pop();
                        cc ++;
                    } else {
                        cc ++;
                        res ++;
                    }
                }
                for (int j = 0; j < 3; j++) { // 遍历三连珠的三个盲盒
                    if (i[j] == 1) {  // 如果是特殊格
                        UseSpeFlag = 1;
                        continue;
                    } else { // 不是特殊格
                        ans[chess[x1[j]][y1[j]]] ++;    // 更新答案
                        chess[x1[j]][y1[j]] = -1;
                    }
                }
            }
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                cout << chess[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        //Step 4 顺序检查任意两种盲盒是否相同
        for (int i = 1; i <= 9; i++) {
            for (int j = i; j <= 9; j++) {
                if (j <= i)  continue;  // 遍历宫格号以做到顺序遍历
                int x1 = loc[i].first, y1 = loc[i].second;
                int x2 = loc[j].first, y2 = loc[j].second;
                // 如果两个盲盒相同 & 不是空格
                if (chess[x1][y1] == chess[x2][y2] && chess[x1][y1] != -1) {
                    DidSth = 1;
                    if (i == 1) { // 如果第一个利用到特殊格
                        UseSpeFlag = 1;
                        if (!a.empty()) {
                            got.push(a.front());
                            a.pop();
                            cc ++;
                        } else {
                            res ++;
                            cc ++;
                        }
                        ans[chess[x2][y2]] ++;  // 更新答案
                        chess[x2][y2] = -1;
                        continue;
                    }
                    if (j == 1) { // 如果第二个利用到特殊格
                        UseSpeFlag = 1;
                        if (!a.empty()) {
                            got.push(a.front());
                            a.pop();
                            cc ++;
                        } else {
                            res ++;
                            cc ++;
                        }
                        ans[chess[x1][y1]] ++; // 更新答案
                        chess[x1][y1] = -1;
                        continue;
                    }
                    // 如果没利用到特殊格
                    if (!a.empty()) {
                        got.push(a.front());
                        a.pop();
                        cc ++;
                    } else {
                        res ++;
                        cc ++;
                    }
                    ans[chess[x1][y1]] += 2;    // 更新答案
                    chess[x1][y1] = chess[x2][y2] = -1;
                }
            }
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                cout << chess[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        //Step 5 判断是否利用到特殊格
        if (UseSpeFlag == 1) {
            DidSth = 1;
            ans[chess[2][2]] ++;    // 更新答案
            chess[2][2] = -1;
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                cout << chess[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        //Step 6 如果没有操作游戏结束
        if (!DidSth) {
            break;
        }
        int Judge0Flag = 0; // 判断是否清台
        for (int i = 1 ; i <= 9 ; i++) {
            if (chess[loc[i].first][loc[i].second] == -1)
                Judge0Flag ++;
        }
        if (Judge0Flag == 9) {  // 如果清台
            for (int i = 0; i < 10; i++) { // 发放奖励盲盒
                if (!a.empty()) {
                    got.push(a.front());
                    a.pop();
                    cc ++;
                } else {
                    res ++;
                    cc ++;
                }
            }
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                cout << chess[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        for (int i = 0; i <= m; i ++) { // 输出每一种盲盒获得的数量
            cout << ans[i] << " ";
        }
        cout << '\n';

    }
    // 游戏结束, 清理棋盘
    for (int i = 1; i <= 9; i++) {
        if (chess[loc[i].first][loc[i].second] != -1) {
            ans[chess[loc[i].first][loc[i].second]] ++;
            chess[loc[i].first][loc[i].second] = -1;
        }
    }
    for (int i = 0; i <= m; i ++) { // 输出每一种盲盒获得的数量
        cout << ans[i] << " ";
    }
    if (res != 0) { // 输出缺少的盲盒数量
        // cout<<"Unhappy! "<<res<<endl;
    }
    return ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;  // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
