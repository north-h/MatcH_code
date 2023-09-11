/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-10 21:22:37
 *
 * Problem: P1115 最大子段和
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1115
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int ans = -2e9;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        // printf("%d-%d\n", sum, ans);
        if(ans < sum)ans = sum;
        // printf("%d-%d\n", sum, ans);
        if(sum < 0) {
            sum = 0;
        }
    }
    if(ans < sum && sum != 0)ans = sum;
    printf("%d", ans);
    return 0;
}