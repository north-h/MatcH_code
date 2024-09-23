#include <iostream>
#include <sstream>
#include <Windows.h>
#include <ctime>
#include <map>
#include <string>
using namespace std;

#define MAX_NUM 500000

int main()
{
    time_t tBegin, tEnd;//时间戳，计算代码段执行时间

    //键值为int类型的map
    map<int, int> mapInt;
    for (int i = 0; i < MAX_NUM; i++)
    {
        mapInt.insert(make_pair(i, i));
        //或mapInt[i] = i; 区别为遇到重复键时，insert不会覆盖值，[]会覆盖值
    }

    map<int, int>::iterator iterInt;
    tBegin = clock();
    for (int i = 0; i < MAX_NUM; i++)
    {
        iterInt = mapInt.find((MAX_NUM / 2));
    }
    tEnd = clock();
    cout << "int-find  耗时" << (tEnd - tBegin) << "毫秒" << endl;

    int nRtn = 0;
    tBegin = clock();
    for (int i = 0; i < MAX_NUM; i++)
    {
        nRtn = mapInt.count((MAX_NUM / 2));
    }
    tEnd = clock();
    cout << "int-count 耗时" << (tEnd - tBegin) << "毫秒" << endl << endl;

    //键值为string类型的map
    map<string, string> mapString;
    for (int i = 0; i < MAX_NUM; i++)
    {
        stringstream ss;
        ss << i;
        string str = ss.str();
        str = "string" + str;
        mapString[str] = str;//或mapString.insert(make_pair(str, str));
    }

    map<string, string>::iterator iterStr;
    tBegin = clock();
    for (int i = 0; i < MAX_NUM; i++)
    {
        iterStr = mapString.find("string250000");
    }
    tEnd = clock();
    cout << "string-find  耗时" << (tEnd - tBegin) << "毫秒" << endl;

    tBegin = clock();
    for (int i = 0; i < MAX_NUM; i++)
    {
        nRtn = mapString.count("string250000");
    }
    tEnd = clock();
    cout << "string-count 耗时" << (tEnd - tBegin) << "毫秒" << endl;

    getchar();
    return 0;
}
