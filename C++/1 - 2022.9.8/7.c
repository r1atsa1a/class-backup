#include <stdio.h>
int n, k;
int matrix[110][110];
void reverse() {
    for (int i = 0; i < n; i ++) {
        for (int j = 0 ; j < n; j ++) {
            if (j > i) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}
int main() {
    // 1 2
    // 3 4
    n = 2; k = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            matrix[i][j] = k ++;
        }
    }
    reverse();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    puts("");
    // 1 2 3
    // 4 5 6
    // 7 8 9
    n = 3; k = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            matrix[i][j] = k ++;
        }
    }
    reverse();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    puts("");
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    // 13 14 15 16
    n = 4; k = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            matrix[i][j] = k ++;
        }
    }
    reverse();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    puts("");
    return 0;
}