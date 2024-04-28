#include <stdio.h>

int n, m;
int state[20];

void dfs(int x) {
    if (x > n) {
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (state[i] == 1) cnt ++;
        }
        if (cnt == m) {
            for (int i = 1; i <= n; i ++) {
                if (state[i] == 1) printf("%d ", i);
            }
            puts("");
        }
        return ;
    }

    state[x] = 1;
    dfs(x + 1);
    state[x] = 0;

    dfs(x + 1);
}
int main() {
    scanf ("%d %d", &n, &m);
    dfs(1);
    return 0;
}