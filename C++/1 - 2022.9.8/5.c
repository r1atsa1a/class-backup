#include <stdio.h>
#include <string.h>
int n;
char arr[1010][15];
void reverse() {
    int len;
    for (int i = 0; i < n; i ++) {
        len = strlen(arr[i]);
        for (int j = len - 1; j >= 0; j --) printf("%c", arr[i][j]);
        putchar(' ');
    }
    puts("");
}
int main() {
    // 1.65
    n = 1; strcpy(arr[0], "1.65");
    reverse();
    // 2.55 10.8
    n = 2; strcpy(arr[0], "2.55"); strcpy(arr[1], "10.8");
    reverse();
    // 8.45 0.65 0.035
    n = 3; strcpy(arr[0], "8.45"); strcpy(arr[1], "0.65"); strcpy(arr[2], "0.035");
    reverse();
    return 0;
}