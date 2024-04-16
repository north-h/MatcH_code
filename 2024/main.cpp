#include <stdio.h>
char op[4] = {'+', '-', '*', '/'};
float result(float x, float y, char op) {
    if (op == '+')
        return x + y;
    if (op == '-')
        return x - y;
    if (op == '*')
        return x * y;
    if (op == '/')
        return x / y;
}
float model1(float a, float b, float c, float d, char op1, char op2, char op3) {
    float x, y, z;
    x = result(a, b, op1);
    y = result(x, c, op2);
    z = result(y, d, op3);
    return z;

}
float model2(float a, float b, float c, float d, char op1, char op2, char op3) {
    float x, y, z;
    x = result(b, c, op2);
    y = result(a, x, op1);
    z = result(y, d, op3);
    return z;

}
float model3(float a, float b, float c, float d, char op1, char op2, char op3) {
    float x, y, z;
    x = result(c, d, op3);
    y = result(b, x, op2);
    z = result(a, y, op1);
    return z;


}
float model4(float a, float b, float c, float d, char op1, char op2, char op3) {
    float x, y, z;
    x = result(b, c, op2);
    y = result(x, d, op3);
    z = result(a, y, op1);
    return z;

}
float model5(float a, float b, float c, float d, char op1, char op2, char op3) {
    float x, y, z;
    x = result(a, b, op1);
    y = result(c, d, op3);
    z = result(x, y, op2);
    return z;
}
int cal(int a, int b, int c, int d) {
    int i, j, k;
    int flag = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                char op1 = op[i], op2 = op[j], op3 = op[k];
                if (model1(a, b, c, d, op1, op2, op3) == 24) {
                    printf("((%d%c%d)%c%d)%c%d", a, op1, b, op2, c, op3, d);
                    flag = 1;
                    break;
                }
                if (model2(a, b, c, d, op1, op2, op3) == 24) {
                    printf("(%d%c(%d%c%d))%c%d", a, op1, b, op2, c, op3, d);
                    flag = 1;
                    break;
                }
                if (model3(a, b, c, d, op1, op2, op3) == 24) {
                    printf("%d%c(%d%c(%d%c%d))", a, op1, b, op2, c, op3, d);
                    flag = 1;
                    break;
                }
                if (model4(a, b, c, d, op1, op2, op3) == 24) {
                    printf("%d%c((%d%c%d)%c%d)", a, op1, b, op2, c, op3, d);
                    flag = 1;
                    break;
                }
                if (model5(a, b, c, d, op1, op2, op3) == 24) {
                    printf("(%d%c%d)%c(%d%c%d)", a, op1, b, op2, c, op3, d);
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    if (flag)
        return 1;
    return 0;
}
int main() {
    int x[4];
    scanf("%d %d %d %d", &x[0], &x[1], &x[2], &x[3]);
    int i, j, k, t;
    int a, b, c, d;
    int flag = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == i)continue;
            for (k = 0; k < 4; k++) {
                if (k == i || k == j)continue;
                for (t = 0; t < 4; t++) {
                    if (t == i || t == j || t == k)continue;
                    int a = x[i];
                    int b = x[j];
                    int c = x[k];
                    int d = x[t];
                    flag = cal(a, b, c, d);
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    if (!flag)
        printf("-1");
    return 0;
}