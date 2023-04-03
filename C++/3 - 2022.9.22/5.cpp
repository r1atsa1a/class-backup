// 原题见洛谷 P1760 通天之汉诺塔
// 默认三根圆柱 其中一根圆柱放置着自上而下大小逐步递增的圆盘
#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int hanoi(int n) {
    int dp[N];
    dp[1] = 1;
    for (int i = 2; i <= n; i ++) dp[i] = dp[i - 1] * 2 + 1;
    return dp[n];
}
int main() {
    int n1 = 3;
    printf("当圆柱上的圆盘个数是%d时，至少需%d步才能完成汉诺塔问题要求。\n", n1, hanoi(n1));
    int n2 = 10;
    printf("当圆柱上的圆盘个数是%d时，至少需%d步才能完成汉诺塔问题要求。\n", n2, hanoi(n2));
    int n3 = 15;
    printf("当圆柱上的圆盘个数是%d时，至少需%d步才能完成汉诺塔问题要求。\n", n3, hanoi(n3));
    return 0;
}