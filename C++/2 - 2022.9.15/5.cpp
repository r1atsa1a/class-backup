#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void dectobin(char *bin, int n) {
	int x, i = 0;
	while (n) {
        x = n % 2;
        n = n >> 1;
        *(bin + i) = x + '0';
        i ++;
    }
    *(bin + i) = '\0';
}
void addbin(char *s1, char *s2, int *ans_bin, int &cnt) {
    int k = 0; cnt = 0;
    for (int i = 0; *(s1 + i); i ++) {
        k += *(s1 + i) - '0';
        if (*(s2 + i)) k += s2[i] - '0';
        ans_bin[cnt ++] = k % 2;
        k /= 2;
    }
    if (k) ans_bin[cnt ++] = 1;
}
void bintodec(int *ans_bin, int cnt, int &ans_dec) {
    ans_dec = 0;
    for (int i = 0; i < cnt; i ++) ans_dec += ans_bin[i] * pow(2, i);
}
int main() {
    int a, b, ans_bin[25], cnt, ans_dec;
    char bin_a[25], bin_b[25];
    a = 15, b = 10;
    printf("a = %d, b = %d\n", a, b);
    dectobin(bin_a, a); dectobin(bin_b, b);
    printf("a(B) = "); for (int i = strlen(bin_a) - 1; i >= 0; i --) cout << bin_a[i]; printf(", ");
    printf("b(B) = "); for (int i = strlen(bin_b) - 1; i >= 0; i --) cout << bin_b[i]; printf("\n");
    addbin(bin_a, bin_b, ans_bin, cnt);
    printf("a(B) + b(B) = ");
    for (int i = cnt - 1; i >= 0; i --) cout << ans_bin[i];
    bintodec(ans_bin, cnt, ans_dec);
    printf("(B), %d(D)\n", ans_dec);
    a = 18, b = 8;
    printf("a = %d, b = %d\n", a, b);
    dectobin(bin_a, a); dectobin(bin_b, b);
    printf("a(B) = "); for (int i = strlen(bin_a) - 1; i >= 0; i --) cout << bin_a[i]; printf(", ");
    printf("b(B) = "); for (int i = strlen(bin_b) - 1; i >= 0; i --) cout << bin_b[i]; printf("\n");
    addbin(bin_a, bin_b, ans_bin, cnt);
    printf("a(B) + b(B) = ");
    for (int i = cnt - 1; i >= 0; i --) cout << ans_bin[i];
    bintodec(ans_bin, cnt, ans_dec);
    printf("(B), %d(D)\n", ans_dec);
    a = 118, b = 25;
    printf("a = %d, b = %d\n", a, b);
    dectobin(bin_a, a); dectobin(bin_b, b);
    printf("a(B) = "); for (int i = strlen(bin_a) - 1; i >= 0; i --) cout << bin_a[i]; printf(", ");
    printf("b(B) = "); for (int i = strlen(bin_b) - 1; i >= 0; i --) cout << bin_b[i]; printf("\n");
    addbin(bin_a, bin_b, ans_bin, cnt);
    printf("a(B) + b(B) = ");
    for (int i = cnt - 1; i >= 0; i --) cout << ans_bin[i];
    bintodec(ans_bin, cnt, ans_dec);
    printf("(B), %d(D)\n", ans_dec);
    return 0;
}